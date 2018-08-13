// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_MANAGER_CLASS_HEADER

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

#endif // INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_MANAGER_CLASS_HEADER
