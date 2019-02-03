// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	/// @class EntityInstanceCreatedListener
    /// @brief Listener for newly created entity instances.
	class EntityInstanceCreatedListener
	{
		public:

			/// Called if a new entity instance has been created.
			virtual void on_entity_instance_created(ENT_INST entity_instance) = 0;

	};


};
};
