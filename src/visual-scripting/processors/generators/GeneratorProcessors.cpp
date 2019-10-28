#include "GeneratorProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

GeneratorProcessors::GeneratorProcessors(CounterProcessorsPtr counter_processors, TimerProcessorsPtr timer_processors, RandomProcessorsPtr random_processors)
{
    this->counter_processors = std::move(counter_processors);
    this->timer_processors = std::move(timer_processors);
    this->random_processors = std::move(random_processors);
}

GeneratorProcessors::~GeneratorProcessors() = default;

void GeneratorProcessors::init()
{
    counter_processors->init();
    timer_processors->init();
    random_processors->init();
}

void GeneratorProcessors::shutdown()
{
    //		random_processors->init();
    //		timer_processors->init();
    counter_processors->shutdown();
}

} // namespace inexor::visual_scripting
