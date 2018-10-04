// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relations-manager/entity-relation-type-instance/EntityRelationTypeInstance.hpp"

namespace inexor {
namespace entity_system {


	// A manager class for instances of types of relations between entity types.
    class EntityRelationTypeInstanceManager
    {
		private:

			// Vector of instances of types of relations between entities.
			std::vector<EntityRelationTypeInstance> relation_type_instances;

        protected:
            
			// 
            EntityRelationTypeInstanceManager();
            
			// 
			~EntityRelationTypeInstanceManager();

		public:

			// Create a new entity relation type instance.
			std::shared_ptr<EntityRelationTypeInstance> create_entity_relation_type_instance(const std::shared_ptr<EntityRelationType>&,
				                                                                             const std::shared_ptr<EntityTypeInstance>&,
					                                                                         const std::shared_ptr<EntityTypeInstance>&);

			// TODO: get instances count.
			// TODO: delete instance.
			// TODO: get instance(s).
			// TODO: delete all instances.

    };


};
};
