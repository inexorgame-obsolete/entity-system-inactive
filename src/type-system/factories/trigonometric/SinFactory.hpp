#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "type-system/providers/trigonometric/SinEntityTypeProvider.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

	/// @class SinFactory
    /// @brief Factory for entity instances of type SIN.
	class SinFactory
	{
		public:

			using SinEntityTypeProviderPtr = std::shared_ptr<SinEntityTypeProvider>;
			using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

			/// Constructor.
			SinFactory(
				SinEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			/// Destructor.
			~SinFactory();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

		private:

			/// The entity type provider
			SinEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};


}
}
}
