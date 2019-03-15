#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/generators/timers/TimerTickEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
	using TimerTickEntityTypeProviderPtr = std::shared_ptr<TimerTickEntityTypeProvider>;

    /// Factory for creating entity instances of type TIMER_TICK.
	class TimerTickFactory
	{
		public:

			/// Constructs a factory for creating entity instances of type TIMER_TICK.
			TimerTickFactory(
				TimerTickEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			~TimerTickFactory();

			/// Initializes the factory.
			void init();

			/// Creates a counter with the default values: millis = 1000.
			EntityInstancePtrOpt create_instance();

			/// Creates an counter with the specified
			EntityInstancePtrOpt create_instance(int millis);

		private:

			/// Provides the entity type TIMER_TICK.
			TimerTickEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
