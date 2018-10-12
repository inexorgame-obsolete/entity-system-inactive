// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-type/EntityRelationType.hpp"
#include "../../entity-type-manager/entity-type-instance/EntityTypeInstance.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"
#include "../../entity-relation-attribute-manager/entity-relation-attribute-type-instance/EntityRelationAttributeTypeInstance.hpp"


namespace inexor {
namespace entity_system {


	// A base class for instances of types of relations between entity types.
	class EntityRelationTypeInstance : public TypeInstanceBase<EntityRelationType,EntityRelationTypeInstance>
	{
		private:
		
			// The instance of the source entity type.
			std::shared_ptr<EntityTypeInstance> source_entity_type_instance;

			// The instance of the target entity type.
			std::shared_ptr<EntityTypeInstance> destination_entity_type_instance;
			
			// TODO
			std::unordered_map<std::shared_ptr<EntityRelationAttributeType>,
				               std::shared_ptr<EntityRelationAttributeTypeInstance>> relation_attribute_instances;

		public:

			EntityRelationTypeInstance(const std::shared_ptr<EntityRelationType>&,
				                       const std::shared_ptr<EntityTypeInstance>&,
				                       const std::shared_ptr<EntityTypeInstance>&);

			~EntityRelationTypeInstance();


			// TODO: get source entity type
			// TODO: get destination entity type
			// TODO: Set data !

			
	};


};
};
