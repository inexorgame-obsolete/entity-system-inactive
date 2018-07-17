// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_ATTRIBUTE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_ATTRIBUTE_MANAGER_CLASS_HEADER

#include "../../../return-codes/ReturnCodes.hpp"

namespace inexor {
namespace entsys {

    class EntityAttributeManager
    {
        public:
            EntityAttributeManager();
            ~EntityAttributeManager();
            
            ENTSYS_RETURN_CODE add_attribute();
            ENTSYS_RETURN_CODE modify_attribute();
            ENTSYS_RETURN_CODE set_attribute_value();
            ENTSYS_RETURN_CODE remove_attribute();

    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_MANAGER_CLASS_HEADER
