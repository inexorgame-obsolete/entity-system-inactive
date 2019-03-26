#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/logical/comparison/EqualsIntEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

    /// @class EqualsIntFactory
    /// @brief Factory for creating entity instances of type EQUALS_INT.
	class EqualsIntFactory
	{
		public:

			using EqualsIntEntityTypeProviderPtr = std::shared_ptr<EqualsIntEntityTypeProvider>;
			using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

			/// @brief Constructs a factory for creating entity instances of type EQUALS_INT.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type EQUALS_INT.
            /// @param entity_instance_builder_factory Factory for creating entity instance builders.
			EqualsIntFactory(
				EqualsIntEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

            /// Destructor.
			~EqualsIntFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values.
			EntityInstancePtrOpt create_instance();

		private:

			/// Provides the entity type EQUALS_INT.
			EqualsIntEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
