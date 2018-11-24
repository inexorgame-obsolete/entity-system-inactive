// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-attribute-manager/entity-relation-attribute-type-instance/EntityRelationAttributeTypeInstance.hpp"
#include "../entity-relation-attribute-manager/entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../templates/TypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


	//
	class EntityRelationAttributeTypeInstanceManager
		: public TypeInstanceManager<EntityRelationAttributeTypeInstance>
	{
		protected:

			// 
			EntityRelationAttributeTypeInstanceManager();

			// 
			~EntityRelationAttributeTypeInstanceManager();

	public:
			
			// Create an entity relation attribute type instance.
			std::shared_ptr<EntityRelationAttributeTypeInstance>
				create_entity_relation_attribute_type_instance(const std::shared_ptr<EntityRelationAttributeType>&);

			// Get the number of existing entity relation attribute instances.
			const std::size_t get_entity_relation_attribute_type_instance_count() const;

			// Delete all instances of entity relation attribute types.
			void delete_all_entity_relation_type_attribute_instances();

	};


};
};
