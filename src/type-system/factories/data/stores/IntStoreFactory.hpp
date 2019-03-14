#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/data/stores/IntStoreEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using IntStoreEntityTypeProviderPtr = std::shared_ptr<IntStoreEntityTypeProvider>;
	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// Factory for creating entity instances of type INT_STORE.
	class IntStoreFactory
	{
		public:

			/// Constructs a factory for creating entity instances of type INT_STORE.
			IntStoreFactory(
				IntStoreEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			~IntStoreFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

			/// Creates an instance with the given name
			EntityInstancePtrOpt create_instance(const std::string& name, const int& input_value, const int& default_value, const int& output_value);

		private:

			/// Provides the entity type INT_STORE.
			IntStoreEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
