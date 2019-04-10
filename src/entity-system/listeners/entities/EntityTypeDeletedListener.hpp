#pragma once

#include <crossguid/guid.hpp>

namespace inexor {
namespace entity_system {

	/// @class EntityTypeDeletedListener
	/// @brief Listener for newly created entity types.
	class EntityTypeDeletedListener
	{
		public:

			/// Called if an entity type has been deleted.
			virtual void on_entity_type_deleted(const xg::Guid& type_GUID) = 0;

	};

}
}
