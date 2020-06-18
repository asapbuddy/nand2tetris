#pragma once

#include "../API/Factory.h"
#include "../HackPlatform/Assembler.h"
#include "../HackPlatform/Decoder.h"
#include "../HackPlatform/ProcessingParameters.h"
#include "../HackPlatform/SymbolTable.h"


struct HackFactory final : Factory
{
    std::unique_ptr<Assembler> CreateAssembler() override
    {
        return std::make_unique<TwoPassAssembler>(CreateParameters());
    }

    std::unique_ptr<StatementParameters> CreateParameters() override
    {
        return std::make_unique<ProcessingParameters>(
            std::make_unique<SymbolTable>(),
            std::make_unique<Decoder>()
        );
    }

    ~HackFactory() override = default;
};
