#pragma once

#include <crossguid/guid.hpp>

namespace inexor {
namespace entity_system {

	/// @class RelationTypeDeletedListener
	/// @brief Listener for newly created relation types.
	class RelationTypeDeletedListener
	{
		public:

			/// @brief Called if a new relation type has been deleted.
			/// @param type_GUID The GUID of the relation type which was deleted.
			virtual void on_relation_type_deleted(const xg::Guid& type_GUID) = 0;

	};

}
}
