// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include "../../../model/relation-attributes/relation-attribute-instances/EntityRelationAttributeInstance.hpp"
#include "../../../model/relation-attributes/relation-attribute-types/EntityRelationAttributeType.hpp"
#include "../../../model/data/container/DataContainer.hpp"
#include "../../../model/base/instance/Instance.hpp"
#include "../../../util/type-definitions/TypeDefinitions.hpp"
#include "../../../util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for entity relation attribute type instances
	class EntityRelationAttributeInstance : public InstanceBase<EntityRelationAttributeType>, public DataContainer, public GUIDBase
	{
		public:

			/// Constructor.
			/// @param ent_rel_attr_type A const reference to a shared pointer of
			/// an entity relation attribute type of which an instance will be created.
			/// @note the GUID of the new entity relation attribute type instance will
			/// be created automatically by the inheritance of GUIDBase!
			EntityRelationAttributeInstance(const ENT_REL_ATTR_TYPE&);

			/// Destructor.
			~EntityRelationAttributeInstance();
			

	};

};
};
