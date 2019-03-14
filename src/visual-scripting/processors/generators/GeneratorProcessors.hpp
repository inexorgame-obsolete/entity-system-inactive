#pragma once

#include "visual-scripting/processors/generators/counters/CounterProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	using CounterProcessorsPtr = std::shared_ptr<CounterProcessors>;

    /// Provides processors for generators like counters and timers.
	class GeneratorProcessors
	{
		public:

			/// Constructs the processors for generators like counters and timers.
			GeneratorProcessors(
				CounterProcessorsPtr counter_processors
			);

			~GeneratorProcessors();

			/// Initialization of the processors for generators like counters and timers.
			void init();

		private:

			/// Processors for counters.
			CounterProcessorsPtr counter_processors;

	};

}
}
