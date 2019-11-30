#include "DataProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

DataProcessors::DataProcessors(ConverterProcessorsPtr converter_processors)
    : LifeCycleComponent(converter_processors)
{
    this->converter_processors = std::move(converter_processors);
}

DataProcessors::~DataProcessors() = default;

std::string DataProcessors::get_component_name()
{
    return "DataProcessors";
}

} // namespace inexor::visual_scripting
