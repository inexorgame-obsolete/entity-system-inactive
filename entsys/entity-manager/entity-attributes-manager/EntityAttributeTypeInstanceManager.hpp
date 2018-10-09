// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-attributes-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"

#include "../../templates/TypeInstanceManagerTemplate.hpp"


namespace inexor {
namespace entity_system {


	// A manager class for instances of attributes of entity types.
    class EntityAttributeTypeInstanceManager : public TypeInstanceManagerTemplate<EntityAttributeTypeInstance>
    {
		protected:
            
			EntityAttributeTypeInstanceManager();
			~EntityAttributeTypeInstanceManager();

		public:

			// Create an entity attribute instance.
			std::shared_ptr<EntityAttributeTypeInstance> create_entity_attribute_type_instance(const std::shared_ptr<EntityAttributeType>&);

			// Return the number of created instances.
			const std::size_t get_entity_attribute_type_instance_count() const;

			// Delete all instances of entity attribute types.
			void delete_all_entity_attribute_type_instances();

	};


};
};
