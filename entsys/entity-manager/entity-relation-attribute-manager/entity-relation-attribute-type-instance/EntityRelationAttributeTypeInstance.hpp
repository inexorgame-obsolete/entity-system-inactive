// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"
#include "../../../data-container/DataContainer.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	// A base class for instances of entity relation attribute types.
	class EntityRelationAttributeTypeInstance :
		public TypeInstanceBase<EntityRelationAttributeType,EntityRelationAttributeTypeInstance>,
		public DataContainer
	{
		public:

			// 
			EntityRelationAttributeTypeInstance(const ENT_REL_ATTR_TYPE&);

			// 
			~EntityRelationAttributeTypeInstance();

	};

};
};
