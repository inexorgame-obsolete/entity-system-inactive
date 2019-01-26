// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <vector>

#include "relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "relations/relation-type-manager/RelationTypeManager.hpp"
#include "relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "relation-attributes/relation-attribute-type-manager/RelationAttributeTypeManager.hpp"


using namespace inexor::entity_system;
using namespace std;


namespace inexor {
namespace entity_system {


    /// @class RelationManager
    /// @brief The relation manager manages the relation managers.
    class RelationManager
    {

		public:

			/// Constructor.
    		RelationManager(
				shared_ptr<RelationTypeManager> entity_relation_type_manager,
				shared_ptr<RelationInstanceManager> entity_relation_instance_manager,
				shared_ptr<RelationAttributeTypeManager> entity_relation_attribute_type_manager,
				shared_ptr<RelationAttributeInstanceManager> entity_relation_attribute_instance_manager
		    );

			/// Destructor.
			~RelationManager();

			/// Resets the entire entity system.
			void reset_entity_system();

		private:

			/// The entity relation type manager.
			shared_ptr<RelationTypeManager> relation_type_manager;

			/// The entity relation instance manager.
			shared_ptr<RelationInstanceManager> relation_instance_manager;

			/// The entity relation attribute type manager.
			shared_ptr<RelationAttributeTypeManager> relation_attribute_type_manager;

			/// The entity relation attribute instance manager.
			shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager;

    };


};
};
