// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-attributes-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"


namespace inexor {
namespace entity_system {


	// A manager class for instances of attributes of entity types.
    class EntityAttributeTypeInstanceManager
    {
		protected:

			// 
			std::vector<std::shared_ptr<EntityAttributeTypeInstance>> entity_attribute_type_instance_buffer;

		protected:
            
			// 
			EntityAttributeTypeInstanceManager();
            
			// 
			~EntityAttributeTypeInstanceManager();

		public:

			// Create an entity attribute instance.
			std::shared_ptr<EntityAttributeTypeInstance> create_entity_attribute_type_instance(const std::shared_ptr<EntityAttributeType>&);

			// Return the number of created instances.
			const std::size_t get_entity_attribute_type_instance_count() const;

	};


};
};
