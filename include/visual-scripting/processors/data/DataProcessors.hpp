#pragma once

#include "visual-scripting/processors/data/converters/ConverterProcessors.hpp"

namespace inexor::visual_scripting {

using ConverterProcessorsPtr = std::shared_ptr<ConverterProcessors>;

/// @class DataProcessors
/// @brief Provides processors for data type and values.
class DataProcessors : public LifeCycleComponent
{
    public:
    /// @brief Constructs the processors for data types and values.
    /// @param converter_processors Processors for data type converters.
    DataProcessors(ConverterProcessorsPtr converter_processors);

    /// Destructor.
    ~DataProcessors();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Processors for counters.
    ConverterProcessorsPtr converter_processors;
};

} // namespace inexor::visual_scripting
