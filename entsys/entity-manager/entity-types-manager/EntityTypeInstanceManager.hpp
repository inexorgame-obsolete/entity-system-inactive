// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_MANAGER_CLASS_HEADER

#include <vector>
#include "entity-type-instance\EntityTypeInstance.hpp"

namespace inexor {
namespace entsys {

    /// \class CEntityTypeInstanceManager
    /// \brief TODO
    class EntityTypeInstanceManager
    {
        private:            
            std::vector<EntityTypeInstance> entity_instances;
            
        public:
            EntityTypeInstanceManager();
            ~EntityTypeInstanceManager();
                        
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_MANAGER_CLASS_HEADER
