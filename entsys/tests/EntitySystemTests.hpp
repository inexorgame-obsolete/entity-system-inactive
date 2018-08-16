// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
#define INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER

// Minimum and maximum values for memory.
#include <cstdint>
#include <limits>

#include "../EntitySystem.hpp"
#include "../tests/EntitySystemProfiler.hpp"

// Look for definition of entsys in other files.
extern inexor::entity_system::EntitySystem& entsys;


namespace inexor {
namespace entity_system {


    // Iterate through all types when changing the data container's data type.
    ENTSYS_DATA_TYPE DataContainerDataTypeArray[] =
	{
        ENTSYS_DATA_TYPE_INT,
        ENTSYS_DATA_TYPE_BIG_INT,
        ENTSYS_DATA_TYPE_FLOAT,
        ENTSYS_DATA_TYPE_STRING,
        ENTSYS_DATA_TYPE_DOUBLE,
        ENTSYS_DATA_TYPE_BOOL
    };
    

    // Test DataContainer by making correct API calls.
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
            undefinedCont.set_data_type(DataContainerDataTypeArray[i % 6]);
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
		start_test("Creating and deleting entity of type 'player spawn'.", ENTSYS_TEST_REPETITION);
		Print_TestResultTableHeader();

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
		start_test("Creating and deleting entity of type 'sound source'.", ENTSYS_TEST_REPETITION);
		Print_TestResultTableHeader();

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
	void Test_DoesEntityTypeAlreadyExists_CorrectUsage()
	{
		start_test("Creating entity of type 'ctf flag'.");
		Print_TestResultTableHeader();

		// Create a new entity type called "flagpost"
		std::shared_ptr<EntityType> ctf_flag = std::make_shared<EntityType>(std::string("flagbase"));

		// Register new entity type to the entity system.
		entsys.create_entity_type(ctf_flag);

		// Look up if these types of entities do exist.
		bool ctf_flag_available = entsys.does_entity_type_exist("flagbase");
		bool capture_base_available = entsys.does_entity_type_exist("capturebase");

		if(ctf_flag_available) cout << "Entity type 'ctf flag' is available." << endl;
		if(!capture_base_available) cout << "Entity type '' is not available." << endl;

		end_test();
	}
};
};

#endif // INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
