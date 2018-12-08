// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-type/EntityRelationType.hpp"
#include "../../entity-type-manager/entity-type-instance/EntityTypeInstance.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"
#include "../../entity-relation-attribute-manager/entity-relation-attribute-type-instance/EntityRelationAttributeTypeInstance.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for entity relation type instances.
	class EntityRelationTypeInstance : public TypeInstanceBase<EntityRelationType,EntityRelationTypeInstance>
	{
		private:
		
			/// The source entity type instance.
			ENT_TYPE_INST source_entity_type_instance;

			/// The target entity type instance.
			ENT_TYPE_INST destination_entity_type_instance;
			
			/// Entity relation attribute type instances stored by entity relation attribute types.
			std::unordered_map<ENT_REL_ATTR_TYPE, ENT_REL_ATTR_TYPE_INST> relation_attribute_instances;

		public:

			/// Constructor.
			/// @param ent_rel_type A const reference to a shared pointer of
			/// an entity relation type of which an instance will be created.
			/// @param ent_type_inst_source A const reference to a shared pointer of
			/// an entity type instance which will be used as source entity instance.
			/// @param ent_type_inst_target A const reference to a shared pointer of
			/// an entity type instance which will be used as target entity instance.
			/// @note The GUID of the new entity relation type instance will
			/// be created automatically by the inheritance of GUIDBase!
			EntityRelationTypeInstance(const ENT_REL_TYPE&, const ENT_TYPE_INST&, const ENT_TYPE_INST&);

			/// Destructor.
			~EntityRelationTypeInstance();


			// TODO: get source entity type
			// TODO: get destination entity type
			// TODO: Set data !

			
	};


};
};
