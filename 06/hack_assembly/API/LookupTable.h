#pragma once
#include <string>

/**
 * \brief Keeps a correspondence between symbolic labels and numeric
    addresses
 * \ctor creates a new symbol table
 */
struct LookupTable
{
    virtual ~LookupTable() = default;

    /**
     * \brief adds entry to table
     * \param symbol symbolic label
     * \param address in source code
     */
    virtual void AddEntry(std::string symbol, int address) = 0;

    /**
     * \brief check if symbol exists in table
     * \param symbol symbolic label
     * \return true if table contains key and false otherwise
     */
    virtual bool Contains(std::string symbol) = 0;

    /**
     * \brief get address of symbol in source code
     * \param symbol symbolic label
     * \return address in source file where symbol located
     */
    virtual int GetAddress(std::string symbol) = 0;
};
