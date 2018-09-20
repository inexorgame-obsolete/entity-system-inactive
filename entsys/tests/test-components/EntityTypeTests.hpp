// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

// Types of entities.
#include "../../entity-manager/entity-types-manager/entity-type/EntityType.hpp"
using namespace inexor::entity_system;


TEST(EntityTypeTests, get_type_name)
{
	std::string ent_name = std::string("grenade");
	ENT_TYPE new_ent1 = std::make_shared<EntityType>(ent_name);
	EXPECT_EQ(new_ent1->get_type_name(), ent_name);
}

TEST(EntityTypeTests, link_entity_attribute_type_to_entity_type)
{
	ENT_TYPE weap1 = std::make_shared<EntityType>("rocketlauncher");

	ENT_ATTR_TYPE attr1 = std::make_shared<EntityAttributeType>("damage");
	weap1->link_attribute_type(attr1);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 1);

	ENT_ATTR_TYPE attr2 = std::make_shared<EntityAttributeType>("weight");
	weap1->link_attribute_type(attr2);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 2);

	ENT_ATTR_TYPE attr3 = std::make_shared<EntityAttributeType>("color");
	weap1->link_attribute_type(attr3);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 3);

	ENT_ATTR_TYPE attr4 = std::make_shared<EntityAttributeType>("reloadtime");
	weap1->link_attribute_type(attr4);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 4);
}

TEST(EntityTypeTests, has_attribute_type)
{
	ENT_TYPE weap1 = std::make_shared<EntityType>("rocketlauncher");

	ENT_ATTR_TYPE attr1 = std::make_shared<EntityAttributeType>("damage");
	weap1->link_attribute_type(attr1);
	EXPECT_EQ(weap1->has_attribute_type("damage"), true);
	EXPECT_EQ(weap1->has_attribute_type(attr1), true);

	ENT_ATTR_TYPE attr2 = std::make_shared<EntityAttributeType>("weight");
	weap1->link_attribute_type(attr2);
	EXPECT_EQ(weap1->has_attribute_type("weight"), true);
	EXPECT_EQ(weap1->has_attribute_type(attr2), true);

	ENT_ATTR_TYPE attr3 = std::make_shared<EntityAttributeType>("color");
	weap1->link_attribute_type(attr3);
	EXPECT_EQ(weap1->has_attribute_type("color"), true);
	EXPECT_EQ(weap1->has_attribute_type(attr3), true);

	ENT_ATTR_TYPE attr4 = std::make_shared<EntityAttributeType>("reloadtime");
	weap1->link_attribute_type(attr4);
	EXPECT_EQ(weap1->has_attribute_type("reloadtime"), true);
	EXPECT_EQ(weap1->has_attribute_type(attr4), true);
}

TEST(EntityTypeTests, reset_linked_attribute_types)
{
	ENT_TYPE weap1 = std::make_shared<EntityType>("rocketlauncher");

	ENT_ATTR_TYPE attr1 = std::make_shared<EntityAttributeType>("damage");
	weap1->link_attribute_type(attr1);

	ENT_ATTR_TYPE attr2 = std::make_shared<EntityAttributeType>("weight");
	weap1->link_attribute_type(attr2);

	EXPECT_EQ(weap1->has_attribute_type("damage"), true);
	EXPECT_EQ(weap1->has_attribute_type("weight"), true);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 2);

	weap1->reset_linked_attribute_types();
	
	EXPECT_EQ(weap1->has_attribute_type("damage"), false);
	EXPECT_EQ(weap1->has_attribute_type("weight"), false);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 0);
}

TEST(EntityTypeTests, get_linked_attributes_count)
{
	ENT_TYPE weap1 = std::make_shared<EntityType>("rocketlauncher");

	ENT_ATTR_TYPE attr1 = std::make_shared<EntityAttributeType>("damage");
	weap1->link_attribute_type(attr1);

	ENT_ATTR_TYPE attr2 = std::make_shared<EntityAttributeType>("weight");
	weap1->link_attribute_type(attr2);

	EXPECT_EQ(weap1->has_attribute_type("damage"), true);
	EXPECT_EQ(weap1->has_attribute_type("weight"), true);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 2);

	weap1->reset_linked_attribute_types();
	
	EXPECT_EQ(weap1->has_attribute_type("damage"), false);
	EXPECT_EQ(weap1->has_attribute_type("weight"), false);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 0);
}
