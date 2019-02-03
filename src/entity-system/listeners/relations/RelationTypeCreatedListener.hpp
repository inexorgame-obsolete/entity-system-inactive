// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	/// @class RelationTypeCreatedListener
    /// @brief Listener for newly created relation types.
	class RelationTypeCreatedListener
	{
		public:

			/// Called if a new relation type has been created.
			virtual void on_relation_type_created(REL_TYPE relation_type) = 0;

	};


};
};
