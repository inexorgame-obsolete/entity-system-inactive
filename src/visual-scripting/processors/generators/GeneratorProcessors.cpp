#include <visual-scripting/processors/generators/GeneratorProcessors.hpp>

#include <utility>

namespace inexor::visual_scripting {

GeneratorProcessors::GeneratorProcessors(CounterProcessorsPtr counter_processors, TimerProcessorsPtr timer_processors, RandomProcessorsPtr random_processors)
    : LifeCycleComponent(counter_processors, timer_processors, random_processors)
{
    this->counter_processors = std::move(counter_processors);
    this->timer_processors = std::move(timer_processors);
    this->random_processors = std::move(random_processors);
}

GeneratorProcessors::~GeneratorProcessors() = default;

std::string GeneratorProcessors::get_component_name()
{
    return "GeneratorProcessors";
}

} // namespace inexor::visual_scripting
