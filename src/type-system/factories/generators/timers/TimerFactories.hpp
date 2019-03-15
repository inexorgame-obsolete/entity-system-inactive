#pragma once

#include "type-system/factories/generators/timers/TimerTickFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using TimerTickFactoryPtr = std::shared_ptr<TimerTickFactory>;

	/// Provides the factories for timers.
	class TimerFactories
	{
		public:

			/// Constructs the factories for timers.
			TimerFactories(
				TimerTickFactoryPtr timer_tick_factory
			);

			~TimerFactories();

			/// Initializes the factories for timers.
			void init();

		private:

			/// Factory for creating entity instances of type TIMER_TICK.
			TimerTickFactoryPtr timer_tick_factory;

	};

}
}
}
