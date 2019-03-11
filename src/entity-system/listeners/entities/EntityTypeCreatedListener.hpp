#pragma once

#include "entity-system/model/entities/entity-types/EntityType.hpp"

namespace inexor {
namespace entity_system {

	/// @class EntityTypeCreatedListener
    /// @brief Listener for newly created entity types.
	class EntityTypeCreatedListener
	{
		public:

			/// Called if a new entity type has been created.
			virtual void on_entity_type_created(std::shared_ptr<EntityType> entity_type) = 0;

	};

}
}
