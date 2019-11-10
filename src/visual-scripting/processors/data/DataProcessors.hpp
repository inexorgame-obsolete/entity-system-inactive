#pragma once

#include "visual-scripting/processors/data/converters/ConverterProcessors.hpp"

namespace inexor::visual_scripting {

using ConverterProcessorsPtr = std::shared_ptr<ConverterProcessors>;

/// @class DataProcessors
/// @brief Provides processors for data type and values.
class DataProcessors
{
    public:
    /// @brief Constructs the processors for data types and values.
    /// @param converter_processors Processors for data type converters.
    DataProcessors(ConverterProcessorsPtr converter_processors);

    /// Destructor.
    ~DataProcessors();

    /// Initialization of the processors for data types and values.
    void init();

    /// Shut down the processors for data types and values.
    void shutdown();

    private:
    /// Processors for counters.
    ConverterProcessorsPtr converter_processors;
};

} // namespace inexor::visual_scripting
