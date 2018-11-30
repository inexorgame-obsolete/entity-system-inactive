// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-manager/entity-relation-type-instance/EntityRelationTypeInstance.hpp"
#include "../../templates/TypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


	// A manager class for instances of types of relations between entity types.
    class EntityRelationTypeInstanceManager : public TypeInstanceManager<EntityRelationTypeInstance>
    {
        protected:
            
			// 
            EntityRelationTypeInstanceManager();

			// 
			~EntityRelationTypeInstanceManager();

		public:
		
			// Create a new entity relation type instance.
			ENT_REL_TYPE_INST create_entity_relation_type_instance(const ENT_REL_TYPE&, const ENT_TYPE_INST&, const ENT_TYPE_INST&);

			// 
			const std::size_t get_relation_type_instances_count() const;

			// TODO: Get instances count.
			// TODO: Delete instance.
			// TODO: Get instance(s).
			// TODO: Delete all instances.

    };


};
};
