#include <string>

enum class COMMAND_TYPE
{
    A_COMMAND,
    C_COMMAND,
    LABEL
};

struct command
{
    std::string raw;
    std::string mnemonic;
    std::string op_code;
    COMMAND_TYPE type;
};
