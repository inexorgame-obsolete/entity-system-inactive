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
    class EntityAttributeTypeManager : public TypeManagerTemplate<EntityAttributeType>
    {
        private:

			// This error entity attribute type will be returned when a method fails.
			std::shared_ptr<EntityAttributeType> entity_attribute_type_error;

        protected:

			EntityAttributeTypeManager();
            ~EntityAttributeTypeManager();

		public:

			// Check if an entity attribute type does already exist.
			bool does_entity_attribute_type_exist(const std::string&);
			bool does_entity_attribute_type_exist(const std::shared_ptr<EntityAttributeType>&);

			// Create a new entity attribute type and store it in the entity system.
			std::shared_ptr<EntityAttributeType> create_entity_attribute_type(const std::string&, const ENTSYS_DATA_TYPE&);

			// Returns the number of available types of entities.
			const std::size_t get_entity_attribute_type_count() const;

			// Deletes an entity attribute type from the entity system.
			void delete_entity_attribute_type(const std::string&);
			void delete_entity_attribute_type(const std::shared_ptr<EntityAttributeType>&);
			// TODO: Delete by UUID.

			// Delete all types of entity attributes.
			void delete_all_entity_attribute_types();


	};


};
};
