// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	/// @class EntityTypeCreatedListener
    /// @brief Listener for newly created entity types.
	class EntityTypeCreatedListener
	{
		public:

			/// Called if a new entity type has been created.
			virtual void on_entity_type_created(ENT_TYPE entity_type) = 0;

	};


};
};
