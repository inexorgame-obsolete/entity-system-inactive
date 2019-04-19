#pragma once

#include "visual-scripting/processors/generators/counters/CounterProcessors.hpp"
#include "visual-scripting/processors/generators/timers/TimerProcessors.hpp"
#include "visual-scripting/processors/generators/random/RandomProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	using CounterProcessorsPtr = std::shared_ptr<CounterProcessors>;
	using TimerProcessorsPtr = std::shared_ptr<TimerProcessors>;
	using RandomProcessorsPtr = std::shared_ptr<RandomProcessors>;

    /// @class GeneratorProcessors
    /// @brief Provides processors for generators like counters and timers.
	class GeneratorProcessors
	{
		public:

			/// @brief Constructs the processors for generators like counters and timers.
            /// @note The dependencies of this class will be injected automatically.
            /// @param counter_processors Processors for counters.
            /// @param timer_processors Processors for counters.
            /// @param random_processors Processors for random number generators.
			GeneratorProcessors(
				CounterProcessorsPtr counter_processors,
				TimerProcessorsPtr timer_processors,
				RandomProcessorsPtr random_processors
			);

            /// Destructor.
			~GeneratorProcessors();

			/// Initialization of the processors for generators like counters and timers.
			void init();

			/// Shut down the generator processors.
			void shutdown();

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
