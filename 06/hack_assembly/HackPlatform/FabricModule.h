#pragma once

#include "Decoder.h"
#include "SymbolTable.h"
#include "../API/Fabric.h"
#include "Statements/ProcessingParameters.h"

class FabricModule final : public Fabric
{
public:

    std::unique_ptr<StatementParameters> CreateParameters() override
    {
        return std::make_unique<ProcessingParameters>(
            std::make_unique<SymbolTable>(),
            std::make_unique<Decoder>()
        );
    }

    ~FabricModule() override = default;
};
