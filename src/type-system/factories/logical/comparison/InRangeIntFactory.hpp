#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/logical/comparison/InRangeIntEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

    /// Factory for creating entity instances of type IN_RANGE_INT.
	class InRangeIntFactory
	{
		public:

			using InRangeIntEntityTypeProviderPtr = std::shared_ptr<InRangeIntEntityTypeProvider>;
			using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

			/// Constructs a factory for creating entity instances of type IN_RANGE_INT.
			InRangeIntFactory(
				InRangeIntEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			~InRangeIntFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

		private:

			/// Provides the entity type IN_RANGE_INT.
			InRangeIntEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
