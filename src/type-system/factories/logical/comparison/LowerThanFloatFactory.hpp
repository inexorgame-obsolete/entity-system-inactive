#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/logical/comparison/LowerThanFloatEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

    /// @class LowerThanFloatFactory
    /// @brief Factory for creating entity instances of type LOWER_THAN_FLOAT.
	class LowerThanFloatFactory
	{
		public:

			using LowerThanFloatEntityTypeProviderPtr = std::shared_ptr<LowerThanFloatEntityTypeProvider>;
			using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

			/// @brief Constructs a factory for creating entity instances of type LOWER_THAN_FLOAT.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type LOWER_THAN_FLOAT.
            /// @param entity_instance_builder_factory Factory for creating entity instance builders.
			LowerThanFloatFactory(
				LowerThanFloatEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

            /// Destructor.
			~LowerThanFloatFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

		private:

			/// Provides the entity type LOWER_THAN_FLOAT.
			LowerThanFloatEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
