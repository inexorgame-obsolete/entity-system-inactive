// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-attribute-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"
#include "../../templates/TypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


	// A manager class for instances of attributes of entity types.
    class EntityAttributeTypeInstanceManager
		: public TypeInstanceManager<EntityAttributeTypeInstance>
    {
		protected:
            
			// 
			EntityAttributeTypeInstanceManager();

			// 
			~EntityAttributeTypeInstanceManager();

		public:

			// Create an entity attribute type instance.
			std::shared_ptr<EntityAttributeTypeInstance> create_entity_attribute_type_instance(
				const std::shared_ptr<EntityAttributeType>&);

			// Return the number of existing entity attribute type instances.
			const std::size_t get_entity_attribute_type_instance_count() const;

			// Delete all entity attribute type instances.
			void delete_all_entity_attribute_type_instances();

	};


};
};
