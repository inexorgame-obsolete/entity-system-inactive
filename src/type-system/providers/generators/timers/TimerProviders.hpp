#pragma once

#include "type-system/providers/generators/timers/TimerTickEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using TimerTickEntityTypeProviderPtr = std::shared_ptr<TimerTickEntityTypeProvider>;

	/// The entity type providers for counters.
	class TimerProviders
	{
		public:

			/// Constructs the entity type providers for timers.
			TimerProviders(
				TimerTickEntityTypeProviderPtr timer_tick_entity_type_provider
			);

			~TimerProviders();

			/// Initializes the providers for timers.
			void init();

		private:

			/// Provides the entity type TIMER_TICK.
			TimerTickEntityTypeProviderPtr timer_tick_entity_type_provider;

	};

}
}
}
