#include <visual-scripting/processors/math/MathProcessors.hpp>

#include <utility>

namespace inexor::visual_scripting {

MathProcessors::MathProcessors(ArithmeticProcessorsPtr arithmetic_processors, TrigonometricProcessorsPtr trigonometric_processors)
    :LifeCycleComponent(arithmetic_processors, trigonometric_processors)
{
    this->arithmetic_processors = std::move(arithmetic_processors);
    this->trigonometric_processors = std::move(trigonometric_processors);
}

MathProcessors::~MathProcessors() = default;

std::string MathProcessors::get_component_name()
{
    return "Processors";
}

} // namespace inexor::visual_scripting
