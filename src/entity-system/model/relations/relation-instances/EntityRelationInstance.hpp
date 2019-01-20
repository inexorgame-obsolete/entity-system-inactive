// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include "entity-system/model/relation-attributes/relation-attribute-instances/EntityRelationAttributeInstance.hpp"
#include "entity-system/model/relations/relation-types/EntityRelationType.hpp"
#include "entity-system/model/types/instances/EntityInstance.hpp"
#include "entity-system/model/base/instance/Instance.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for entity relation type instances.
	class EntityRelationInstance : public InstanceBase<EntityRelationType>, public GUIDBase
	{
		private:

			/// The relation type
			// TODO: ENT_REL_TYPE relation_type;

			/// The source entity type instance.
			ENT_INST source_entity_instance;

			/// The target entity type instance.
			ENT_INST destination_entity_instance;
			
			/// Entity relation attribute type instances stored by entity relation attribute types.
			std::unordered_map<ENT_REL_ATTR_TYPE, ENT_REL_ATTR_INST> relation_attribute_instances;

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
			EntityRelationInstance(const ENT_REL_TYPE&, const ENT_INST&, const ENT_INST&);

			/// Destructor.
			~EntityRelationInstance();

			/// Returns all entity relation attribute instances.
			/// @return A std::unordered_map of shared pointers of entity relation attribute type.
			std::unordered_map<ENT_REL_ATTR_TYPE, ENT_REL_ATTR_INST> get_relation_attribute_instances() const;

            /// 
			// TODO: ENT_REL_TYPE get_relation_type() const;

            ///
			ENT_INST get_source_entity_instance() const;

            /// 
			ENT_INST get_target_entity_instance() const;

			// TODO: Set data !

			
	};


};
};
