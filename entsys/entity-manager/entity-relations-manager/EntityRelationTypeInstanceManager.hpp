// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relations-manager/entity-relation-type-instance/EntityRelationTypeInstance.hpp"
#include "../../templates/TypeInstanceManagerTemplate.hpp"


namespace inexor {
namespace entity_system {


	// A manager class for instances of types of relations between entity types.
    class EntityRelationTypeInstanceManager : public TypeInstanceManagerTemplate<EntityRelationTypeInstance>
    {
        protected:
            
            EntityRelationTypeInstanceManager();
			~EntityRelationTypeInstanceManager();

		public:
		
			// Create a new entity relation type instance.
			std::shared_ptr<EntityRelationTypeInstance> create_entity_relation_type_instance(const std::shared_ptr<EntityRelationType>&,
				                                                                             const std::shared_ptr<EntityTypeInstance>&,
					                                                                         const std::shared_ptr<EntityTypeInstance>&);


			const std::size_t get_relation_type_instances_count() const;

			// TODO: Get instances count.
			// TODO: Delete instance.
			// TODO: Get instance(s).
			// TODO: Delete all instances.

    };


};
};
