// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityRelationAttributeTypeInstance.hpp"


namespace inexor {
namespace entity_system {


	EntityRelationAttributeTypeInstance::EntityRelationAttributeTypeInstance(const ENT_REL_ATTR_TYPE& ent_rel_attr_type)
		: DataContainer(ent_rel_attr_type->get_attribute_data_type()),
		TypeInstanceBase(ent_rel_attr_type)
	{
		// TODO: Implement!
	}


	EntityRelationAttributeTypeInstance::~EntityRelationAttributeTypeInstance()
	{
		// TODO: Implement!
	}


};
};
