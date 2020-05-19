#pragma once
#include <bitset>

/**
 * \brief Translate Hack assembly to binary code.
 */
struct ICodeModule
{
    virtual ~ICodeModule() = default;

    /**
    * \brief 
    * \param mnemonic of instruction
    * \return binary code of dest mnemonic
    */
    virtual std::bitset<3> dest(std::string mnemonic) = 0;
    
    /**
    * \brief 
    * \param mnemonic of instruction
    * \return binary code of comp mnemonic
    */
    virtual std::bitset<7> comp(std::string mnemonic) = 0;
    
    /**
    * \brief 
    * \param mnemonic of instruction
    * \return binary code of jump mnemonic
    */
    virtual std::bitset<3> jump(std::string mnemonic) = 0;
};
