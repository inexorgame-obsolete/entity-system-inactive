// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "../../../return-codes/ReturnCodes.hpp"
#include "../../../data-validation/DataValidation.hpp"
#include "../../../data-container/DataTypes.hpp"


namespace inexor {
namespace entity_system {
    
	
	// A base class for types of entity attributes.
	// This class needs to implement a data validation method!
	// PLEASE NOTE
	// The corresponding DataContainer will be managed by the EntityAttributeTypeInstance class!
    class EntityAttributeType : public DataValidation
    {
        protected:

			// Every entity attribute must have a unique name.
			std::string entity_attribute_type_name;
			
			// PLEASE NOTE
			// The corresponding DataContainer will be managed by the EntityAttributeTypeInstance class!
			// The data type of this container however must be declared here.
			ENTSYS_DATA_TYPE entity_attribute_data_type;


        public:

			// Remove the default constructor!
			EntityAttributeType() = delete;
			
			// Make this the default constructor so 
			// the name of an entity type must be set!
			EntityAttributeType(const std::string&, const ENTSYS_DATA_TYPE&);

			EntityAttributeType(const std::string&);

            ~EntityAttributeType();

			// Returns the name of the entity attribute type.
			std::string get_entity_attribute_type_name() const;

			// Returns the data type of the entity attribute type
			ENTSYS_DATA_TYPE get_entity_attribute_data_type() const;

			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

	};
    

};
};
