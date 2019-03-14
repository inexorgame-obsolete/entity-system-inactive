#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/generators/counters/CounterFloatEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
	using CounterFloatEntityTypeProviderPtr = std::shared_ptr<CounterFloatEntityTypeProvider>;

    /// Factory for creating entity instances of type COUNTER_FLOAT.
	class CounterFloatFactory
	{
		public:

			/// Constructs a factory for creating entity instances of type COUNTER_FLOAT.
			CounterFloatFactory(
				CounterFloatEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			~CounterFloatFactory();

			/// Initializes the factory.
			void init();

			/// Creates a counter with the default values: millis = 1000, step = 1.0f, start_value = 0.0f.
			EntityInstancePtrOpt create_instance();

			/// Creates an counter with the specified
			EntityInstancePtrOpt create_instance(int millis, float step);

			/// Creates an counter with the specified
			EntityInstancePtrOpt create_instance(int millis, float step, float start_value);

		private:

			/// Provides the entity type COUNTER_FLOAT.
			CounterFloatEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
