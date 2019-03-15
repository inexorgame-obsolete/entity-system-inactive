#pragma once

#include "visual-scripting/processors/generators/counters/CounterProcessors.hpp"
#include "visual-scripting/processors/generators/timers/TimerProcessors.hpp"
#include "visual-scripting/processors/generators/random/RandomProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	using CounterProcessorsPtr = std::shared_ptr<CounterProcessors>;
	using TimerProcessorsPtr = std::shared_ptr<TimerProcessors>;
	using RandomProcessorsPtr = std::shared_ptr<RandomProcessors>;

    /// Provides processors for generators like counters and timers.
	class GeneratorProcessors
	{
		public:

			/// Constructs the processors for generators like counters and timers.
			GeneratorProcessors(
				CounterProcessorsPtr counter_processors,
				TimerProcessorsPtr timer_processors,
				RandomProcessorsPtr random_processors
			);

			~GeneratorProcessors();

			/// Initialization of the processors for generators like counters and timers.
			void init();

		private:

			/// Processors for counters.
			CounterProcessorsPtr counter_processors;

			/// Processors for counters.
			TimerProcessorsPtr timer_processors;

			/// Processors for random number generators.
			RandomProcessorsPtr random_processors;

	};

}
}
