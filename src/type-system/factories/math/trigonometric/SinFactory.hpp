#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/math/trigonometric/SinEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

    /// @class SinFactory
    /// @brief Factory for creating entity instances of type SIN.
	class SinFactory
	{
		public:

			using SinEntityTypeProviderPtr = std::shared_ptr<SinEntityTypeProvider>;
			using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

			/// @brief Constructs a factory for creating entity instances of type SIN.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type SIN.
            /// @param entity_instance_builder_factory Factory for creating entity instance builders.
			SinFactory(
				SinEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

            /// Destructor.
			~SinFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

			/// @brief Creates an instance with the given input value.
            /// @param input the given input value of type float.
			EntityInstancePtrOpt create_instance(float input);

		private:

			/// Provides the entity type SIN.
			SinEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
