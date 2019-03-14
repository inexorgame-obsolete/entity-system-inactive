#pragma once

#include "visual-scripting/processors/generators/counters/CounterIntProcessor.hpp"
#include "visual-scripting/processors/generators/counters/CounterFloatProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using CounterIntProcessorPtr = std::shared_ptr<CounterIntProcessor>;
	using CounterFloatProcessorPtr = std::shared_ptr<CounterFloatProcessor>;

	/// Provides processors for time based counters.
	class CounterProcessors
	{
		public:

			/// Constructs the processors for time based counters.
			CounterProcessors(
				CounterIntProcessorPtr counter_int_processor,
				CounterFloatProcessorPtr counter_float_processor
			);

			~CounterProcessors();

			/// Initialization of the processors for time based counters.
			void init();

		private:

			// Processor for the entity type COUNTER_INT
			CounterIntProcessorPtr counter_int_processor;

			// Processor for the entity type COUNTER_FLOAT
			CounterFloatProcessorPtr counter_float_processor;

	};

}
}
