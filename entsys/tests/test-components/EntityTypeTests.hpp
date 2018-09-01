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
	std::shared_ptr<EntityType> new_ent1 = std::make_shared<EntityType>(ent_name);
	EXPECT_EQ(new_ent1->get_type_name(), ent_name);
}

TEST(EntityTypeTests, link_entity_attribute_type_to_entity_type)
{
	std::shared_ptr<EntityType> weap1 = std::make_shared<EntityType>("rocketlauncher");

	std::shared_ptr<EntityAttributeType> attr1 = std::make_shared<EntityAttributeType>("damage");
	weap1->link_attribute_type(attr1);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 1);

	std::shared_ptr<EntityAttributeType> attr2 = std::make_shared<EntityAttributeType>("weight");
	weap1->link_attribute_type(attr2);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 2);

	std::shared_ptr<EntityAttributeType> attr3 = std::make_shared<EntityAttributeType>("color");
	weap1->link_attribute_type(attr3);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 3);

	std::shared_ptr<EntityAttributeType> attr4 = std::make_shared<EntityAttributeType>("reloadtime");
	weap1->link_attribute_type(attr4);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 4);
}

TEST(EntityTypeTests, has_attribute_type)
{
	std::shared_ptr<EntityType> weap1 = std::make_shared<EntityType>("rocketlauncher");

	std::shared_ptr<EntityAttributeType> attr1 = std::make_shared<EntityAttributeType>("damage");
	weap1->link_attribute_type(attr1);
	EXPECT_EQ(weap1->has_attribute_type("damage"), true);
	EXPECT_EQ(weap1->has_attribute_type(attr1), true);

	std::shared_ptr<EntityAttributeType> attr2 = std::make_shared<EntityAttributeType>("weight");
	weap1->link_attribute_type(attr2);
	EXPECT_EQ(weap1->has_attribute_type("weight"), true);
	EXPECT_EQ(weap1->has_attribute_type(attr2), true);

	std::shared_ptr<EntityAttributeType> attr3 = std::make_shared<EntityAttributeType>("color");
	weap1->link_attribute_type(attr3);
	EXPECT_EQ(weap1->has_attribute_type("color"), true);
	EXPECT_EQ(weap1->has_attribute_type(attr3), true);

	std::shared_ptr<EntityAttributeType> attr4 = std::make_shared<EntityAttributeType>("reloadtime");
	weap1->link_attribute_type(attr4);
	EXPECT_EQ(weap1->has_attribute_type("reloadtime"), true);
	EXPECT_EQ(weap1->has_attribute_type(attr4), true);
}

TEST(EntityTypeTests, reset_linked_attribute_types)
{
	std::shared_ptr<EntityType> weap1 = std::make_shared<EntityType>("rocketlauncher");

	std::shared_ptr<EntityAttributeType> attr1 = std::make_shared<EntityAttributeType>("damage");
	weap1->link_attribute_type(attr1);

	std::shared_ptr<EntityAttributeType> attr2 = std::make_shared<EntityAttributeType>("weight");
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
	std::shared_ptr<EntityType> weap1 = std::make_shared<EntityType>("rocketlauncher");

	std::shared_ptr<EntityAttributeType> attr1 = std::make_shared<EntityAttributeType>("damage");
	weap1->link_attribute_type(attr1);

	std::shared_ptr<EntityAttributeType> attr2 = std::make_shared<EntityAttributeType>("weight");
	weap1->link_attribute_type(attr2);

	EXPECT_EQ(weap1->has_attribute_type("damage"), true);
	EXPECT_EQ(weap1->has_attribute_type("weight"), true);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 2);

	weap1->reset_linked_attribute_types();
	
	EXPECT_EQ(weap1->has_attribute_type("damage"), false);
	EXPECT_EQ(weap1->has_attribute_type("weight"), false);
	EXPECT_EQ(weap1->get_linked_attributes_count(), 0);
}

