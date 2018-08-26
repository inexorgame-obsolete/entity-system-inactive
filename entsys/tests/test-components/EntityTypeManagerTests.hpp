// Inexor entity system prototype
// Automatic software tests using Google Test
// (c)2018 Inexor

#pragma once

// Data validation.
#include "../../data-validation/DataValidation.cpp"

// Entity manager.
#include "../../entity-manager/EntityManager.cpp"

// Error handling.
#include "../../error-handling/ErrorHandling.cpp"

// Entity types.
#include "../../entity-manager/entity-types-manager/entity-type/EntityType.cpp"

// Entity attribute types.
#include "../../entity-manager/entity-attributes-manager/entity-attribute-type/EntityAttributeType.cpp"

// Entity types and instances of those.
#include "../../entity-manager/entity-types-manager\EntityTypeManager.cpp"
#include "../../entity-manager/entity-types-manager\EntityTypeInstanceManager.cpp"

// Entity attribute types and instances of those.
#include "../../entity-manager/entity-attributes-manager\EntityAttributeTypeManager.cpp"
#include "../../entity-manager/entity-attributes-manager\EntityAttributeTypeInstanceManager.cpp"

// Entity relation types and instances of those.
#include "../../entity-manager/entity-relations-manager\EntityRelationTypeManager.cpp"
#include "../../entity-manager/entity-relations-manager\EntityRelationTypeInstanceManager.cpp"

#include "../../EntitySystem.cpp"
using namespace inexor::entity_system;


// Thread-safe C++11 implementation of a singleton pattern for the entity system.
std::unique_ptr<EntitySystem> EntitySystem::instance;
std::once_flag EntitySystem::onceFlag;

// Create one instance of the entity system.
EntitySystem& entsys = EntitySystem::Instance();


// Testing class methods of entity type manager.

TEST(EntityTypeManagerTests, create_entity_type_1)
{
	std::shared_ptr<EntityType> new_ent_type = std::make_shared<EntityType>(std::string("rocketlauncher"));
	entsys.create_entity_type(new_ent_type);
	EXPECT_EQ(entsys.get_entity_types_count(), 1);
	entsys.reset_entity_system();
	EXPECT_EQ(entsys.get_entity_types_count(), 0);
	// Cleanup!
	entsys.reset_entity_system();
}

TEST(EntityTypeManagerTests, create_entity_type_2)
{
	std::shared_ptr<EntityType> new_ent_type = std::make_shared<EntityType>(std::string(""));
	// This will fail because the name of the entity type is invalid!
	entsys.create_entity_type(new_ent_type);
	EXPECT_EQ(entsys.get_entity_types_count(), 0);

	// Now set a valid name and try again.
	std::shared_ptr<EntityType> new_ent_type2 = std::make_shared<EntityType>(std::string("barrel"));
	entsys.create_entity_type(new_ent_type2);
	EXPECT_EQ(entsys.get_entity_types_count(), 1);

	// Now try to create an entity type which does already exist!
	// This will fail!
	entsys.create_entity_type(new_ent_type2);
	EXPECT_EQ(entsys.get_entity_types_count(), 1);
	
	// Now try to create an entity type which does already exist (again)!
	std::shared_ptr<EntityType> new_ent_type3 = std::make_shared<EntityType>(std::string("barrel"));
	// This will fail!
	entsys.create_entity_type(new_ent_type3);
	EXPECT_EQ(entsys.get_entity_types_count(), 1);

	// Cleanup!
	entsys.reset_entity_system();
}

TEST(EntityTypeManagerTests, reset_entity_system)
{
	std::shared_ptr<EntityType> new_ent_type = std::make_shared<EntityType>(std::string("banana"));
	entsys.create_entity_type(new_ent_type);
	EXPECT_EQ(entsys.get_entity_types_count(), 1);
	entsys.reset_entity_system();
	EXPECT_EQ(entsys.get_entity_types_count(), 0);
	// Cleanup!
	entsys.reset_entity_system();
}

TEST(EntityTypeManagerTests, does_entity_type_exist)
{
	std::shared_ptr<EntityType> new_ent_type = std::make_shared<EntityType>(std::string("quaddamage"));
	entsys.create_entity_type(new_ent_type);
	EXPECT_EQ(entsys.get_entity_types_count(), 1);
	bool does_banana_exist = entsys.does_entity_type_exist(std::string("banana"));
	EXPECT_EQ(does_banana_exist, false);
	bool does_quaddamage_exist = entsys.does_entity_type_exist(std::string("quaddamage"));
	EXPECT_EQ(does_quaddamage_exist, true);
	// Cleanup!
	entsys.reset_entity_system();
}

TEST(EntityTypeManagerTests, get_entity_types_count)
{
	std::shared_ptr<EntityType> new_ent_type = std::make_shared<EntityType>(std::string("shotgun"));
	entsys.create_entity_type(new_ent_type);
	EXPECT_EQ(entsys.get_entity_types_count(), 1);
	std::shared_ptr<EntityType> new_ent_type2 = std::make_shared<EntityType>(std::string("shotgunshells"));
	entsys.create_entity_type(new_ent_type2);
	EXPECT_EQ(entsys.get_entity_types_count(), 2);
	// Cleanup!
	entsys.reset_entity_system();
}

TEST(EntityTypeManagerTests, delete_entity_type_1)
{
	std::shared_ptr<EntityType> new_ent_type = std::make_shared<EntityType>(std::string("minigun"));
	entsys.create_entity_type(new_ent_type);
	EXPECT_EQ(entsys.get_entity_types_count(), 1);
	entsys.delete_entity_type("minigun");
	EXPECT_EQ(entsys.get_entity_types_count(), 0);
	// Cleanup!
	entsys.reset_entity_system();
}

TEST(EntityTypeManagerTests, delete_entity_type_2)
{
	std::shared_ptr<EntityType> new_ent_type = std::make_shared<EntityType>(std::string("minigun"));
	entsys.create_entity_type(new_ent_type);
	EXPECT_EQ(entsys.get_entity_types_count(), 1);
	entsys.delete_entity_type(new_ent_type);
	EXPECT_EQ(entsys.get_entity_types_count(), 0);
	// Cleanup!
	entsys.reset_entity_system();
}
