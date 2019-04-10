#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor {
namespace entity_system {

	/// @class EntityInstanceCreatedListener
	/// @brief Listener for newly created entity instances.
	class EntityInstanceCreatedListener
	{
		public:

			/// Called if a new entity instance has been created.
			virtual void on_entity_instance_created(std::shared_ptr<EntityInstance> entity_instance) = 0;

	};

}
}
