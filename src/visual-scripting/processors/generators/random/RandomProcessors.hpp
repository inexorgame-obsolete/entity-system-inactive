#pragma once

#include "visual-scripting/processors/generators/random/RandomNextFloatProcessor.hpp"
#include "visual-scripting/processors/generators/random/RandomNextIntProcessor.hpp"

namespace inexor::visual_scripting {

using RandomNextIntProcessorPtr = std::shared_ptr<RandomNextIntProcessor>;
using RandomNextFloatProcessorPtr = std::shared_ptr<RandomNextFloatProcessor>;

/// @class RandomProcessors
/// @brief Provides processors for random number generators.
class RandomProcessors
{
    public:
    /// @brief Constructs the processors for random number generators.
    /// @param random_next_int_processor Processor for the entity type RANDOM_NEXT_INT.
    /// @param random_next_float_processor Processor for the entity type RANDOM_NEXT_FLOAT.
    RandomProcessors(RandomNextIntProcessorPtr random_next_int_processor, RandomNextFloatProcessorPtr random_next_float_processor);

    /// Destructor.
    ~RandomProcessors();

    /// Initialization of the processors for random number generators.
    void init();

    private:
    /// Processor for the entity type RANDOM_NEXT_INT.
    RandomNextIntProcessorPtr random_next_int_processor;

    /// Processor for the entity type RANDOM_NEXT_FLOAT.
    RandomNextFloatProcessorPtr random_next_float_processor;
};

} // namespace inexor::visual_scripting
