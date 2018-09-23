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
			std::unordered_map<std::string, std::shared_ptr<EntityAttributeType>> entity_attribute_type_buffer_map;

			// Entity attribute type error.
			std::shared_ptr<EntityAttributeType> entity_attribute_type_ERROR;

        protected:

			// 
			EntityAttributeTypeManager();

			// 
            ~EntityAttributeTypeManager();

			// TODO: Should this be public ?
			// Delete all types of entity attributes.
			void delete_all_entity_attribute_types();
	
		public:

			// 
			bool does_entity_attribute_type_exist(const std::string&);

			// Create a new entity attribute type and store it in the entity system.
			std::shared_ptr<EntityAttributeType> create_entity_attribute_type(const std::string&, const ENTSYS_DATA_TYPE&);

			// Returns the number of available types of entities.
			const std::size_t get_entity_attribute_type_count() const;

			// Deletes an entity attribute type from the entity system.
			ENTSYS_RESULT delete_entity_attribute_type(const std::string&);
			ENTSYS_RESULT delete_entity_attribute_type(const std::shared_ptr<EntityAttributeType>&);

			// Validates entity attribute types
			ENTSYS_DATA_VALIDATION_RESULT validate_attribute_types(const std::vector<std::shared_ptr<EntityAttributeType>>&);

	};

};
};
