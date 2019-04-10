#pragma once

#include <crossguid/guid.hpp>

namespace inexor {
namespace entity_system {

	/// @class RelationTypeDeletedListener
	/// @brief Listener for newly created relation types.
	class RelationTypeDeletedListener
	{
		public:

			/// Called if a new relation type has been deleted.
			virtual void on_relation_type_deleted(const xg::Guid& type_GUID) = 0;

	};

}
}
