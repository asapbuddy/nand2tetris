#pragma once
#include <bitset>
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <xstring>


#include "Command.h"
#include "misc/Helper.h"
using namespace std;
using namespace std::filesystem;

#include "errors/ParserError.h"

class parser
{
    vector<string> raw_source_;
    vector<command> source_;
    unordered_map<string, pair<int, bool>> a_table_;
    unordered_map<string, pair<int, bool>> l_table_;


    unordered_map<string, string> comp_table_;
    unordered_map<string, string> dest_table{
        {"M", "001"},
        {"D", "010"},
        {"MD", "011"},
        {"A", "100"},
        {"AM", "101"},
        {"AD", "110"},
        {"AMD", "111"},
    };

    unordered_map<string, string> jmp_table{
        {"JGT", "001"},
        {"JEQ", "010"},
        {"JGE", "011"},
        {"JLT", "100"},
        {"JNE", "101"},
        {"JLE", "110"},
        {"JMP", "111"},
    };


    void init_sym_table()
    {
        a_table_["SP"] = {0, false};
        a_table_["LCL"] = {1, false};
        a_table_["ARG"] = {2, false};
        a_table_["THIS"] = {3, false};
        a_table_["THAT"] = {4, false};
        a_table_["SCREEN"] = {16384, false};
        a_table_["KBD"] = {24576, false};

        a_table_["R0"] = {0, false};
        a_table_["R1"] = {1, false};
        a_table_["R2"] = {2, false};
        a_table_["R3"] = {3, false};
        a_table_["R4"] = {4, false};
        a_table_["R5"] = {5, false};
        a_table_["R6"] = {6, false};
        a_table_["R7"] = {7, false};
        a_table_["R8"] = {8, false};
        a_table_["R9"] = {9, false};
        a_table_["R10"] = {10, false};
        a_table_["R11"] = {11, false};
        a_table_["R12"] = {12, false};
        a_table_["R13"] = {13, false};
        a_table_["R14"] = {14, false};
        a_table_["R15"] = {15, false};
    }

    void init_comp_table()
    {
        comp_table_["0"] = "101010";
        comp_table_["1"] = "111111";
        comp_table_["-1"] = "111010";
        comp_table_["D"] = "001100";
        comp_table_["A"] = "110000";
        comp_table_["!D"] = "001101";
        comp_table_["!A"] = "110001";
        comp_table_["-D"] = "001111";
        comp_table_["-A"] = "110011";
        comp_table_["D+1"] = "011111";
        comp_table_["A+1"] = "110111";
        comp_table_["D-1"] = "001110";
        comp_table_["A-1"] = "110010";
        comp_table_["D+A"] = "000010";
        comp_table_["D-A"] = "010011";
        comp_table_["A-D"] = "000111";
        comp_table_["D&A"] = "000000";
        comp_table_["D|A"] = "010101";
        // when a =1
        comp_table_["M"] = "110000";
        comp_table_["!M"] = "110001";
        comp_table_["-M"] = "110011";
        comp_table_["M+1"] = "110111";
        comp_table_["M-1"] = "110010";
        comp_table_["D+M"] = "000010";
        comp_table_["D-M"] = "010011";
        comp_table_["M-D"] = "000111";
        comp_table_["D&M"] = "000000";
        comp_table_["D|M"] = "010101";
    }

public:

    parser()
    {
        init_sym_table();
        init_comp_table();
    }

