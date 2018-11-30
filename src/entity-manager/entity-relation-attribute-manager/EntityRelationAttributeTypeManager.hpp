// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../templates/TypeManager.hpp"
#include "../entity-relation-attribute-manager/entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {

	
	// 
	class EntityRelationAttributeTypeManager : public TypeManager<EntityRelationAttributeType>
	{
		protected:

			// 
			EntityRelationAttributeTypeManager();

			// 
			~EntityRelationAttributeTypeManager();

		public:

			// Create an entity relation attribute type.
			ENT_REL_ATTR_TYPE create_entity_relation_attribute_type(const std::string&, const ENTSYS_DATA_TYPE&);

			// Get the number of existing entity relation attribute types.
			std::size_t get_entity_relation_attribute_type_count() const;

			// Delete all types of entity relation attributes.
			void delete_all_entity_relation_attribute_types();

	};


};
};
