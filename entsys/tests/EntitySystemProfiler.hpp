// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_PERFORMANCE_PROFILER_HEADER
#define INEXOR_ENTSYS_PERFORMANCE_PROFILER_HEADER

#include <iostream>
using namespace std;

#include <ctime>
#include <ratio>
#include <chrono>
using namespace std::chrono;


namespace inexor {
namespace entsys {
    
    high_resolution_clock::time_point t1;

    void start_test()
    {
        t1 = high_resolution_clock::now();
    }

    void end_test()
    {
        // Calculate time difference in milliseconds.
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double, std::milli> time_span = t2 - t1;

        // Print out how many milliseconds have passed during this test.
        std::cout << "Time passed: " << time_span.count() << " milliseconds." << endl  << endl;
    }
    
};
};

#endif // INEXOR_ENTSYS_PERFORMANCE_PROFILER_HEADER
