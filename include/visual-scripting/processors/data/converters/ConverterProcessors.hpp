#pragma once

#include "visual-scripting/processors/data/converters/IntToFloatProcessor.hpp"
#include "visual-scripting/processors/data/converters/IntToStringProcessor.hpp"

namespace inexor::visual_scripting {

using IntToFloatProcessorPtr = std::shared_ptr<IntToFloatProcessor>;
using IntToStringProcessorPtr = std::shared_ptr<IntToStringProcessor>;

/// @class ConverterProcessors
/// @brief Provides processors for data type converters.
class ConverterProcessors : public LifeCycleComponent
{
    public:
    /// @brief Constructs the processors for data type converters.
    /// @param int_to_float_processor Processor for the entity type INT_TO_FLOAT.
    /// @param int_to_string_processor Processor for the entity type INT_TO_STRING.
    ConverterProcessors(IntToFloatProcessorPtr int_to_float_processor, IntToStringProcessorPtr int_to_string_processor);

    /// Destructor.
    ~ConverterProcessors();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Processor for the entity type INT_TO_FLOAT.
    IntToFloatProcessorPtr int_to_float_processor;

    /// Processor for the entity type INT_TO_STRING.
    IntToStringProcessorPtr int_to_string_processor;
};

} // namespace inexor::visual_scripting
