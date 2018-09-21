// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-attribute-type/EntityAttributeType.hpp"
#include "../../../data-container/DataContainer.hpp"


namespace inexor {
namespace entity_system {


	// A base class for instances of attributes of entities.
	class EntityAttributeTypeInstance : public DataValidation, public DataContainer
	{
		private:

			// Pointer to entity type.
			std::shared_ptr<EntityAttributeType> pointer_to_entity_attribute_type;

		public:

			// 
			EntityAttributeTypeInstance();

			// 
			EntityAttributeTypeInstance(const std::shared_ptr<EntityAttributeType>&);

			// 
			~EntityAttributeTypeInstance();

			// 
			void set_entity_attribute_type(const std::shared_ptr<EntityAttributeType>&);

			// 
			std::shared_ptr<EntityAttributeType> get_entity_attribute_type() const;

			// Returns the name of the entity attribute type.
			std::string get_entity_attribute_type_name() const;

			// Returns the data type of the entity attribute type
			ENTSYS_DATA_TYPE get_entity_attribute_data_type() const;

			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

	};

};
};
