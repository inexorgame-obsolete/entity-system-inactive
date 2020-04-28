#include <visual-scripting/processors/logical/gates/GateProcessors.hpp>

#include <utility>

namespace inexor::visual_scripting {

GateProcessors::GateProcessors(NotProcessorPtr not_processor, OrProcessorPtr or_processor, AndProcessorPtr and_processor, XorProcessorPtr xor_processor, NorProcessorPtr nor_processor, NandProcessorPtr nand_processor)
    : LifeCycleComponent(not_processor, or_processor, and_processor, xor_processor, nor_processor, nand_processor)
{
    this->not_processor = std::move(not_processor);
    this->or_processor = std::move(or_processor);
    this->and_processor = std::move(and_processor);
    this->xor_processor = std::move(xor_processor);
    this->nor_processor = std::move(nor_processor);
    this->nand_processor = std::move(nand_processor);
}

GateProcessors::~GateProcessors() = default;

std::string GateProcessors::get_component_name()
{
    return "GateProcessors";
}

} // namespace inexor::visual_scripting
