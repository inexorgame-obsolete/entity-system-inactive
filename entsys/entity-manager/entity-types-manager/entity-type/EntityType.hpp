// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <unordered_map>

// std::strcmp
#include <cstring>

#include "../../../return-codes/ReturnCodes.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"
#include "../../../data-validation/DataValidation.hpp"

#include "../../entity-attributes-manager/entity-attribute-type/EntityAttributeType.hpp"


namespace inexor {
namespace entity_system {

	
	// A base class for types of entities.
	// This class needs to implement a data validation method!
	class EntityType : public DataValidation
    {
		private:

			// Every entity type must have a unique name.
			std::string entity_type_name;

			// Every entity type can have linked
			// entity attribute types which will be stored here.
			std::vector<std::shared_ptr<EntityAttributeType>> vector_of_linked_entity_attribute_types;

			// TODO: add UUID ?

        protected:
                        
        public:

			// Remove the default constructor!
			EntityType() = delete;

			// Make this the default constructor so 
			// the name of an entity type must be set!
            EntityType(const std::string&);

			// 
            ~EntityType();
			
			// Returns the name of the entity type;
			std::string get_entity_type_name() const;

			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;


			// Checks if an entity attribute type
			// is already linked to an entity type.
			bool is_entity_attribute_type_linked(const std::string&);
            
			// Links an entity attribute type to an entity type.
			ENTSYS_RESULT link_entity_attribute_type_to_entity_type(const std::shared_ptr<EntityAttributeType>&);


    };

};
};
