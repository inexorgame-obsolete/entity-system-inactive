#pragma once

#include "entity-system/model/relations/relation-instances/RelationInstance.hpp"

namespace inexor {
namespace entity_system {

	/// @class RelationInstanceCreatedListener
	/// @brief Listener for newly created relation instances.
	class RelationInstanceCreatedListener
	{
		public:

			/// @brief Called if a new relation instance has been created.
			/// @param relation_instance The relation instance which has been created.
			/// @TODO: Use const std::shared_ptr<T>& instead?
			virtual void on_relation_instance_created(std::shared_ptr<RelationInstance> relation_instance) = 0;

	};


}
}
