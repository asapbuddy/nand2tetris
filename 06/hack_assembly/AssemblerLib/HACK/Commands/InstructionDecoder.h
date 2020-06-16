#pragma once
#include <bitset>

/**
 * \brief Translate Hack assembly to binary code.
 * \return aligned bit-values
 */
struct InstructionDecoder
{
    virtual ~InstructionDecoder() = default;

    /**
    * \brief 
    * \return binary code of dest mnemonic
    */
    virtual std::string dest(std::string mnemonic) = 0;
    
    /**
    * \brief 
    * \return binary code of comp mnemonic
    */
    virtual std::string comp(std::string mnemonic) = 0;
    
    /**
    * \brief 
    * \return binary code of jump mnemonic
    */
    virtual std::string jump(std::string mnemonic) = 0;

    /**
     * \brief clients doesn't actually know about processing
     * \return full instruction bits
     */
    virtual std::string instruction() = 0;
};
