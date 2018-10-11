// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../entity-types-manager/entity-type/EntityType.hpp"
#include "../../entity-relation-attributes-manager/entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../../base-classes/TypeBase.hpp"


namespace inexor {
namespace entity_system {

	
	// A base class for types of entity relations.
	class EntityRelationType : public TypeBase
	{
		private:

			// The entity type of the source entity.
			std::shared_ptr<EntityType> source_entity_type;

			// The entity type of the target entity.
			std::shared_ptr<EntityType> target_entity_type;

			// Vector of stored entity relation attribute types which are linked to this entity relation type.
			std::vector<std::shared_ptr<EntityRelationAttributeType>> linked_rel_attr_types;

		public:

			EntityRelationType(const std::string&, const std::shared_ptr<EntityType>&, const std::shared_ptr<EntityType>&);
			~EntityRelationType();


			// Link an entity relation attribute type to this entity relation type.
			void link_entity_relation_attribute_type(const std::shared_ptr<EntityRelationAttributeType>&);
			
			// Get linked entity relation attribute types.
			std::vector<std::shared_ptr<EntityRelationAttributeType>> get_linked_attribute_types() const;
						
			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;


	};


};
};
