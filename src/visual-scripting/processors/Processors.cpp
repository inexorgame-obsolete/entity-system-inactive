#include "Processors.hpp"

#include <utility>

namespace inexor::visual_scripting {

Processors::Processors(ProcessorRegistryPtr processor_registry, DataProcessorsPtr data_processors, GeneratorProcessorsPtr generator_processors, InOutProcessorsPtr inout_processors, LogicalProcessorsPtr logical_processors, MathProcessorsPtr math_processors)
    : LifeCycleComponent(processor_registry, data_processors, generator_processors, inout_processors, logical_processors, math_processors)
{
    this->processor_registry = std::move(processor_registry);
    this->data_processors = std::move(data_processors);
    this->generator_processors = std::move(generator_processors);
    this->inout_processors = std::move(inout_processors);
    this->logical_processors = std::move(logical_processors);
    this->math_processors = std::move(math_processors);
}

Processors::~Processors() = default;

std::string Processors::get_component_name()
{
    return "Processors";
}

} // namespace inexor::visual_scripting
