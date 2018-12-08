// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"
#include "../../../data-container/DataContainer.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"
#include "base-classes/GUID/GUIDBase.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for entity relation attribute type instances
	class EntityRelationAttributeTypeInstance :
		public TypeInstanceBase<EntityRelationAttributeType,EntityRelationAttributeTypeInstance>,
		public DataContainer,
		public GUIDBase
	{
		public:

			/// Constructor.
			/// @param ent_rel_attr_type A const reference to a shared pointer of
			/// an entity relation attribute type of which an instance will be created.
			/// @note the GUID of the new entity relation attribute type instance will
			/// be created automatically by the inheritance of GUIDBase!
			EntityRelationAttributeTypeInstance(const ENT_REL_ATTR_TYPE&);

			/// Destructor.
			~EntityRelationAttributeTypeInstance();

	};

};
};
