#include "MathProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

MathProcessors::MathProcessors(ArithmeticProcessorsPtr arithmetic_processors, TrigonometricProcessorsPtr trigonometric_processors)
{
    this->arithmetic_processors = std::move(arithmetic_processors);
    this->trigonometric_processors = std::move(trigonometric_processors);
}

MathProcessors::~MathProcessors() = default;

void MathProcessors::init()
{
    this->arithmetic_processors->init();
    this->trigonometric_processors->init();
}

} // namespace inexor::visual_scripting
