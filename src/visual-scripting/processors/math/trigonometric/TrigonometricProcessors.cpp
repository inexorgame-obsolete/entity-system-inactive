#include <visual-scripting/processors/math/trigonometric/TrigonometricProcessors.hpp>

#include <utility>

namespace inexor::visual_scripting {

TrigonometricProcessors::TrigonometricProcessors(SinProcessorPtr sin_processor, CosProcessorPtr cos_processor, TanProcessorPtr tan_processor)
    : LifeCycleComponent(sin_processor, cos_processor, tan_processor)
{
    this->sin_processor = std::move(sin_processor);
    this->cos_processor = std::move(cos_processor);
    this->tan_processor = std::move(tan_processor);
}

TrigonometricProcessors::~TrigonometricProcessors() = default;

std::string TrigonometricProcessors::get_component_name()
{
    return "TrigonometricProcessors";
}

} // namespace inexor::visual_scripting
