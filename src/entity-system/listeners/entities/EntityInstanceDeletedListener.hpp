// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	/// @class EntityInstanceDeletedListener
    /// @brief Listener for deleted entity instances.
	class EntityInstanceDeletedListener
	{
		public:

			/// Called if a entity instance has been deleted.
			virtual void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& instance_GUID) = 0;

	};


};
};
