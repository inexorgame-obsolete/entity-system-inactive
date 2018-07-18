// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
#define INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER

#include <iostream>
using namespace std;

// Time 
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std::chrono;

#include "../data-container/DataContainer.hpp"


namespace inexor {
namespace entsys {

// Points in time.
high_resolution_clock::time_point t1;

// Start test: remember start time in milliseconds
void start_test()
{
    t1 = high_resolution_clock::now();
}

// End test: remember end time in milliseconds
void end_test()
{
    // Calculate time difference in milliseconds.
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double, std::milli> time_span = t2 - t1;
    // Print out how many milliseconds have passed during this test.
    std::cout << "Time passed: " << time_span.count() << " milliseconds." << endl  << endl;
}



// Testing multiple purpose data container.
void Test_EntitySystemDataContainers()
{
    // TESTS HERE

    // Initialisation
    // Debug constructor calls here.
    DataContainer dc_int(0);
    DataContainer dc_bigint(std::int64_t(0));
    DataContainer dc_string(std::string(""));
    DataContainer dc_bool(false);
    DataContainer dc_float(0.0f);
    DataContainer dc_double(0.0);

    cout << "Inexor entity system prototype automated software testing." << endl;
    

    // Testing DataContainer of type Integer (signed int)
    // ==================================================================

    // Smaller tests: 1000 calls

    start_test();
    cout << "Call DataContainer::operator=(int) 1000 times:" << endl;
    for(int i=0; i<1000; i++) {
        dc_int.set(0);
        dc_int = i;
    }
    end_test();

    start_test();
    cout << "Call DataContainer::operator=(float) 1000 times:" << endl;
    for(float i=0.0f; i<1000.0f; i+=1.0f) {
        dc_float.set(0.0f);
        dc_float = i;
    }
    end_test();

    start_test();
    cout << "Call DataContainer::operator=(double) 1000 times:" << endl;
    for(double i=0.0f; i<1000.0f; i+=1.0f) {
        dc_double.set(0.0);
        dc_double = i;
    }
    end_test();

    start_test();
    cout << "Call DataContainer::operator=(bool) 1000 times:" << endl;
    for(int i=0; i<1000; i+=1) {
        dc_bool.set(false);
        dc_bool = (0==(i%2)) ? true : false;
    }
    end_test();

    start_test();
    cout << "Call DataContainer::operator=(std::int64_t) 1000 times:" << endl;
    for(int64_t i=0; i<1000; i+=1) {
        dc_bigint.set(0);
        dc_bigint = i;
    }
    end_test();

    start_test();
    cout << "Call DataContainer::operator=(std::string) 1000 times:" << endl;
    for(int i=0; i<1000; i+=1) {
        dc_string.set(std::string(""));
        dc_string = std::to_string(i);
    }
    end_test();
    
    start_test();
    int test_int = 0;
    cout << "Call DataContainer::get_intval() 1 million times:" << endl;
    for(int i=0; i<1000000; i++) test_int = dc_int.get_intval();
    end_test();
    
    start_test();
    cout << "Call DataContainer::get_data_type() 1 million times:" << endl;
    for(int i=0; i<1000000; i++) ENTSYS_DATA_TYPE test_type = dc_int.get_data_type();
    end_test();

    start_test();
    cout << "Call DataContainer::operator=(int) 1 million times" << endl;
    end_test();

    // Testing DataContainer of type Big Integer (std::int64_t)
    // ==================================================================

}


};
};

#endif // INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
