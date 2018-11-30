// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "entity-type-instance/EntityTypeInstance.hpp"
#include "../../templates/TypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


	// A manager class for instances of types of entities.
    class EntityTypeInstanceManager : public TypeInstanceManager<EntityTypeInstance>
    {            
        protected:
            
			// 
			EntityTypeInstanceManager();

			// 
			~EntityTypeInstanceManager();
			
		public:

			// Create an entity type instance.
			ENT_TYPE_INST create_entity_type_instance(const ENT_TYPE&);

			// Get the number of existing entity type instances.
			const std::size_t get_entity_type_instance_count() const;

			// Delete all entity type instances
			void delete_all_entity_type_instances();

			// TODO: Delete by UUID!

	};


};
};
