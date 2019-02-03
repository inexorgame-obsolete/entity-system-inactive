// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	/// @class RelationInstanceCreatedListener
    /// @brief Listener for newly created relation instances.
	class RelationInstanceCreatedListener
	{
		public:

			/// Called if a new relation instance has been created.
			virtual void on_relation_instance_created(REL_INST relation_instance) = 0;

	};


};
};
