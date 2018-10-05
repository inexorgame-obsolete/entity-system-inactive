// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "entity-attribute-type\EntityAttributeType.hpp"
#include "../../data-validation/DataValidationResults.hpp"

#include "../../templates/TypeManagerTemplate.hpp"


namespace inexor {
namespace entity_system {
    

	// A manager class for types of entity attributes.
    class EntityAttributeTypeManager : public TypeManagerTemplate<EntityAttributeType>//, public DataValidation
    {
        private:

			// This will be returned when a create method fails
			// TODO: Is there no better way to do this?
			// TODO: Don't use exceptions!
			std::shared_ptr<EntityAttributeType> entity_attribute_type_error;

        protected:

			// 
			EntityAttributeTypeManager();

			// 
            ~EntityAttributeTypeManager();

		public:

			// Delete all types of entity attributes.
			void delete_all_entity_attribute_types();

			// 
			bool does_entity_attribute_type_exist(const std::string&);

			// Create a new entity attribute type and store it in the entity system.
			std::shared_ptr<EntityAttributeType> create_entity_attribute_type(const std::string&, const ENTSYS_DATA_TYPE&);

			// Returns the number of available types of entities.
			const std::size_t get_entity_attribute_type_count() const;

			// Deletes an entity attribute type from the entity system.
			ENTSYS_RESULT delete_entity_attribute_type(const std::string&);
			//ENTSYS_RESULT delete_entity_attribute_type(const std::shared_ptr<EntityAttributeType>&);

			// Validates entity attribute types.
			//ENTSYS_DATA_VALIDATION_RESULT validate_attribute_types(const std::vector<std::shared_ptr<EntityAttributeType>>&);

	};


};
};