    void load(ifstream&& in)
    {
        const string data((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
        auto splitted = helper::split(data, '\n');
        for(auto& s : splitted)
        {
            if(!helper::is_comment(s) && s != "")
            {
                helper::remove_comment(s);
                helper::trim(s);

                command cmd;
                cmd.raw = s;
                cmd.type = get_command_type(s[0]);
                get_command_mnemonic(cmd);

                source_.emplace_back(cmd);

                //raw_source_.emplace_back(s);
            }
        }
    }

    void process()
    {
        for(auto i = 0; i < source_.size(); ++i)
        {
            if(source_[i].type == COMMAND_TYPE::LABEL)
            {
                l_table_[source_[i].mnemonic].first = i;
                l_table_[source_[i].mnemonic].second = false;
                if(i < source_.size())
                {
                    //while(source_[i + 1].type == COMMAND_TYPE::LABEL && i < source_.size())
                      //  ++i;
                }
            }
        }

        auto test1 = l_table_["RET_ADDRESS_CALL0"];
        auto test2 = l_table_["ball.new"];
        for(auto i = 0, a_cnt = 16; i < source_.size(); ++i)
        {
            auto& current = source_[i];
            int shift = 0;
            if(current.type == COMMAND_TYPE::A_COMMAND)
            {
                int test = 0;
                if(current.mnemonic == "RET_ADDRESS_CALL7")
                {
                    test++;
                }
                if(l_table_.count(current.mnemonic))
                {
                    auto& position = l_table_[current.mnemonic];
                    if(position.second == false)
                    {
                        vector<pair<string, pair<int, bool>>> positions;
                        for(const auto& label : l_table_)
                        {
                            if(label.second.first < position.first)
                            {
                                shift--;
                                positions.push_back(label);
                            }
                        }

                        position.first += shift;
                        position.second = true;
                    }

                    a_table_[current.mnemonic] = {position.first, true};
                }
                else if(is_digit(current.mnemonic[0]))
                {
                    a_table_[current.mnemonic] = {stoi(current.mnemonic), false};
                }
                else if(a_table_.count(current.mnemonic) == 0)
                {
                    a_table_[current.mnemonic] = {a_cnt++, false};
                }
            }
        }
        // redudant labels 
        vector<pair<string, pair<int, bool>>> positions;
        for(auto& label : l_table_)
        {
            if(label.second.second == false)
            {
                positions.push_back(label);
                for(auto& a_cmd : a_table_)
                {
                    if(a_cmd.second.first > label.second.first && a_cmd.second.second == true)
                        a_cmd.second.first--;
                }
            }
        }

        for(unsigned i = 0; i < source_.size(); ++i)
        {
            auto& command = source_[i];
            if(command.type == COMMAND_TYPE::A_COMMAND)
            {
                auto bits = a_table_[command.mnemonic].first;
                command.op_code = "0" + std::bitset<15>(bits).to_string();
            }

            if(command.type == COMMAND_TYPE::C_COMMAND)
                process_c_command(command);
        }

        test1 = test1;
        test2 = test2;
        //for()
        // resolve @
    }

    vector<string> compile()
    {
        vector<string> result;
        for(const auto& s : source_)
        {
            if(s.op_code != "")
                result.push_back(s.op_code);
        }
        return result;
    }

private:
    COMMAND_TYPE get_command_type(char ch)
    {
        switch(ch)
        {
        case '(':
            return COMMAND_TYPE::LABEL;
        case '@':
            return COMMAND_TYPE::A_COMMAND;
        default:
            return COMMAND_TYPE::C_COMMAND;
        }
    }

    void process_c_command(command& cmd)
    {
        cmd.op_code = "111";

        auto dest_split = helper::split(cmd.mnemonic, '=');
        auto dest = dest_split.size() == 1 ? "" : dest_split[0];
        auto comp_part = dest == "" ? dest_split[0] : dest_split[1];

        auto jmp_split = helper::split(dest_split.size() == 1 ? dest_split[0] : dest_split[1], ';');
        auto jmp = jmp_split.size() == 1 ? "" : jmp_split[1];
        auto comp = jmp_split.size() == 1 ? comp_part : jmp_split[0];

        auto a = comp.find("M") == string::npos ? "0" : "1";

        cmd.op_code += a;
        cmd.op_code += comp_table_[comp];
        auto test1 = comp_table_[comp];
        auto test2 = dest_table[dest];
        cmd.op_code += dest == "" ? "000" : dest_table[dest];
        cmd.op_code += jmp == "" ? "000" : jmp_table[jmp];

        if(cmd.op_code.size() != 16)
            throw parser_error("op_code size not equal 16");
    }

    bool is_digit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }

    void get_command_mnemonic(command& cmd)
    {
        switch(cmd.type)
        {
        case COMMAND_TYPE::A_COMMAND:
            cmd.mnemonic = string(cmd.raw.begin() + 1, cmd.raw.end());
            break;
        case COMMAND_TYPE::C_COMMAND:
            cmd.mnemonic = cmd.raw;
            break;
        case COMMAND_TYPE::LABEL:
            cmd.mnemonic = string(cmd.raw.begin() + 1, cmd.raw.end() - 1);
            break;
        default: ;
        }
    }
};
