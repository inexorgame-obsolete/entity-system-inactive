// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>

#include "../../../data-validation/DataValidation.hpp"

#include "../../entity-types-manager/entity-type/EntityType.hpp"
#include "../../entity-attributes-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"


namespace inexor {
namespace entity_system {


	// A base class for instances of types of entities.
    class EntityTypeInstance : public DataValidation
    {
		private:

			std::vector<std::shared_ptr<EntityAttributeTypeInstance>> vector_of_instances_of_linked_entity_attribute_types;

			std::shared_ptr<EntityType> pointer_to_entity_type;

		public:

			// Remove default constructor!
			EntityTypeInstance() = delete;

			// 
			EntityTypeInstance(const std::shared_ptr<EntityType>&);

			// 
			~EntityTypeInstance();

			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

    };

};
};
