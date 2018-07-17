// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER

#include <string>
#include <vector>
#include "entity-attribute-type\base\EntityAttributeTypeBase.hpp"

namespace inexor {
namespace entsys {
        
    /// 
    /// 
    class EntityAttributeTypeManager
    {
        protected:
            std::vector<EntityAttributeTypeBase> entity_attribute_types;

        public:
            EntityAttributeTypeManager();
            ~EntityAttributeTypeManager();
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER
