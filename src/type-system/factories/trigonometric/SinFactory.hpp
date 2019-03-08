#pragma once

#include "entity-system/managers/entities/entity-instance-builder-manager/EntityInstanceBuilderManager.hpp"
#include "type-system/providers/trigonometric/SinEntityTypeProvider.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// @class SinFactory
    /// @brief Factory for entity instances of type SIN.
	class SinFactory
	{
		using SinEntityTypeProviderPtr = std::shared_ptr<SinEntityTypeProvider>;
		using EntityInstanceBuilderManagerPtr = std::shared_ptr<EntityInstanceBuilderManager>;

		public:

			/// Constructor.
			SinFactory(
				SinEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderManagerPtr entity_instance_builder_manager
			);

			/// Destructor.
			~SinFactory();

			/// Creates an instance with default values
			std::optional<std::shared_ptr<EntityInstance> > create_instance();

		private:

			/// The entity type provider
			SinEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager
			EntityInstanceBuilderManagerPtr entity_instance_builder_manager;

	};


}
}
}
