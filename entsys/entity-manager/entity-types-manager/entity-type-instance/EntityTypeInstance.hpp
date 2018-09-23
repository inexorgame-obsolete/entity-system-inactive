// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../entity-types-manager/entity-type/EntityType.hpp"
#include "../../entity-attributes-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"


namespace inexor {
namespace entity_system {


	// A base class for instances of types of entities.
	// Only EntityTypeInstanceManager can create instances!
    class EntityTypeInstance : public DataValidation
    {
		private:

			// 
			std::unordered_map<std::shared_ptr<EntityAttributeType>, std::shared_ptr<EntityAttributeTypeInstance>> linked_entity_attribute_type_instances;

			// 
			std::shared_ptr<EntityType> entity_type;

		public:

			// TODO: Remove default constructor!
			EntityTypeInstance(); // = delete;

			// TODO: Make this the default constructor.
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
