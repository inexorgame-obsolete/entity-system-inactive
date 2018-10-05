// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

#include "../EntitySystem.hpp"
#include "../../templates/TypeManagerTemplate.hpp"
#include "../../typedefs/TypeDefinitions.hpp"


// Testing class methods of entity type manager.

TEST(Test_EntityTypeManager, create_entity_type_1)
{
	ENT_TYPE new_ent_type = CREATE_ENT_TYPE("rocketlauncher");
	ASSERT_EQ(entsys->get_entity_types_count(), 1);

	entsys->reset_entity_system();
	ASSERT_EQ(entsys->get_entity_types_count(), 0);

	// Cleanup!
	entsys->reset_entity_system();
}


TEST(Test_EntityTypeManager, create_entity_type_2)
{
	// This will fail because the name of the entity type is invalid!
	ENT_TYPE new_ent_type = CREATE_ENT_TYPE("");
	ASSERT_EQ(entsys->get_entity_types_count(), 0);

	// Now set a valid name and try again.
	ENT_TYPE new_ent_type2 = CREATE_ENT_TYPE("barrel");
	ASSERT_EQ(entsys->get_entity_types_count(), 1);

	// Now try to create an entity type which does already exist!
	// This will fail!
	ASSERT_EQ(entsys->get_entity_types_count(), 1);
	
	// Now try to create an entity type which does already exist (again)!
	ENT_TYPE new_ent_type3 = CREATE_ENT_TYPE("barrel");

	// This will fail!
	ASSERT_EQ(entsys->get_entity_types_count(), 1);

	// Cleanup!
	entsys->reset_entity_system();
}


TEST(Test_EntityTypeManager, reset)
{
	ENT_TYPE new_ent_type = CREATE_ENT_TYPE("banana");
	ASSERT_EQ(entsys->get_entity_types_count(), 1);

	entsys->reset_entity_system();
	ASSERT_EQ(entsys->get_entity_types_count(), 0);

	// Cleanup!
	entsys->reset_entity_system();
}


TEST(Tests_EntityTypeManager, does_entity_type_exist)
{
	ENT_TYPE new_ent_type = CREATE_ENT_TYPE("quaddamage");
	ASSERT_EQ(entsys->get_entity_types_count(), 1);

	bool does_banana_exist = entsys->does_entity_type_exist("banana");
	ASSERT_EQ(does_banana_exist, false);

	bool does_quaddamage_exist = entsys->does_entity_type_exist("quaddamage");
	ASSERT_EQ(does_quaddamage_exist, true);

	// Cleanup!
	entsys->reset_entity_system();
}


TEST(Tests_EntityTypeManager, get_entity_types_count)
{
	ENT_TYPE new_ent_type = CREATE_ENT_TYPE("shotgun");
	ASSERT_EQ(entsys->get_entity_types_count(), 1);

	ENT_TYPE new_ent_type2 = CREATE_ENT_TYPE("shotgunshells");
	ASSERT_EQ(entsys->get_entity_types_count(), 2);

	// Cleanup!
	entsys->reset_entity_system();
}


TEST(Tests_EntityTypeManager, delete_entity_type_1)
{
	ENT_TYPE new_ent_type = CREATE_ENT_TYPE("minigun");
	ASSERT_EQ(entsys->get_entity_types_count(), 1);

	entsys->delete_entity_type("minigun");
	ASSERT_EQ(entsys->get_entity_types_count(), 0);

	// Cleanup!
	entsys->reset_entity_system();
}


TEST(Tests_EntityTypeManager, delete_entity_type_2)
{
	ENT_TYPE new_ent_type = CREATE_ENT_TYPE("minigun");
	ASSERT_EQ(entsys->get_entity_types_count(), 1);

	entsys->delete_entity_type(new_ent_type);
	ASSERT_EQ(entsys->get_entity_types_count(), 0);

	// Cleanup!
	entsys->reset_entity_system();
}
