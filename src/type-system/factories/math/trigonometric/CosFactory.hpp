#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/math/trigonometric/CosEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

    /// @class CosFactory
    /// @brief Factory for creating entity instances of type COS.
	class CosFactory
	{
		public:

			using CosEntityTypeProviderPtr = std::shared_ptr<CosEntityTypeProvider>;
			using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

            /// @brief Constructs a factory for creating entity instances of type COS.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type COS.
            /// @param Factory for creating entity instance builders.
			CosFactory(
				CosEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

            /// Destructor.
			~CosFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default value.
			EntityInstancePtrOpt create_instance();

			/// @brief Creates an instance with the given input value.
            /// @param input The given input value of type float.
			EntityInstancePtrOpt create_instance(float input);

		private:

			/// Provides the entity type COS.
			CosEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
