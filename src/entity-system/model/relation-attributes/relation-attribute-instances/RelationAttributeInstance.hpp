// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include "entity-system/model/relation-attributes/relation-attribute-types/RelationAttributeType.hpp"
#include "entity-system/model/base/instance/Instance.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for relation attribute type instances
	class RelationAttributeInstance : public InstanceBase<RelationAttributeType>, public DataContainer, public GUIDBase
	{
		public:

			/// Constructor.
			/// @param rel_attr_type A const reference to a shared pointer of
			/// an relation attribute type of which an instance will be created.
			/// @note the GUID of the new relation attribute type instance will
			/// be created automatically by the inheritance of GUIDBase!
			RelationAttributeInstance(const REL_ATTR_TYPE&);

			/// Destructor.
			~RelationAttributeInstance();
			

	};

};
};
