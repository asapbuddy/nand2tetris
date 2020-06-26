#pragma once

#include "../API/Factory.h"
#include "../HackPlatform/Assembler.h"
#include "../HackPlatform/Encoder.h"
#include "../HackPlatform/StatementContext.h"
#include "../HackPlatform/SymbolTable.h"


struct HackFactory final : Factory
{
    std::unique_ptr<Assembler> CreateAssembler() override
    {
        return std::make_unique<TwoPassAssembler>(CreateContext());
    }

    std::unique_ptr<Context> CreateContext() override
    {
        return std::make_unique<StatementContext>(
            std::make_unique<SymbolTable>(),
            std::make_unique<Encoder>()
        );
    }

    ~HackFactory() override = default;
};
