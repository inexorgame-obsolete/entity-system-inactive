// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

// Minimum and maximum values for memory.
#include <cstdint>
#include <limits>

#include "../EntitySystem.hpp"
#include "../tests/EntitySystemProfiler.hpp"

// Look for definition of entsys in other files.
extern inexor::entity_system::EntitySystem& entsys;


namespace inexor {
namespace entity_system {


	// 
    void Test_DataContainer_CorrectUsage()
    {
        // Undefined type and undefined memory value.
        DataContainer undefinedCont;

        // Defined type but undefined memory value.
        DataContainer undefined_dc_int(ENTSYS_DATA_TYPE_INT);
        DataContainer undefined_dc_bigint(ENTSYS_DATA_TYPE_BIG_INT);
        DataContainer undefined_dc_float(ENTSYS_DATA_TYPE_FLOAT);
        DataContainer undefined_dc_string(ENTSYS_DATA_TYPE_STRING);
        DataContainer undefined_dc_double(ENTSYS_DATA_TYPE_DOUBLE);
        DataContainer undefined_dc_bool(ENTSYS_DATA_TYPE_BOOL);

        // Defined type and defined memory value.
        DataContainer BigIntCont(std::int64_t(32842471123));
        DataContainer DoubleCont(2345423.0);
        DataContainer FloatCont(2323.0f);
        DataContainer BoolCont(true);
        DataContainer IntCont(1234);
        DataContainer StringCont("This is an example string");        
        
        // ---------------------------------------------------------------------------------
		
        Print_TestHeadline("Testing DataContainer::set methods for 6 different data types.");
        Print_TestResultTableHeader();

        start_test("DataContainer::set(std::int64_t)", ENTSYS_TEST_REPETITION);
        for(std::int64_t i=0; i<ENTSYS_TEST_REPETITION; i++) {
            BigIntCont.set(i);
        }
        end_test();

        start_test("DataContainer::set(double)", ENTSYS_TEST_REPETITION);
        for(double i=0; i<ENTSYS_TEST_REPETITION; i+=1.0) {
            DoubleCont.set(i);
        }
        end_test();

        start_test("DataContainer::set(float)", ENTSYS_TEST_REPETITION);
        for(float i=0.0f; i<ENTSYS_TEST_REPETITION; i+=1.0f) {
            FloatCont.set(i);
        }
        end_test();

        start_test("DataContainer::set(bool)", ENTSYS_TEST_REPETITION);
        for(std::size_t i=0; i<ENTSYS_TEST_REPETITION; i++) {
            BoolCont.set( (0==i%2) ? true : false );
        }
        end_test();

        start_test("DataContainer::set(int)", ENTSYS_TEST_REPETITION);
        for(int i=0; i<ENTSYS_TEST_REPETITION; i++) {
            IntCont.set(i);
        }
        end_test();

        start_test("DataContainer::set(std::string)", ENTSYS_TEST_REPETITION);
        for(std::size_t i=0; i<ENTSYS_TEST_REPETITION; i++) {
            std::string strval = std::to_string(i);
            StringCont.set(strval);
        }
        end_test();

        // ---------------------------------------------------------------------------------
        
        Print_TestHeadline("Testing DataContainer::get methods for 6 different data types.");
        Print_TestResultTableHeader();
		
        int give_me_big_integer = 0;
        start_test("DataContainer::get(std::int64_t&)", ENTSYS_TEST_REPETITION);
        for(std::int64_t i=0; i<ENTSYS_TEST_REPETITION; i++) {
            BigIntCont.get(give_me_big_integer);
        }
        end_test();

        double give_me_double = 0.0;
        start_test("DataContainer::get(double&)", ENTSYS_TEST_REPETITION);
        for(double i=0; i<ENTSYS_TEST_REPETITION; i+=1.0) {
            DoubleCont.get(give_me_double);
        }
        end_test();

        float give_me_float = 0.0f;
        start_test("DataContainer::get(float&)", ENTSYS_TEST_REPETITION);
        for(float i=0.0f; i<ENTSYS_TEST_REPETITION; i+=1.0f) {
            FloatCont.get(give_me_float);
        }
        end_test();

        bool give_me_bool = false;
        start_test("DataContainer::get(bool&)", ENTSYS_TEST_REPETITION);
        for(std::size_t i=0; i<ENTSYS_TEST_REPETITION; i++) {
            BoolCont.get(give_me_bool);
        }
        end_test();

        int give_me_int = 0;
        start_test("DataContainer::get(int&)", ENTSYS_TEST_REPETITION);
        for(int i=0; i<ENTSYS_TEST_REPETITION; i++) {
            IntCont.get(give_me_int);
        }
        end_test();

        std::string give_me_str;
        start_test("DataContainer::get(std::string&)", ENTSYS_TEST_REPETITION);
        for(std::size_t i=0; i<ENTSYS_TEST_REPETITION; i++) {
            StringCont.get(give_me_str);
        }
        end_test();

        // ---------------------------------------------------------------------------------
		
        Print_TestHeadline("Testing DataContainer::set_data_type() method.");
        Print_TestResultTableHeader();

        start_test("DataContainer::set_data_type(const ENTSYS_DATA_TYPE&)", ENTSYS_TEST_REPETITION);
        for(std::size_t i=0; i<ENTSYS_TEST_REPETITION; i++) {
            // Make sure not to read outside of the array.
            undefinedCont.set_data_type(ENTSYS_DATA_TYPE_INT);
        }
        end_test();

        // ---------------------------------------------------------------------------------

        Print_TestHeadline("Testing DataContainer::get_data_type() method.");
        Print_TestResultTableHeader();

        ENTSYS_DATA_TYPE containerDataType;
        start_test("DataContainer::get_data_type()", ENTSYS_TEST_REPETITION);
        for(std::size_t i=0; i<ENTSYS_TEST_REPETITION; i++) {
            containerDataType = IntCont.get_data_type();
        }
        end_test();

        // ---------------------------------------------------------------------------------
                
        Print_TestHeadline("Testing DataContainer::operator=() for 6 data types.");
        Print_TestResultTableHeader();

        start_test("DataContainer::operator=(std::int64_t&)", ENTSYS_TEST_REPETITION);
        for(std::int64_t i=0; i<ENTSYS_TEST_REPETITION; i++) {
            BigIntCont = i;
        }
        end_test();

        start_test("DataContainer::operator=(double&)", ENTSYS_TEST_REPETITION);
        for(double i=0; i<ENTSYS_TEST_REPETITION; i+=1.0) {
            DoubleCont = i;
        }
        end_test();

        start_test("DataContainer::operator=(float&)", ENTSYS_TEST_REPETITION);
        for(float i=0.0f; i<ENTSYS_TEST_REPETITION; i+=1.0f) {
            FloatCont = i;
        }
        end_test();

        start_test("DataContainer::operator=(bool&)", ENTSYS_TEST_REPETITION);
        for(std::size_t i=0; i<ENTSYS_TEST_REPETITION; i++) {
            BoolCont = (0==i%2) ? true : false;
        }
        end_test();

        start_test("DataContainer::operator=(int&)", ENTSYS_TEST_REPETITION);
        for(int i=0; i<ENTSYS_TEST_REPETITION; i++) {
            IntCont = i;
        }
        end_test();

        start_test("DataContainer::operator=(std::string&)", ENTSYS_TEST_REPETITION);
        for(std::size_t i=0; i<ENTSYS_TEST_REPETITION; i++) {
            StringCont = std::to_string(i);
        }
        end_test();
    }


