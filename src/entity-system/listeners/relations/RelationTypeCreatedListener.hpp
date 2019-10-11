#pragma once

#include "entity-system/model/relations/relation-types/RelationType.hpp"

namespace inexor {
namespace entity_system {

	/// @class RelationTypeCreatedListener
	/// @brief Listener for newly created relation types.
	class RelationTypeCreatedListener
	{
		public:

			/// @brief Called if a new relation type has been created.
			/// @param relation_type The new relation type which has been created.
			virtual void on_relation_type_created(std::shared_ptr<RelationType> relation_type) = 0;

	};

}
}
