#pragma once

#include <crossguid/guid.hpp>

namespace inexor {
namespace entity_system {

	/// @class EntityInstanceDeletedListener
	/// @brief Listener for deleted entity instances.
	class EntityInstanceDeletedListener
	{
		public:

			/// @brief Called if a entity instance has been deleted.
			/// @param type_GUID The GUID of the entity type of which an entity instance has been created.
			/// @param instance_GUID The GUID of the entity instance which has been created.
			virtual void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& instance_GUID) = 0;

	};


}
}
