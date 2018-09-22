// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once


TEST(EntityTypeInstanceTests, TODO)
{
	// Create an entity type (weapon) called minigun.
	ENT_TYPE minigun = CREATE_ENT_TYPE("minigun");

	// Create entity attribute types.
	ENT_ATTR_TYPE weapon_dmg = CREATE_ENT_ATTR_TYPE("weapondamage", ENTSYS_DATA_TYPE_FLOAT);
	minigun->link_attribute_type(weapon_dmg);
	ENT_ATTR_TYPE weapon_weight = CREATE_ENT_ATTR_TYPE("weight", ENTSYS_DATA_TYPE_FLOAT);
	minigun->link_attribute_type(weapon_weight);
	ENT_ATTR_TYPE weapon_magazine_size = CREATE_ENT_ATTR_TYPE("ammosize", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_magazine_size);

	// Create an instance!
	ENT_TYPE_INSTANCE pickup1 = CREATE_ENT_TYPE_INSTANCE(minigun);
	ENT_TYPE_INSTANCE pickup2 = CREATE_ENT_TYPE_INSTANCE(minigun);
	ENT_TYPE_INSTANCE pickup3 = CREATE_ENT_TYPE_INSTANCE(minigun);
	ENT_TYPE_INSTANCE pickup4 = CREATE_ENT_TYPE_INSTANCE(minigun);

	pickup1->set_attribute_data(weapon_dmg, 35);
}
