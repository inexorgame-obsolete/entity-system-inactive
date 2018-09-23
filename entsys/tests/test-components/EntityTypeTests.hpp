// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

#include "../../typedefs/TypeDefinitions.hpp"
using namespace inexor::entity_system;


TEST(Test_EntityType, get_type_name)
{
	std::string ent_name = "grenade";
	ENT_TYPE new_ent1 = CREATE_ENT_TYPE(ent_name);
	EXPECT_EQ(new_ent1->get_type_name(), ent_name);
}


TEST(Tests_EntityType, link_attribute_type)
{
	ENT_TYPE weap1 = CREATE_ENT_TYPE("rocketlauncher");

	ENT_ATTR_TYPE attr1 = CREATE_ENT_ATTR_TYPE("damage", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr1);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 1);

	ENT_ATTR_TYPE attr2 = CREATE_ENT_ATTR_TYPE("weight", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr2);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 2);

	ENT_ATTR_TYPE attr3 = CREATE_ENT_ATTR_TYPE("color", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr3);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 3);

	ENT_ATTR_TYPE attr4 = CREATE_ENT_ATTR_TYPE("reloadtime", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr4);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 4);
}


TEST(Tests_EntityType, has_attribute_type)
{
	ENT_TYPE weap1 = CREATE_ENT_TYPE("rocketlauncher");

	ENT_ATTR_TYPE attr1 = CREATE_ENT_ATTR_TYPE("damage", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr1);
	EXPECT_EQ(weap1->has_attribute_type("damage"), true);
	EXPECT_EQ(weap1->has_attribute_type(attr1), true);

	ENT_ATTR_TYPE attr2 = CREATE_ENT_ATTR_TYPE("weight", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr2);
	EXPECT_EQ(weap1->has_attribute_type("weight"), true);
	EXPECT_EQ(weap1->has_attribute_type(attr2), true);

	ENT_ATTR_TYPE attr3 = CREATE_ENT_ATTR_TYPE("color", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr3);
	EXPECT_EQ(weap1->has_attribute_type("color"), true);
	EXPECT_EQ(weap1->has_attribute_type(attr3), true);

	ENT_ATTR_TYPE attr4 = CREATE_ENT_ATTR_TYPE("reloadtime", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr4);
	EXPECT_EQ(weap1->has_attribute_type("reloadtime"), true);
	EXPECT_EQ(weap1->has_attribute_type(attr4), true);
}


TEST(Tests_EntityType, reset_linked_attribute_types)
{
	ENT_TYPE weap1 = CREATE_ENT_TYPE("rocketlauncher");

	ENT_ATTR_TYPE attr1 = CREATE_ENT_ATTR_TYPE("damage", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr1);

	EXPECT_EQ(weap1->has_attribute_type("damage"), true);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 1);

	ENT_ATTR_TYPE attr2 = CREATE_ENT_ATTR_TYPE("weight", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr2);

	EXPECT_EQ(weap1->has_attribute_type("damage"), true);
	EXPECT_EQ(weap1->has_attribute_type("weight"), true);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 2);

	// Reset all linked types of attributes!
	weap1->reset_linked_attribute_types();
	
	EXPECT_EQ(weap1->has_attribute_type("damage"), false);
	EXPECT_EQ(weap1->has_attribute_type("weight"), false);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 0);
}


TEST(Tests_EntityType, get_linked_attributes_count)
{
	ENT_TYPE weap1 = CREATE_ENT_TYPE("rocketlauncher");

	ENT_ATTR_TYPE attr1 = CREATE_ENT_ATTR_TYPE("damage", ENTSYS_DATA_TYPE_FLOAT);
	ENT_ATTR_TYPE attr2 = CREATE_ENT_ATTR_TYPE("weight", ENTSYS_DATA_TYPE_FLOAT);

	weap1->link_attribute_type(attr1);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 1);
	weap1->link_attribute_type(attr2);

	EXPECT_EQ(weap1->has_attribute_type("damage"), true);
	EXPECT_EQ(weap1->has_attribute_type("weight"), true);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 2);

	// Reset linked types of attributes!
	weap1->reset_linked_attribute_types();
	
	EXPECT_EQ(weap1->has_attribute_type("damage"), false);
	EXPECT_EQ(weap1->has_attribute_type("weight"), false);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 0);
}
