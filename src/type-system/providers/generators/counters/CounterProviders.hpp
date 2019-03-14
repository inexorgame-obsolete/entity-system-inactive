#pragma once

#include "type-system/providers/generators/counters/CounterIntEntityTypeProvider.hpp"
#include "type-system/providers/generators/counters/CounterFloatEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using CounterIntEntityTypeProviderPtr = std::shared_ptr<CounterIntEntityTypeProvider>;
	using CounterFloatEntityTypeProviderPtr = std::shared_ptr<CounterFloatEntityTypeProvider>;

	/// The entity type providers for counters.
	class CounterProviders
	{
		public:

			/// Constructs the entity type providers for counters.
			CounterProviders(
				CounterIntEntityTypeProviderPtr counter_int_entity_type_provider,
				CounterFloatEntityTypeProviderPtr counter_float_entity_type_provider
			);

			~CounterProviders();

			/// Initializes the providers for logical operations.
			void init();

		private:

			/// Provides the entity type COUNTER_INT.
			CounterIntEntityTypeProviderPtr counter_int_entity_type_provider;

			/// Provides the entity type COUNTER_FLOAT.
			CounterFloatEntityTypeProviderPtr counter_float_entity_type_provider;

	};

}
}
}
