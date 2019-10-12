#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor {
namespace entity_system {

	/// @class EntityInstanceCreatedListener
	/// @brief Listener for newly created entity instances.
	class EntityInstanceCreatedListener
	{
		public:

			/// @brief Called if a new entity instance has been created.
			/// @param entity_instance The entity instance which has been created.
			/// @TODO: Use const std::shared_ptr<T>& instead?
			virtual void on_entity_instance_created(std::shared_ptr<EntityInstance> entity_instance) = 0;

	};

}
}
