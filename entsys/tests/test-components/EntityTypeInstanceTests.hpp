// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once


TEST(Test_EntityTypeInstance, create_entity_attribute_type_instance)
{
	// Create an entity type (weapon) called minigun.
	ENT_TYPE minigun = CREATE_ENT_TYPE("minigun");

	// Create entity attribute types.
	ENT_ATTR_TYPE weapon_dmg = CREATE_ENT_ATTR_TYPE("weapondamage", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_dmg);
	
	ENT_ATTR_TYPE weapon_weight = CREATE_ENT_ATTR_TYPE("weight", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_weight);

	ENT_ATTR_TYPE weapon_magazine_size = CREATE_ENT_ATTR_TYPE("ammosize", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_magazine_size);

	// Create an instance!
	ENT_TYPE_INSTANCE pickup1 = CREATE_ENT_TYPE_INSTANCE(minigun);
	ENT_TYPE_INSTANCE pickup2 = CREATE_ENT_TYPE_INSTANCE(minigun);
	ENT_TYPE_INSTANCE pickup3 = CREATE_ENT_TYPE_INSTANCE(minigun);
	ENT_TYPE_INSTANCE pickup4 = CREATE_ENT_TYPE_INSTANCE(minigun);

	// Cleanup!
	entsys->reset();
}


TEST(Test_EntityTypeInstance, set_attribute_data)
{
	// Create an entity type (weapon) called minigun.
	ENT_TYPE minigun = CREATE_ENT_TYPE("minigun");

	// Create entity attribute types.
	ENT_ATTR_TYPE weapon_dmg = CREATE_ENT_ATTR_TYPE("weapondamage", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_dmg);

	ENT_ATTR_TYPE weapon_weight = CREATE_ENT_ATTR_TYPE("weight", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_weight);

	ENT_ATTR_TYPE weapon_magazine_size = CREATE_ENT_ATTR_TYPE("ammosize", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_magazine_size);

	// Create an instance!
	ENT_TYPE_INSTANCE pickup1 = CREATE_ENT_TYPE_INSTANCE(minigun);
	ENT_TYPE_INSTANCE pickup2 = CREATE_ENT_TYPE_INSTANCE(minigun);
	ENT_TYPE_INSTANCE pickup3 = CREATE_ENT_TYPE_INSTANCE(minigun);
	ENT_TYPE_INSTANCE pickup4 = CREATE_ENT_TYPE_INSTANCE(minigun);

	const int dmg_val = 12;
	pickup1->set_attribute_data(weapon_dmg, dmg_val);
	ASSERT_EQ(pickup1->get_attribute_data_int(weapon_dmg), dmg_val);

	const int weight_val = 134;
	pickup1->set_attribute_data(weapon_weight, weight_val);
	ASSERT_EQ(pickup1->get_attribute_data_int(weapon_weight), weight_val);

	const int magazine_size = 60;
	pickup1->set_attribute_data(weapon_magazine_size, magazine_size);
	ASSERT_EQ(pickup1->get_attribute_data_int(weapon_magazine_size), magazine_size);
}