	// 
	void Test_CreateEntityType_CorrectUsage()
	{
		Print_TestHeadline("Creating and deleting entity of type 'player spawn'.");
		Print_TestResultTableHeader();

		start_test("EntityTypeManager:: create_entity_type, delete_entity_type", ENTSYS_TEST_REPETITION);

		for(std::size_t i=0; i<ENTSYS_TEST_REPETITION; i++)
		{
			// Create a new entity type called "playerspawn".
			std::shared_ptr<EntityType> playerspawn = std::make_shared<EntityType>(std::string("playerspawn"));

			// Register new entity type to the entity system.
			entsys.create_entity_type(playerspawn);

			// Remove entity type from the entity system again.
			entsys.delete_entity_type("playerspawn");
		}
		end_test();
	}


	// 
	void Test_CreateEntityType_IncorrectUsage()
	{
		Print_TestHeadline("Creating and deleting entity of type 'sound source'.");
		Print_TestResultTableHeader();
		
		start_test("EntityTypeManager:: create_entity_type, delete_entity_type", ENTSYS_TEST_REPETITION);

		for(std::size_t i=0; i<ENTSYS_TEST_REPETITION; i++)
		{
			// Create a new entity type called "playerspawn"
			std::shared_ptr<EntityType> soundsource1 = std::make_shared<EntityType>(std::string("soundsource"));
			std::shared_ptr<EntityType> soundsource2 = std::make_shared<EntityType>(std::string("soundsource"));

			// Register new entity type to the entity system.
			entsys.create_entity_type(soundsource1);

			// ERROR: new entity type does already exist!
			entsys.create_entity_type(soundsource2);

			// Remove entity type from the entity system again.
			entsys.delete_entity_type("soundsource");
		}
		end_test();
	}


