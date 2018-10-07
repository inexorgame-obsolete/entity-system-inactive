// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <unordered_map>

#include "../../entity-attributes-manager/entity-attribute-type/EntityAttributeType.hpp"
#include "../../../base-classes/TypeBase.hpp"


namespace inexor {
namespace entity_system {

	
	// A base class for types of entities.
	// This class needs to implement a data validation method!
	class EntityType : public TypeBase
    {
		private:

			// Every entity type can have linked entity attribute types.
			std::vector<std::shared_ptr<EntityAttributeType>> linked_entity_attribute_types;

        public:

			// Default constructor.
			EntityType(const std::string&);

			// Destructor.
            ~EntityType();

			// Checks if an entity attribute type
			// is already linked to an entity type.
			bool has_attribute_type(const std::string&);
			bool has_attribute_type(const std::shared_ptr<EntityAttributeType>&);
        
			// Links an entity attribute type to an entity type.
			ENTSYS_RESULT link_attribute_type(const std::shared_ptr<EntityAttributeType>&);
	
			// Returns the number of linked entity attribute types.
			std::size_t get_linked_attributes_count() const;

			// Returns a vector of linked types of attributes of entities.
			const std::vector<std::shared_ptr<EntityAttributeType>> get_linked_attribute_types() const;

			// Deletes all linked types of attributes.
			void reset_linked_attribute_types();

			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

    };


};
};
