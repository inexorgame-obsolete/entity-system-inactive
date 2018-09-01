// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

// Types of attributes of entities.
#include "../../entity-manager/entity-attributes-manager/entity-attribute-type/EntityAttributeType.hpp"
using namespace inexor::entity_system;


TEST(EntityAttributeTypeTests, get_entity_attribute_type_name)
{
	std::string ent_attr_name = std::string("weight");
	ENTSYS_DATA_TYPE ent_attr_data_type = ENTSYS_DATA_TYPE_INT;
	std::shared_ptr<EntityAttributeType> new_ent_attr1 = std::make_unique<EntityAttributeType>(ent_attr_name, ent_attr_data_type);
	EXPECT_EQ(new_ent_attr1->get_entity_attribute_type_name(), ent_attr_name);
	EXPECT_EQ(new_ent_attr1->get_entity_attribute_type_name(), std::string("weight"));
}

TEST(EntityAttributeTypeTests, get_entity_attribute_data_type)
{
	std::string ent_attr_name = std::string("density");
	ENTSYS_DATA_TYPE ent_attr_data_type = ENTSYS_DATA_TYPE_BOOL;
	std::shared_ptr<EntityAttributeType> new_ent_attr1 = std::make_unique<EntityAttributeType>(ent_attr_name, ent_attr_data_type);
	EXPECT_EQ(new_ent_attr1->get_entity_attribute_data_type(), ent_attr_data_type);
	EXPECT_EQ(new_ent_attr1->get_entity_attribute_data_type(), ENTSYS_DATA_TYPE_BOOL);
}