	// 
	void Test_DoesEntityTypeExist_CorrectUsage()
	{
		Print_TestHeadline("Creating, querying and deleting entity of type 'flagbase'.");
		Print_TestResultTableHeader();

		start_test("EntityTypeManager:: create_entity_type, does_entity_type_exist'.", ENTSYS_TEST_REPETITION);
		
		for(std::size_t i=0; i<ENTSYS_TEST_REPETITION; i++)
		{
			// Create a new entity type called "flagpost".
			std::shared_ptr<EntityType> ctf_flag = std::make_shared<EntityType>(std::string("flagbase"));

			// Register new entity type to the entity system.
			entsys.create_entity_type(ctf_flag);

			// Look up if these types of entities do exist.
			bool ctf_flag_available = entsys.does_entity_type_exist("flagbase");
			bool capture_base_available = entsys.does_entity_type_exist("capturebase");
		}

		end_test();
		
		// Delete entity type after the test has finished.
		entsys.delete_entity_type("flagbase");
	}


	//
	void Test_EntityTypesCount_CorrectUsage()
	{
		Print_TestHeadline("Querying number of available entity types.");
		Print_TestResultTableHeader();

		// Create a new entity type called "pistol".
		std::shared_ptr<EntityType> weapon1 = std::make_shared<EntityType>(std::string("pistol"));

		// Register new entity type to the entity system.
		entsys.create_entity_type(weapon1);

		start_test("EntityTypeManager::get_entity_types_count", ENTSYS_TEST_REPETITION);
		
		for(std::size_t i=0; i<ENTSYS_TEST_REPETITION; i++)
		{
			std::size_t tmp = entsys.get_entity_types_count();
		}

		end_test();

		// Delete entity type after the test has finished.
		entsys.delete_entity_type("pistol");
	}


	// 
	void Test_LinkEntityAttributeTypeToEntityType_CorrectUsage()
	{
		Print_TestHeadline("Initialising entity types and link entity attribute types.");
		Print_TestResultTableHeader();
	
		// Create a new entity type called "rocketlauncher".
		std::shared_ptr<EntityType> weapon2 = std::make_shared<EntityType>("rocketlauncher");

		// Create attribute types for "rocketlauncher".
		std::shared_ptr<EntityAttributeType> attr1 = std::make_shared<EntityAttributeType>("damage");
		std::shared_ptr<EntityAttributeType> attr2 = std::make_shared<EntityAttributeType>("weight");
		std::shared_ptr<EntityAttributeType> attr3 = std::make_shared<EntityAttributeType>("color");
		std::shared_ptr<EntityAttributeType> attr4 = std::make_shared<EntityAttributeType>("reloadtime");

		// Create a vector of shared pointers to entity attribute types
		const std::vector<std::shared_ptr<EntityAttributeType>> weapon2_attributes = {attr1, attr2, attr3, attr4};
		std::vector<std::shared_ptr<EntityAttributeType>> weapon2_attributes2 = {attr1, attr2, attr3, attr4};

		// Link entity attribute types to entity type.

		// TODO: Rename to "setup_..." ?
		entsys.create_entity_type_with_attributes(weapon2, weapon2_attributes);
		entsys.create_entity_type_with_attributes(weapon2, weapon2_attributes2);

		// Delete entity type after the test has finished.
		entsys.delete_entity_type("rocketlauncher");
	}

};
};
