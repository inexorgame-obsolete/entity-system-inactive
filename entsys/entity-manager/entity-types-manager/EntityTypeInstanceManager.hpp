// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "entity-type/EntityType.hpp"
#include "entity-type-instance/EntityTypeInstance.hpp"


namespace inexor {
namespace entity_system {


	// A manager class for instances of types of entities.
    class EntityTypeInstanceManager
    {
        private:            
            
			// 
            std::vector<std::shared_ptr<EntityTypeInstance>> entity_type_instance_buffer;
            
        protected:
            
			// 
			EntityTypeInstanceManager();

			// 
			~EntityTypeInstanceManager();

        public:

			// Create an entity type instance.
			std::shared_ptr<EntityTypeInstance> create_entity_type_instance(const std::shared_ptr<EntityType>&);

			// Return the number of created instances.
			const std::size_t get_entity_type_instance_count() const;

			// Erase all instances.
			void delete_all_entity_type_instances();

	};


};
};
