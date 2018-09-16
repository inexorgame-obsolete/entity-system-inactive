// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

// Instances of types of attributes of entities.
#include "../../entity-manager/entity-attributes-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.cpp"
using namespace inexor::entity_system;


TEST(TODO1, TODO2)
{
	std::string ent_attr_name = std::string("density");
	ENTSYS_DATA_TYPE ent_attr_data_type = ENTSYS_DATA_TYPE_FLOAT;
	std::shared_ptr<EntityAttributeType> new_ent_attr1 = std::make_shared<EntityAttributeType>(ent_attr_name, ent_attr_data_type);
	EXPECT_EQ(new_ent_attr1->get_entity_attribute_type_name(), ent_attr_name);
	EXPECT_EQ(new_ent_attr1->get_entity_attribute_type_name(), std::string("density"));

	std::shared_ptr<EntityAttributeTypeInstance> new_ent_attr1_inst = std::make_shared<EntityAttributeTypeInstance>(new_ent_attr1);
	EXPECT_EQ(new_ent_attr1_inst->get_entity_attribute_data_type(), ent_attr_data_type);
	EXPECT_EQ(new_ent_attr1_inst->get_entity_attribute_type_name(), ent_attr_name);
}
