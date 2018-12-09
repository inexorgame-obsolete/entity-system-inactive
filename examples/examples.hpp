// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "EntitySystem.hpp"
using namespace inexor::entity_system;

// Create macros to make definitions short and easy.
#include "typedefs/CreateMacros.hpp"

using namespace std;

void example_setup(const std::string msg)
{
	cout << endl << endl << "----------------------------------------" << endl;
	cout << "EXAMPLE: " << msg << endl << endl;
}


/// 
void example_player()
{
	example_setup("player");

	ENT_TYPE player = CREATE_ENT_TYPE("player");
	ENT_ATTR_TYPE nickname = CREATE_ENT_ATTR_TYPE("nickname", ENTSYS_DATA_TYPE_STRING);

	// TODO: Implement builder pattern!
	player->link_attribute_type(nickname);

	ENT_TYPE_INST one = CREATE_ENT_TYPE_INST(player);
	one->set_data(nickname, "Hanni");

	ENT_TYPE_INST two = CREATE_ENT_TYPE_INST(player);
	one->set_data(nickname, "Hanack");

	ENT_TYPE_INST three = CREATE_ENT_TYPE_INST(player);
	one->set_data(nickname, "Fohlen");

	// How many players (entity type instances) do we have?
	cout << "We have " << entsys->get_entity_type_instance_count() << " players." << endl;

	// Cleanup!
	entsys->reset_entity_system();
}


/// 
void example_weapon()
{
	example_setup("weapon");
	cout << "There should not exist entity types yet, right?" << endl;
	cout << "Number of existing entity types: " << entsys->get_entity_types_count() << endl;

	cout << "Creating an entity of type pistol" << endl;
	ENT_TYPE weapon_type = CREATE_ENT_TYPE("weapon");

	cout << "Number of existing entity types " << entsys->get_entity_types_count() << endl;

	cout << "Now lets create some attributes" << endl;

	ENT_ATTR_TYPE dmg = CREATE_ENT_ATTR_TYPE("damage", ENTSYS_DATA_TYPE_INT);
	weapon_type->link_attribute_type(dmg);

	cout << "Number of existing entity attribute types " << entsys->get_entity_attribute_type_count() << endl;

	ENT_ATTR_TYPE ammosize = CREATE_ENT_ATTR_TYPE("ammosize", ENTSYS_DATA_TYPE_INT);
	weapon_type->link_attribute_type(ammosize);

	ENT_ATTR_TYPE silenced = CREATE_ENT_ATTR_TYPE("silencer", ENTSYS_DATA_TYPE_BOOL);
	weapon_type->link_attribute_type(silenced);

	cout << "Number of existing entity attribute types:" << entsys->get_entity_attribute_type_count() << endl;
	cout << "Lets create instances!" << endl;

	ENT_TYPE_INST pistol = CREATE_ENT_TYPE_INST(weapon_type);

	cout << "Number of existing entity type instances: " << entsys->get_entity_type_instance_count() << endl;
	cout << "Lets set the data of the pistol" << endl;

	bool isSilenced = false;
	pistol->set_data(silenced, true);
	pistol->get_data(silenced, isSilenced);
	cout << "Lets see if it worked: " << isSilenced << endl;

	pistol->set_data(silenced, false);
	pistol->get_data(silenced, isSilenced);
	cout << "Lets see if it worked: " << isSilenced << endl;

	// Cleanup!
	entsys->reset_entity_system();
}


void run_entsys_examples()
{
	example_player();
	example_weapon();
	// TODO: Add more examples here.
	
	// Cleanup!
	entsys->reset_entity_system();
}