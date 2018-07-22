// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_MANAGER_CLASS_HEADER

#include <vector>
#include "entity-type-instance\EntityTypeInstance.hpp"


namespace inexor {
namespace entsys {


    class EntityTypeInstanceManager
    {
        private:            
            
            // TODO: DISCUSS: Is this data type the best for this?
            std::vector<EntityTypeInstance> entity_type_instances;
            
        protected:
            
            // Make this protected so this class can only 
            // be instanced by inheritance as base class.
            EntityTypeInstanceManager();

            ~EntityTypeInstanceManager();

        public:

            // Create an instance of an entity type.
            const EntityTypeInstance create_entity_type_instance(const std::string&);

            const EntityTypeInstance create_entity_type_instance(const EntityTypeBase&);

    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_MANAGER_CLASS_HEADER
