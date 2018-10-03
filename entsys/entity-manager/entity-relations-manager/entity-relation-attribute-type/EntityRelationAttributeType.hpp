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
	// This class MUST implement a data validation method because of inheritance rules!
    class EntityRelationAttributeType : public DataValidation
    {
        protected:

			// Every entity attribute must have a unique name.
			std::string entity_relation_attribute_type_name;
			
			// The memory is associated with the entity attribute instance.
			// It will be managed by the EntityAttributeTypeInstance class
			// The data type of this container is declared here.
			ENTSYS_DATA_TYPE entity_relation_attribute_data_type;

        public:

			// TODO: Remove default constructor!
			EntityRelationAttributeType(); // = delete;
			
			// TODO: Make this the default constructor.
			EntityRelationAttributeType(const std::string&, const ENTSYS_DATA_TYPE&);

			// 
			~EntityRelationAttributeType();
			
			// Returns the name of the entity attribute type.
			std::string get_entity_relation_attribute_type_name() const;

			// Returns the data type of the entity attribute type
			ENTSYS_DATA_TYPE get_entity_relation_attribute_data_type() const;

			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

	};


};
};
