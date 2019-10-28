#include "TrigonometricProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

TrigonometricProcessors::TrigonometricProcessors(SinProcessorPtr sin_processor, CosProcessorPtr cos_processor, TanProcessorPtr tan_processor)
{
    this->sin_processor = std::move(sin_processor);
    this->cos_processor = std::move(cos_processor);
    this->tan_processor = std::move(tan_processor);
}

TrigonometricProcessors::~TrigonometricProcessors() = default;

void TrigonometricProcessors::init()
{
    sin_processor->init();
    cos_processor->init();
    tan_processor->init();
}

} // namespace inexor::visual_scripting
