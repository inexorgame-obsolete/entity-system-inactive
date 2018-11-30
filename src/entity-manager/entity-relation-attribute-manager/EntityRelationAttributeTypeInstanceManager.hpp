// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-attribute-manager/entity-relation-attribute-type-instance/EntityRelationAttributeTypeInstance.hpp"
#include "../entity-relation-attribute-manager/entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../templates/TypeInstanceManager.hpp"
#include "../../typedefs/TypeDefinitions.hpp"


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
			ENT_REL_ATTR_TYPE_INST create_entity_relation_attribute_type_instance(const ENT_REL_ATTR_TYPE&);

			// Get the number of existing entity relation attribute instances.
			const std::size_t get_entity_relation_attribute_type_instance_count() const;

			// Delete all instances of entity relation attribute types.
			void delete_all_entity_relation_type_attribute_instances();

	};


};
};
