// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityRelationAttributeTypeInstance.hpp"


namespace inexor {
namespace entity_system {


	EntityRelationAttributeTypeInstance::EntityRelationAttributeTypeInstance(const ENT_REL_ATTR_TYPE& ent_rel_attr_type)
		: DataContainer(ent_rel_attr_type->get_type_name())
	{
	}


	EntityRelationAttributeTypeInstance::~EntityRelationAttributeTypeInstance()
	{
		// TODO: Implement!
	}


};
};
