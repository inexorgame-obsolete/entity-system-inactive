// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

#include "../../entity-manager/entity-attributes-manager/entity-attribute-type/EntityAttributeType.hpp"
using namespace inexor::entity_system;


TEST(Test_EntityAttributeType, get_entity_attribute_type_name)
{
	std::string ent_attr_name = "weight";
	ENTSYS_DATA_TYPE ent_attr_data_type = ENTSYS_DATA_TYPE_INT;
	ENT_ATTR_TYPE new_ent_attr1 = CREATE_ENT_ATTR_TYPE(ent_attr_name, ent_attr_data_type);

	ASSERT_EQ(new_ent_attr1->get_entity_attribute_type_name(), ent_attr_name);
	ASSERT_EQ(new_ent_attr1->get_entity_attribute_type_name(), "weight");

	// Cleanup!
	entsys->reset_entity_system();
}


TEST(Test_EntityAttributeType, get_entity_attribute_data_type)
{
	std::string ent_attr_name = "density";
	ENTSYS_DATA_TYPE ent_attr_data_type = ENTSYS_DATA_TYPE_BOOL;
	ENT_ATTR_TYPE new_ent_attr1 = CREATE_ENT_ATTR_TYPE(ent_attr_name, ent_attr_data_type);

	ASSERT_EQ(new_ent_attr1->get_entity_attribute_data_type(), ent_attr_data_type);
	ASSERT_EQ(new_ent_attr1->get_entity_attribute_data_type(), ENTSYS_DATA_TYPE_BOOL);

	// Cleanup!
	entsys->reset_entity_system();
}
