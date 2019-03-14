#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/generators/counters/CounterIntEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
	using CounterIntEntityTypeProviderPtr = std::shared_ptr<CounterIntEntityTypeProvider>;

    /// Factory for creating entity instances of type COUNTER_INT.
	class CounterIntFactory
	{
		public:

			/// Constructs a factory for creating entity instances of type COUNTER_INT.
			CounterIntFactory(
				CounterIntEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			~CounterIntFactory();

			/// Initializes the factory.
			void init();

			/// Creates a counter with the default values: millis = 1000, step = 1, start_value = 0.
			EntityInstancePtrOpt create_instance();

			/// Creates an counter with the specified
			EntityInstancePtrOpt create_instance(int millis, int step);

			/// Creates an counter with the specified
			EntityInstancePtrOpt create_instance(int millis, int step, int start_value);

		private:

			/// Provides the entity type COUNTER_INT.
			CounterIntEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
