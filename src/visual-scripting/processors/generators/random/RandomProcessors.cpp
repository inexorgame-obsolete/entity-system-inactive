#include "RandomProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

RandomProcessors::RandomProcessors(RandomNextIntProcessorPtr random_next_int_processor, RandomNextFloatProcessorPtr random_next_float_processor)
{
    this->random_next_int_processor = std::move(random_next_int_processor);
    this->random_next_float_processor = std::move(random_next_float_processor);
}

RandomProcessors::~RandomProcessors() = default;

void RandomProcessors::init()
{
    random_next_int_processor->init();
    random_next_float_processor->init();
}

} // namespace inexor::visual_scripting
