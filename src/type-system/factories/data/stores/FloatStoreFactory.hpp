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

    /// @class FloatStoreFactory
    /// @brief Factory for creating entity instances of type FLOAT_STORE.
	class FloatStoreFactory
	{
		public:

			/// @brief Constructs a factory for creating entity instances of type FLOAT_STORE.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type FLOAT_STORE.
            /// @param entity_instance_builder_factory Factory for creating entity instance builders.
			FloatStoreFactory(
				FloatStoreEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

            /// Destructor.
			~FloatStoreFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values.
			EntityInstancePtrOpt create_instance();

			/// @brief Creates an instance with the given name.
            /// @param name ?
            /// @param input_value ?
            /// @param default_value ?
            /// @param output_value ?
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
