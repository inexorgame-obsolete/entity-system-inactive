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

    start_test();
    inexor::entsys::DataContainer dump(0);
    cout << "Performing 100.000 WRITE operations on DataContainer of type int." << endl;
    for(int i=0; i<100000; i++) {
        dump = i;
    }
    end_test();


    start_test();
    cout << "Performing 100.000 READ operations on DataContainer of type int." << endl;
    for(int i=0; i<1000000; i++) {
        int x = dump.get_intval();
    }
    end_test();
    

    start_test();
    end_test();

}

#endif // INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
