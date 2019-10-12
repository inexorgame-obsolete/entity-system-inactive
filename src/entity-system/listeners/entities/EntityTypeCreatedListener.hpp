#pragma once

#include "entity-system/model/entities/entity-types/EntityType.hpp"

namespace inexor {
namespace entity_system {

	/// @class EntityTypeCreatedListener
	/// @brief Listener for newly created entity types.
	class EntityTypeCreatedListener
	{
		public:

			/// @brief Called if a new entity type has been created.
			/// @param entity_type The entity type which has been created.
			/// @TODO const std::shared_ptr<T>& instead?
			virtual void on_entity_type_created(std::shared_ptr<EntityType> entity_type) = 0;

	};

}
}
