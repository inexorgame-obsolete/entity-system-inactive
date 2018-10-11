// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once


TEST(Test_EntityTypeInstance, create_entity_attribute_type_instance)
{
	std::shared_ptr<EntityType> minigun = std::make_shared<EntityType>("minigun");

	std::shared_ptr<EntityAttributeType> weapon_dmg = std::make_shared<EntityAttributeType>("weapondamage", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_dmg);
	
	std::shared_ptr<EntityAttributeType> weapon_weight = std::make_shared<EntityAttributeType>("weight", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_weight);

	std::shared_ptr<EntityAttributeType> weapon_magazine_size = std::make_shared<EntityAttributeType>("ammosize", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_magazine_size);

	std::shared_ptr<EntityTypeInstance> minigunPickup1 = std::make_shared<EntityTypeInstance>(minigun);
	std::shared_ptr<EntityTypeInstance> minigunPickup2 = std::make_shared<EntityTypeInstance>(minigun);
	std::shared_ptr<EntityTypeInstance> minigunPickup3 = std::make_shared<EntityTypeInstance>(minigun);
	std::shared_ptr<EntityTypeInstance> minigunPickup4 = std::make_shared<EntityTypeInstance>(minigun);

	minigunPickup1->set_data(weapon_dmg, 166);

	// Cleanup!
	entsys->reset_entity_system();
}


TEST(Test_EntityTypeInstance, set_attribute_data)
{
	std::shared_ptr<EntityType> minigun = std::make_shared<EntityType>("minigun");

	// Create entity attribute types.
	std::shared_ptr<EntityAttributeType> weapon_dmg = std::make_shared<EntityAttributeType>("weapondamage", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_dmg);

	std::shared_ptr<EntityAttributeType> weapon_weight = std::make_shared<EntityAttributeType>("weight", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_weight);

	std::shared_ptr<EntityAttributeType> weapon_magazine_size = std::make_shared<EntityAttributeType>("ammosize", ENTSYS_DATA_TYPE_INT);
	minigun->link_attribute_type(weapon_magazine_size);

	// Create an instance
	std::shared_ptr<EntityTypeInstance> pickup1 = std::make_shared<EntityTypeInstance>(minigun);
	std::shared_ptr<EntityTypeInstance> pickup2 = std::make_shared<EntityTypeInstance>(minigun);
	std::shared_ptr<EntityTypeInstance> pickup3 = std::make_shared<EntityTypeInstance>(minigun);
	std::shared_ptr<EntityTypeInstance> pickup4 = std::make_shared<EntityTypeInstance>(minigun);

	const int dmg_val = 12;
	pickup1->set_data(weapon_dmg, dmg_val);
	int dmg_val_test = 0;
	pickup1->set_data(weapon_dmg, dmg_val_test);
	ASSERT_EQ(dmg_val_test, dmg_val);

	const int weight_val = 134;
	pickup1->set_data(weapon_weight, weight_val);
	int weight_val_test = 0;
	pickup1->set_data(weapon_weight, weight_val_test);
	ASSERT_EQ(weight_val_test, weight_val);

	const int magazine_size = 60;
	pickup1->set_data(weapon_magazine_size, magazine_size);
	int magazine_val_test = 0;
	pickup1->set_data(weapon_magazine_size, magazine_val_test);
	ASSERT_EQ(magazine_val_test, magazine_size);

	// Cleanup!
	entsys->reset_entity_system();
}
