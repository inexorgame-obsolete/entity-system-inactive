#pragma once

#include <crossguid/guid.hpp>

namespace inexor {
namespace entity_system {

	/// @class RelationInstanceDeletedListener
    /// @brief Listener for deleted relation instances.
	class RelationInstanceDeletedListener
	{
		public:

			/// Called if a relation instance has been deleted.
			virtual void on_relation_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& instance_GUID) = 0;

	};


}
}
