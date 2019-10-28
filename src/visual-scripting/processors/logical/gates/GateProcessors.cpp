#include "GateProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

GateProcessors::GateProcessors(NotProcessorPtr not_processor, OrProcessorPtr or_processor, AndProcessorPtr and_processor, XorProcessorPtr xor_processor, NorProcessorPtr nor_processor, NandProcessorPtr nand_processor)
{
    this->not_processor = std::move(not_processor);
    this->or_processor = std::move(or_processor);
    this->and_processor = std::move(and_processor);
    this->xor_processor = std::move(xor_processor);
    this->nor_processor = std::move(nor_processor);
    this->nand_processor = std::move(nand_processor);
}

GateProcessors::~GateProcessors() = default;

void GateProcessors::init()
{
    not_processor->init();
    or_processor->init();
    and_processor->init();
    xor_processor->init();
    nor_processor->init();
    nand_processor->init();
}

} // namespace inexor::visual_scripting
