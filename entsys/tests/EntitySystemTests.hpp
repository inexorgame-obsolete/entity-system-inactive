// Inexor entity system prototype
// (c)2018 Inexor

#include <iostream>
using namespace std;

// Time 
#include <ctime>
#include <ratio>
#include <chrono>

// Data container
#include "../data-container/DataContainer.hpp"


// Testing multiple purpose data container.
void Test_EntitySystemDataContaners()
{
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    // TESTS HERE
    inexor::entsys::DataContainer dump(100);

    cout << "Performing 100.000 write operations on DataContainer of type int." << endl;
    for(int i=0; i<100000; i++)
    {
        dump = i;
        //cout << dump.get_intval() << endl;
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double, std::milli> time_span = t2 - t1;

    std::cout << "It took me " << time_span.count() << " milliseconds.";
    std::cout << std::endl;


}
