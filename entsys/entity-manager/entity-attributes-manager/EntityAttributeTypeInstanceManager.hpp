// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_ATTRIBUTE_INSTANCE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_ATTRIBUTE_INSTANCE_MANAGER_CLASS_HEADER

#include "../../return-codes/ReturnCodes.hpp"


namespace inexor {
namespace entity_system {


    class EntityAttributeTypeInstanceManager
    {
        protected:
            
            // Make this protected so this class can only 
            // be instanced by inheritance as base class.
            EntityAttributeTypeInstanceManager();
            
            ~EntityAttributeTypeInstanceManager();

        public:

            // TODO: Implement!
            ENTSYS_RETURN_CODE create_entity_attribute_type_instance();

    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_INSTANCE_MANAGER_CLASS_HEADER
