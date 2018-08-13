// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_CLASS_HEADER

#include <string>
#include <unordered_map>

#include "../../../return-codes/ReturnCodes.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"
#include "../../entity-attributes-manager/entity-attribute-type/EntityAttributeType.hpp"


namespace inexor {
namespace entity_system {

	
	// A base class for types of entities.
	class EntityType
    {
        protected:
                        
			// TODO: add data/methods here!
            
        public:

			// 
            EntityType();

			// 
            ~EntityType();


    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_CLASS_HEADER
