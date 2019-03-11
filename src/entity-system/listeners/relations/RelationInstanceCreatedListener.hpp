#pragma once

#include "entity-system/model/relations/relation-instances/RelationInstance.hpp"

namespace inexor {
namespace entity_system {

	/// @class RelationInstanceCreatedListener
    /// @brief Listener for newly created relation instances.
	class RelationInstanceCreatedListener
	{
		public:

			/// Called if a new relation instance has been created.
			virtual void on_relation_instance_created(std::shared_ptr<RelationInstance> relation_instance) = 0;

	};


}
}
