#pragma once

#include "visual-scripting/processors/logical/comparison/EqualsBoolProcessor.hpp"
#include "visual-scripting/processors/logical/comparison/EqualsIntProcessor.hpp"
#include "visual-scripting/processors/logical/comparison/EqualsStringProcessor.hpp"
#include "visual-scripting/processors/logical/comparison/GreaterThanIntProcessor.hpp"
#include "visual-scripting/processors/logical/comparison/GreaterThanFloatProcessor.hpp"
#include "visual-scripting/processors/logical/comparison/LowerThanIntProcessor.hpp"
#include "visual-scripting/processors/logical/comparison/LowerThanFloatProcessor.hpp"
#include "visual-scripting/processors/logical/comparison/InRangeIntProcessor.hpp"
#include "visual-scripting/processors/logical/comparison/InRangeFloatProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using EqualsBoolProcessorPtr = std::shared_ptr<EqualsBoolProcessor>;
	using EqualsIntProcessorPtr = std::shared_ptr<EqualsIntProcessor>;
	using EqualsStringProcessorPtr = std::shared_ptr<EqualsStringProcessor>;
	using GreaterThanIntProcessorPtr = std::shared_ptr<GreaterThanIntProcessor>;
	using GreaterThanFloatProcessorPtr = std::shared_ptr<GreaterThanFloatProcessor>;
	using LowerThanIntProcessorPtr = std::shared_ptr<LowerThanIntProcessor>;
	using LowerThanFloatProcessorPtr = std::shared_ptr<LowerThanFloatProcessor>;
	using InRangeIntProcessorPtr = std::shared_ptr<InRangeIntProcessor>;
	using InRangeFloatProcessorPtr = std::shared_ptr<InRangeFloatProcessor>;

    /// @class ComparisonProcessors
    /// @brief Provides the processors for comparison operations.
	class ComparisonProcessors
	{
		public:

			/// @brief Constructs the processors for comparison operations.
            /// @note The dependencies of this class will be injected automatically.
            /// @param equals_bool_processor Processor for the entity type EQUALS_BOOL.
            /// @param equals_int_processor Processor for the entity type EQUALS_INT.
            /// @param equals_string_processor Processor for the entity type EQUALS_STRING.
            /// @param greater_than_int_processor Processor for the entity type GREATER_THAN_INT.
            /// @param greater_than_float_processor Processor for the entity type GREATER_THAN_FLOAT.
            /// @param lower_than_int_processor Processor for the entity type LOWER_THAN_INT.
            /// @param lower_than_float_processor Processor for the entity type LOWER_THAN_FLOAT.
            /// @param in_range_int_processor Processor for the entity type IN_RANGE_INT.
            /// @param in_range_float_processor Processor for the entity type IN_RANGE_FLOAT.
			ComparisonProcessors(
				EqualsBoolProcessorPtr equals_bool_processor,
				EqualsIntProcessorPtr equals_int_processor,
				EqualsStringProcessorPtr equals_string_processor,
				GreaterThanIntProcessorPtr greater_than_int_processor,
				GreaterThanFloatProcessorPtr greater_than_float_processor,
				LowerThanIntProcessorPtr lower_than_int_processor,
				LowerThanFloatProcessorPtr lower_than_float_processor,
				InRangeIntProcessorPtr in_range_int_processor,
				InRangeFloatProcessorPtr in_range_float_processor
			);

            /// Destructor.
			~ComparisonProcessors();

			/// Initialization of the processors for comparison operations.
			void init();

		private:

			/// Processor for the entity type EQUALS_BOOL.
			EqualsBoolProcessorPtr equals_bool_processor;

			/// Processor for the entity type EQUALS_INT.
			EqualsIntProcessorPtr equals_int_processor;

			/// Processor for the entity type EQUALS_STRING.
			EqualsStringProcessorPtr equals_string_processor;

			/// Processor for the entity type GREATER_THAN_INT.
			GreaterThanIntProcessorPtr greater_than_int_processor;

			/// Processor for the entity type GREATER_THAN_FLOAT.
			GreaterThanFloatProcessorPtr greater_than_float_processor;

			/// Processor for the entity type LOWER_THAN_INT.
			LowerThanIntProcessorPtr lower_than_int_processor;

			/// Processor for the entity type LOWER_THAN_FLOAT.
			LowerThanFloatProcessorPtr lower_than_float_processor;

			/// Processor for the entity type IN_RANGE_INT.
			InRangeIntProcessorPtr in_range_int_processor;

			/// Processor for the entity type IN_RANGE_FLOAT.
			InRangeFloatProcessorPtr in_range_float_processor;

	};

}
}
