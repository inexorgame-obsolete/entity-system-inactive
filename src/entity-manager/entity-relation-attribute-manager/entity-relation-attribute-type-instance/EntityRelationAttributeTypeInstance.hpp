// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"
#include "../../../data-container/DataContainer.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for instances of entity relation attribute types.
	class EntityRelationAttributeTypeInstance :
		public TypeInstanceBase<EntityRelationAttributeType,EntityRelationAttributeTypeInstance>,
		public DataContainer
	{
		public:

			/// Constructor.
			/// @param ent_rel_attr_type A reference to a shared pointer of
			/// an entity relation attribute type of which an instance will be created.
			/// @return A shared pointer to the entity relation attribute type instance which was created.
			/// TODO: entity_relation_attribute_type_instance_ERROR.
			EntityRelationAttributeTypeInstance(const ENT_REL_ATTR_TYPE&);

			/// Destructor.
			~EntityRelationAttributeTypeInstance();

	};

};
};
