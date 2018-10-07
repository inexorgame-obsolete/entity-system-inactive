// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

#include "../../typedefs/TypeDefinitions.hpp"
using namespace inexor::entity_system;


TEST(Test_EntityType, get_type_name)
{
	std::string ent_name = "grenade";
	std::shared_ptr<EntityType> new_ent1 = std::make_shared<EntityType>(ent_name);
	ASSERT_EQ(new_ent1->get_type_name(), ent_name);

	// Cleanup!
	entsys->reset_entity_system();
}


TEST(Tests_EntityType, link_attribute_type)
{
	std::shared_ptr<EntityType> weap1 = std::make_shared<EntityType>("rocketlauncher");

	std::shared_ptr<EntityAttributeType> attr1 = std::make_shared<EntityAttributeType>("damage", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr1);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 1);

	std::shared_ptr<EntityAttributeType> attr2 = std::make_shared<EntityAttributeType>("weight", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr2);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 2);

	std::shared_ptr<EntityAttributeType> attr3 = std::make_shared<EntityAttributeType>("color", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr3);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 3);

	std::shared_ptr<EntityAttributeType> attr4 = std::make_shared<EntityAttributeType>("reloadtime", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr4);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 4);

	// Cleanup!
	entsys->reset_entity_system();
}


TEST(Tests_EntityType, has_attribute_type)
{
	std::shared_ptr<EntityType> weap1 = std::make_shared<EntityType>("rocketlauncher");

	std::shared_ptr<EntityAttributeType> attr1 = std::make_shared<EntityAttributeType>("damage", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr1);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 1);
	// Check by using both overloaded has_attribute_type methods.
	ASSERT_EQ(weap1->has_attribute_type("damage"), true);
	ASSERT_EQ(weap1->has_attribute_type(attr1), true);

	std::shared_ptr<EntityAttributeType> attr2 = std::make_shared<EntityAttributeType>("weight", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr2);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 2);
	// Check by using both overloaded has_attribute_type methods.
	ASSERT_EQ(weap1->has_attribute_type("weight"), true);
	ASSERT_EQ(weap1->has_attribute_type(attr2), true);

	std::shared_ptr<EntityAttributeType> attr3 = std::make_shared<EntityAttributeType>("color", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr3);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 3);
	// Check by using both overloaded has_attribute_type methods.
	ASSERT_EQ(weap1->has_attribute_type("color"), true);
	ASSERT_EQ(weap1->has_attribute_type(attr3), true);

	std::shared_ptr<EntityAttributeType> attr4 = std::make_shared<EntityAttributeType>("reloadtime", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr4);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 4);
	// Check by using both overloaded has_attribute_type methods.
	ASSERT_EQ(weap1->has_attribute_type("reloadtime"), true);
	ASSERT_EQ(weap1->has_attribute_type(attr4), true);

	// Cleanup!
	entsys->reset_entity_system();
}


TEST(Tests_EntityType, reset_linked_attribute_types)
{
	std::shared_ptr<EntityType> weap1 = std::make_shared<EntityType>("rocketlauncher");

	std::shared_ptr<EntityAttributeType> attr1 = std::make_shared<EntityAttributeType>("damage", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr1);
	ASSERT_EQ(weap1->has_attribute_type("damage"), true);
	ASSERT_EQ(weap1->has_attribute_type(attr1), true);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 1);

	std::shared_ptr<EntityAttributeType> attr2 = std::make_shared<EntityAttributeType>("weight", ENTSYS_DATA_TYPE_FLOAT);
	weap1->link_attribute_type(attr2);
	ASSERT_EQ(weap1->has_attribute_type("damage"), true);
	ASSERT_EQ(weap1->has_attribute_type(attr1), true);
	ASSERT_EQ(weap1->has_attribute_type("weight"), true);
	ASSERT_EQ(weap1->has_attribute_type(attr2), true);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 2);

	// Reset all linked types of attributes!
	weap1->reset_linked_attribute_types();
	
	ASSERT_EQ(weap1->has_attribute_type("damage"), false);
	ASSERT_EQ(weap1->has_attribute_type("weight"), false);
	ASSERT_EQ(weap1->has_attribute_type(attr1), false);
	ASSERT_EQ(weap1->has_attribute_type(attr2), false);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 0);

	// Cleanup!
	entsys->reset_entity_system();
}


TEST(Tests_EntityType, get_linked_attributes_count)
{
	std::shared_ptr<EntityType> weap1 = std::make_shared<EntityType>("rocketlauncher");

	std::shared_ptr<EntityAttributeType> attr1 = std::make_shared<EntityAttributeType>("damage", ENTSYS_DATA_TYPE_FLOAT);
	std::shared_ptr<EntityAttributeType> attr2 = std::make_shared<EntityAttributeType>("weight", ENTSYS_DATA_TYPE_FLOAT);

	weap1->link_attribute_type(attr1);
	ASSERT_EQ(weap1->has_attribute_type("damage"), true);
	ASSERT_EQ(weap1->has_attribute_type(attr1), true);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 1);
	
	weap1->link_attribute_type(attr2);
	ASSERT_EQ(weap1->has_attribute_type("damage"), true);
	ASSERT_EQ(weap1->has_attribute_type(attr1), true);
	ASSERT_EQ(weap1->has_attribute_type("weight"), true);
	ASSERT_EQ(weap1->has_attribute_type(attr2), true);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 2);

	// Reset linked types of attributes!
	weap1->reset_linked_attribute_types();
	
	ASSERT_EQ(weap1->has_attribute_type("damage"), false);
	ASSERT_EQ(weap1->has_attribute_type(attr1), false);
	ASSERT_EQ(weap1->has_attribute_type("weight"), false);
	ASSERT_EQ(weap1->has_attribute_type(attr2), false);
	ASSERT_EQ(weap1->get_linked_attributes_count(), 0);

	// Cleanup!
	entsys->reset_entity_system();
}
