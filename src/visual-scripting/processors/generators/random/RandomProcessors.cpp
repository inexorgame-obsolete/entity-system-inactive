#include "RandomProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

RandomProcessors::RandomProcessors(RandomNextIntProcessorPtr random_next_int_processor, RandomNextFloatProcessorPtr random_next_float_processor)
    : LifeCycleComponent(random_next_int_processor, random_next_float_processor)
{
    this->random_next_int_processor = std::move(random_next_int_processor);
    this->random_next_float_processor = std::move(random_next_float_processor);
}

RandomProcessors::~RandomProcessors() = default;

std::string RandomProcessors::get_component_name()
{
    return "RandomProcessors";
}

} // namespace inexor::visual_scripting
