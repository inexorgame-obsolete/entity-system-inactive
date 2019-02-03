// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

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


};
};
