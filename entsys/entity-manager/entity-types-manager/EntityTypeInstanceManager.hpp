// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>
#include "entity-type-instance\EntityTypeInstance.hpp"


namespace inexor {
namespace entity_system {


	// 
    class EntityTypeInstanceManager
    {
        private:            
            
			// 
            std::vector<std::shared_ptr<EntityTypeInstance>> entity_type_instances;
            
        protected:
            
			// 
			EntityTypeInstanceManager();

			// 
            ~EntityTypeInstanceManager();

        public:

			// 
			std::shared_ptr<EntityTypeInstance> create_entity_type_instance(const std::string&);

    };

};
};
