#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/data/stores/FloatStoreEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using FloatStoreEntityTypeProviderPtr = std::shared_ptr<FloatStoreEntityTypeProvider>;
	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// Factory for creating entity instances of type FLOAT_STORE.
	class FloatStoreFactory
	{
		public:

			/// Constructs a factory for creating entity instances of type FLOAT_STORE.
			FloatStoreFactory(
				FloatStoreEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			~FloatStoreFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

			/// Creates an instance with the given name
			EntityInstancePtrOpt create_instance(const std::string& name, const float& input_value, const float& default_value, const float& output_value);

		private:

			/// Provides the entity type FLOAT_STORE.
			FloatStoreEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
