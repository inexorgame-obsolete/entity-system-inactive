#include "Processors.hpp"

#include <utility>

namespace inexor::visual_scripting {

Processors::Processors(ProcessorRegistryPtr processor_registry, DataProcessorsPtr data_processors, GeneratorProcessorsPtr generator_processors, InOutProcessorsPtr inout_processors, LogicalProcessorsPtr logical_processors, MathProcessorsPtr math_processors)
{
    this->processor_registry = std::move(processor_registry);
    this->data_processors = std::move(data_processors);
    this->generator_processors = std::move(generator_processors);
    this->inout_processors = std::move(inout_processors);
    this->logical_processors = std::move(logical_processors);
    this->math_processors = std::move(math_processors);
}

Processors::~Processors() = default;

void Processors::init()
{
    this->processor_registry->init();
    this->data_processors->init();
    this->generator_processors->init();
    this->inout_processors->init();
    this->logical_processors->init();
    this->math_processors->init();
}

void Processors::shutdown()
{
    //		this->math_processors->shutdown();
    //		this->logical_processors->shutdown();
    //		this->inout_processors->shutdown();
    this->generator_processors->shutdown();
    this->data_processors->shutdown();
    //		this->processor_registry->shutdown();
}

} // namespace inexor::visual_scripting
