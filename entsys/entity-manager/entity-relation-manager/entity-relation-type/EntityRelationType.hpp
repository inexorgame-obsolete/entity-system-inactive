// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../entity-type-manager/entity-type/EntityType.hpp"
#include "../../entity-relation-attribute-manager/entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../../base-classes/TypeBase.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {

	
	// A base class for types of entity relations.
	class EntityRelationType : public TypeBase
	{
		private:

			// The entity type of the source entity.
			ENT_TYPE source_entity_type;

			// The entity type of the target entity.
			ENT_TYPE target_entity_type;

			// Vector of stored entity relation attribute types which are linked to this entity relation type.
			std::vector<ENT_REL_ATTR_TYPE> linked_rel_attr_types;

		public:

			// 
			EntityRelationType(const std::string&, const ENT_TYPE&, const ENT_TYPE&);
			
			// 
			~EntityRelationType();

			// Link an entity relation attribute type to this entity relation type.
			void link_entity_relation_attribute_type(const ENT_REL_ATTR_TYPE&);
			
			// Get linked entity relation attribute types.
			std::vector<ENT_REL_ATTR_TYPE> get_linked_attribute_types() const;
						
			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;


	};


};
};
