// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../entity-types-manager/entity-type/EntityType.hpp"
#include "../../entity-attributes-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"


namespace inexor {
namespace entity_system {

	// We have to add instances to the entity system
	// when creatin them in the constructor!
	extern class EntitySystem entsys;


	// A base class for instances of types of entities.
	// Only EntityTypeInstanceManager can create instances!
    class EntityTypeInstance : public DataValidation
    {
		private:

			// 
			std::unordered_map<ENT_ATTR_TYPE, ENT_ATTR_TYPE_INSTANCE> linked_entity_attribute_type_instances;

			// 
			std::shared_ptr<EntityType> pointer_to_entity_type;

		public:

			// Remove default constructor!
			EntityTypeInstance();

			// Create an instance of an entity type.
			EntityTypeInstance(const std::shared_ptr<EntityType>&);

			// Destructor.
			~EntityTypeInstance();

			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

			// Set attribute data
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const DataContainer&);

    };

};
};
