#include "DataProcessors.hpp"

#include <utility>

namespace inexor::visual_scripting {

DataProcessors::DataProcessors(ConverterProcessorsPtr converter_processors)
{
    this->converter_processors = std::move(converter_processors);
}

DataProcessors::~DataProcessors() = default;

void DataProcessors::init()
{
    converter_processors->init();
}

void DataProcessors::shutdown()
{
    converter_processors->shutdown();
}

} // namespace inexor::visual_scripting
