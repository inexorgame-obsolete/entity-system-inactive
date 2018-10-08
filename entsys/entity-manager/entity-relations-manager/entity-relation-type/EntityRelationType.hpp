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
			std::shared_ptr<EntityType> destination_entity_type;


			// This vector of relation attribute types will be linked
			// to the entity relation type.
			std::vector<std::shared_ptr<EntityRelationAttributeType>> linked_relation_attribute_types;


		public:

			EntityRelationType(const std::string&, const std::shared_ptr<EntityType>&, const std::shared_ptr<EntityType>&);
			// TODO: Remove this!
			EntityRelationType(const std::string&)
			{
			}
			~EntityRelationType();
			
			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

			// Links an entity relation attribute type.
			ENTSYS_RESULT link_entity_relation_attribute_type();
			
			// TODO: Add and remove attributes!
			// TODO: Implement get methods.

	};


};
};
