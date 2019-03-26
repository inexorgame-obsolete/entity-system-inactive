#pragma once

#include "type-system/providers/generators/timers/TimerTickEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using TimerTickEntityTypeProviderPtr = std::shared_ptr<TimerTickEntityTypeProvider>;

    /// @class TimerProviders
	/// @brief The entity type providers for counters.
	class TimerProviders
	{
		public:

			/// @brief Constructs the entity type providers for timers.
            /// @note The dependencies of this class will be injected automatically.
            /// @param timer_tick_entity_type_provider Provides the entity type TIMER_TICK.
			TimerProviders(
				TimerTickEntityTypeProviderPtr timer_tick_entity_type_provider
			);

            /// Destructor.
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
