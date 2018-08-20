// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER


#include <memory>
#include <string>
#include <unordered_map>

#include "entity-attribute-type\EntityAttributeType.hpp"
//#include "../entity-types-manager/entity-type/EntityType.hpp"
//#include "../../return-codes/ReturnCodes.hpp"
//#include "../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {
    

	// 
    class EntityAttributeTypeManager
    {
        private:

			// In this unordered map all available types
			// of entity attributes in the entity system will be stored.
			std::unordered_map<std::string, std::shared_ptr<EntityAttributeType>> map_of_entity_attribute_types;

        protected:

			// 
			EntityAttributeTypeManager();

			// 
            ~EntityAttributeTypeManager();

        public:

			bool does_entity_attribute_type_exist(const std::string&);

			// Create a new entity attribute type and store it in the entity system.
			ENTSYS_RESULT create_entity_attribute_type(const std::shared_ptr<EntityAttributeType>&);

			// Returns the number of available types of entities.
			std::size_t get_entity_attribute_type_count() const;

			// Deletes an entity attribute type from the entity system.
			ENTSYS_RESULT delete_entity_attribute_type(const std::string&);
			ENTSYS_RESULT delete_entity_attribute_type(const std::shared_ptr<EntityAttributeType>&);

	};

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_MANAGER_CLASS_HEADER
