// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include "../../../model/relation-attributes/relation-attribute-instances/EntityRelationAttributeInstance.hpp"
#include "../../../model/relations/relation-types/EntityRelationType.hpp"
#include "../../../model/types/instances/EntityInstance.hpp"
#include "../../../model/base/instance/Instance.hpp"
#include "../../../util/type-definitions/TypeDefinitions.hpp"
#include "../../../util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for entity relation type instances.
	class EntityRelationInstance : public InstanceBase<EntityRelationType>, public GUIDBase
	{
		private:
		
			/// The source entity type instance.
			ENT_INST source_entity_type_instance;

			/// The target entity type instance.
			ENT_INST destination_entity_type_instance;
			
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

            /// 
			ENT_INST get_source_entity_instance() const;

            /// 
			ENT_INST get_target_entity_instance() const;

			// TODO: Set data !

			
	};


};
};
