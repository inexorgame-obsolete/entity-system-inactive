// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <optional>

#include "entity-system/managers/relations/relation-instance-manager/EntityRelationInstanceManager.hpp"
#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-instance-manager/EntityRelationAttributeInstanceManager.hpp"
#include "entity-system/model/relations/relation-instances/EntityRelationInstance.hpp"
#include "entity-system/model/relations/relation-types/EntityRelationType.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity relation type instances.
    class EntityRelationInstanceManager : public InstanceManagerTemplate<EntityRelationInstance>
    {
        protected:
            
			/// Constructor.
            EntityRelationInstanceManager();

			/// Destructor.
			~EntityRelationInstanceManager();

    		/// The entity relation attribute instance manager
    		std::shared_ptr<EntityRelationAttributeInstanceManager> entity_relation_attribute_instance_manager;

		public:
		
			/// Creates a new entity relation type instance.
			/// @param ent_rel_type A const reference to a shared pointer of
			/// an entity relation type of which an instance will be created.
			/// @param ent_type_inst_source A const reference to a shared pointer of
			/// the entity type instance which will be used as <b>source</b> entity type instance.
			/// @param ent_type_inst_target A const reference to a shared pointer of
			/// the entity type instance which will be used as <b>target</b> entity type instance.
			/// @return A shared pointer to the new entity relation type instance which was created.
			std::optional<ENT_REL_INST> create_entity_relation_instance(const ENT_REL_TYPE&, const ENT_INST&, const ENT_INST&);

			/// Returns the number of relation type instances.
			/// @return The number of existing entity relation type instances.
			std::size_t get_relation_instances_count() const;


			// TODO: Get instances count.
			// TODO: Delete instance.
			// TODO: Get instance(s).
			// TODO: Delete all instances.

    };


};
};
