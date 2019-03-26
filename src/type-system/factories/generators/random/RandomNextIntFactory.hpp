#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/generators/random/RandomNextIntEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
	using RandomNextIntEntityTypeProviderPtr = std::shared_ptr<RandomNextIntEntityTypeProvider>;

    /// @class RandomNextIntFactory
    /// @brief Factory for creating entity instances of type RANDOM_NEXT_INT.
	class RandomNextIntFactory
	{
		public:

			/// @brief Constructs a factory for creating entity instances of type RANDOM_NEXT_INT.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type RANDOM_NEXT_INT.
            /// @param entity_instance_builder_factory Factory for creating entity instance builders.
			RandomNextIntFactory(
				RandomNextIntEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

            /// Destructor.
			~RandomNextIntFactory();

			/// Initializes the factory.
			void init();

			/// Creates a counter with the default values: millis = 1000, step = 1, start_value = 0.
			EntityInstancePtrOpt create_instance();

			/// @brief Creates an counter with the specified
            /// @param min ?
            /// @param min ?
			EntityInstancePtrOpt create_instance(int min, int max);

		private:

			/// Provides the entity type RANDOM_NEXT_INT.
			RandomNextIntEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
