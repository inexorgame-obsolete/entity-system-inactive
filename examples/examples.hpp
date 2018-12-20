// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "EntitySystem.hpp"
using namespace inexor::entity_system;

// Create macros to make definitions short and easy.
#include "macros/Macros.hpp"
using namespace std;



// The number of the code example.
int example_number = 1;

/// This message will be printed before a code example starts.
void code_example_setup(const std::string& example_name)
{
	cout << endl << endl;
	cout << "Running example #" << example_number << ": " << example_name << endl;
	cout << "-------------------------------------------" << endl;

	// Increase code example number.
	example_number++;
}


/// In this example we will create some fruits as simple examples
/// for entity types. There will be no instances of any kind in this
/// example.
void example_fruits()
{
	// Setup example.
	code_example_setup("Fruits");

	// Create an entity of type "banana".
	ENT_TYPE fruit1 = CREATE_ENT_TYPE("banana");
	cout << "I just created an entity type called banana." << endl;

	// Create an entity of type "apple".
	ENT_TYPE fruit2 = CREATE_ENT_TYPE("apple");
	cout << "I just created an entity type called apple." << endl;

	cout << "We now have " << entsys->get_entity_type_count() << " entity types available." << endl;

	// Delete entity type "banana".
	cout << "Removing entity type banana." << endl;
	DELETE_ENT_TYPE(fruit1);
	cout << "We now have " << entsys->get_entity_type_count() << " entity types available." << endl;

	// Delete entity type "apple".
	cout << "Removing entity type apple." << endl;
	DELETE_ENT_TYPE(fruit2);
	cout << "We now have " << entsys->get_entity_type_count() << " entity types available." << endl;

	// Cleanup.
	entsys->reset_entity_system();
}



/// In this example we will create two other fruits as simple
/// examples for entity types. We will create some instances of them.
void example_fruit_instances()
{
	// Setup example.
	code_example_setup("Fruitbowl");

	// Create entity types.
	ENT_TYPE fruit1 = CREATE_ENT_TYPE("apple");
	ENT_TYPE fruit2 = CREATE_ENT_TYPE("ananas");
	ENT_TYPE fruit3 = CREATE_ENT_TYPE("cherries");

	cout << "We now have " << entsys->get_entity_type_count() << " entity types available." << endl;

	// Create an instance of entity type apple.
	ENT_TYPE_INST freshApple = CREATE_ENT_TYPE_INST(fruit1);
	// Create another instance of entity type apple.
	ENT_TYPE_INST rottenApple = CREATE_ENT_TYPE_INST(fruit1);

	cout << "We now have " << entsys->get_entity_type_instance_count() << " entity types instances available." << endl;

	// Cleanup.
	entsys->reset_entity_system();
}


void run_entsys_examples()
{
	example_fruits();
	example_fruit_instances();
}