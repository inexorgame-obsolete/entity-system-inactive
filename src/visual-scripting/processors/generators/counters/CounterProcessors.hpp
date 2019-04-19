#pragma once

#include "visual-scripting/processors/generators/counters/CounterIntProcessor.hpp"
#include "visual-scripting/processors/generators/counters/CounterFloatProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using CounterIntProcessorPtr = std::shared_ptr<CounterIntProcessor>;
	using CounterFloatProcessorPtr = std::shared_ptr<CounterFloatProcessor>;

    /// @class CounterProcessors
	/// @brief Provides processors for time based counters.
	class CounterProcessors
	{
		public:

			/// @brief Constructs the processors for time based counters.
            /// @note The dependencies of this class will be injected automatically.
            /// @param counter_int_processor Processor for the entity type COUNTER_INT.
            /// @param counter_float_processor Processor for the entity type COUNTER_FLOAT.
			CounterProcessors(
				CounterIntProcessorPtr counter_int_processor,
				CounterFloatProcessorPtr counter_float_processor
			);

            /// Destructor.
			~CounterProcessors();

			/// Initialization of the processors for time based counters.
			void init();

			/// Shut down the processors for time based counters.
			void shutdown();

		private:

			/// Processor for the entity type COUNTER_INT.
			CounterIntProcessorPtr counter_int_processor;

			/// Processor for the entity type COUNTER_FLOAT.
			CounterFloatProcessorPtr counter_float_processor;

	};

}
}
