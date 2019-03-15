#pragma once

#include "type-system/factories/generators/counters/CounterFactories.hpp"
#include "type-system/factories/generators/timers/TimerFactories.hpp"
#include "type-system/factories/generators/random/RandomFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using CounterFactoriesPtr = std::shared_ptr<CounterFactories>;
	using TimerFactoriesPtr = std::shared_ptr<TimerFactories>;
	using RandomFactoriesPtr = std::shared_ptr<RandomFactories>;

	/// The factories for generators like counters and timers.
	class GeneratorFactories
	{
		public:

			/// Constructs the factories for generators like counters and timers.
			GeneratorFactories(
				CounterFactoriesPtr counter_factories,
				TimerFactoriesPtr timer_factories,
				RandomFactoriesPtr random_factories
			);

			~GeneratorFactories();

			/// Initializes the factories for generators like counters and timers.
			void init();

		private:

			/// The factories for counters.
			CounterFactoriesPtr counter_factories;

			/// The factories for timers.
			TimerFactoriesPtr timer_factories;

			/// The factories for random number generators.
			RandomFactoriesPtr random_factories;

	};

}
}
}
