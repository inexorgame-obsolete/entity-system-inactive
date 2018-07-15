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
    class CEntityTypeInstanceManager
    {
        private:            
            std::vector<CEntityTypeInstance> entity_instances;
            
        public:
            CEntityTypeInstanceManager();
            ~CEntityTypeInstanceManager();
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_INSTANCE_MANAGER_CLASS_HEADER
