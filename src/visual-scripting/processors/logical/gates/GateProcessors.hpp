#pragma once

#include "visual-scripting/processors/logical/gates/AndProcessor.hpp"
#include "visual-scripting/processors/logical/gates/NandProcessor.hpp"
#include "visual-scripting/processors/logical/gates/NorProcessor.hpp"
#include "visual-scripting/processors/logical/gates/NotProcessor.hpp"
#include "visual-scripting/processors/logical/gates/OrProcessor.hpp"
#include "visual-scripting/processors/logical/gates/XorProcessor.hpp"

namespace inexor::visual_scripting {

using NotProcessorPtr = std::shared_ptr<NotProcessor>;
using OrProcessorPtr = std::shared_ptr<OrProcessor>;
using AndProcessorPtr = std::shared_ptr<AndProcessor>;
using XorProcessorPtr = std::shared_ptr<XorProcessor>;
using NorProcessorPtr = std::shared_ptr<NorProcessor>;
using NandProcessorPtr = std::shared_ptr<NandProcessor>;

/// @class GateProcessors
/// @brief Management of the logger processors.
class GateProcessors
{
    public:
    /// @brief Constructs the processors for logical operations.
    /// @note The dependencies of this class will be injected automatically.
    /// @param not_processor Processor for the entity type NOT.
    /// @param or_processor Processor for the entity type OR.
    /// @param and_processor Processor for the entity type AND.
    /// @param xor_processor Processor for the entity type XOR.
    /// @param nor_processor Processor for the entity type NOR.
    /// @param nand_processor Processor for the entity type NAND.
    GateProcessors(NotProcessorPtr not_processor, OrProcessorPtr or_processor, AndProcessorPtr and_processor, XorProcessorPtr xor_processor, NorProcessorPtr nor_processor, NandProcessorPtr nand_processor);

    /// Destructor.
    ~GateProcessors();

    /// Initialization of the processors for logical operations.
    void init();

    private:
    /// Processor for the entity type NOT.
    NotProcessorPtr not_processor;

    /// Processor for the entity type OR.
    OrProcessorPtr or_processor;

    /// Processor for the entity type AND.
    AndProcessorPtr and_processor;

    /// Processor for the entity type XOR.
    XorProcessorPtr xor_processor;

    /// Processor for the entity type NOR.
    NorProcessorPtr nor_processor;

    /// Processor for the entity type NAND.
    NandProcessorPtr nand_processor;
};

} // namespace inexor::visual_scripting
