// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../entity-types-manager/entity-type/EntityType.hpp"
#include "../../entity-relations-manager/entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../../base-classes/TypeBase.hpp"


namespace inexor {
namespace entity_system {

	
	// A base class for types of entity relations
	class EntityRelationType : public TypeBase
	{
		private:

			// The entity type of the source entity.
			std::shared_ptr<EntityType> source_entity_type;

			// The entity type of the destination entity.
			std::shared_ptr<EntityType> target_entity_type;

			// Linked entity relation attribute types.
			std::vector<std::shared_ptr<EntityRelationAttributeType>> linked_rel_attr_types;

		public:

			EntityRelationType(const std::string&, const std::shared_ptr<EntityType>&, const std::shared_ptr<EntityType>&);
			~EntityRelationType();


			// Links an entity relation attribute type.
			void link_entity_relation_attribute_type(const std::shared_ptr<EntityRelationAttributeType>&);
			
			// TODO: Add relation attribute types!
			// TODO: Get relation attribute types!
						
			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;


	};


};
};
