#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/logical/comparison/GreaterThanFloatEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

    /// @class GreaterThanFloatFactory
    /// @brief Factory for creating entity instances of type GREATER_THAN_FLOAT.
	class GreaterThanFloatFactory
	{
		public:

			using GreaterThanFloatEntityTypeProviderPtr = std::shared_ptr<GreaterThanFloatEntityTypeProvider>;
			using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

			/// @brief Constructs a factory for creating entity instances of type GREATER_THAN_FLOAT.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type GREATER_THAN_FLOAT.
            /// @param entity_instance_builder_factory Factory for creating entity instance builders.
			GreaterThanFloatFactory(
				GreaterThanFloatEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

            /// Destructor.
			~GreaterThanFloatFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values.
			EntityInstancePtrOpt create_instance();

		private:

			/// Provides the entity type GREATER_THAN_FLOAT.
			GreaterThanFloatEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
