// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "entity-attribute-type\EntityAttributeType.hpp"
#include "../../data-validation/DataValidationResults.hpp"


namespace inexor {
namespace entity_system {
    

    class EntityAttributeTypeManager
    {
        private:

			// In this unordered map all available types
			// of entity attributes in the entity system will be stored.
			std::unordered_map<std::string, std::shared_ptr<EntityAttributeType>> map_of_entity_attribute_types;

        protected:

			EntityAttributeTypeManager();

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

			// Validates entity attribute types
			ENTSYS_DATA_VALIDATION_RESULT validate_attribute_types(const std::vector<std::shared_ptr<EntityAttributeType>>&);

	};

};
};
