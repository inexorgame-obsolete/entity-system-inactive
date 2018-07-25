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

// Windows specific only
#ifdef WIN32
    #include <Windows.h>
#endif

namespace inexor {
namespace entity_system {
    
    
    // Windows specific only
    #ifdef WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    #endif

    high_resolution_clock::time_point t1;
    std::string test_message = "";

    void start_test(std::string msg)
    {
        t1 = high_resolution_clock::now();
        test_message = msg;
    }


    void end_test()
    {
        // Calculate time difference in milliseconds.
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double, std::milli> time_span = t2 - t1;

        #ifdef WIN32
            SetConsoleTextAttribute(hConsole, 11); // light blue
        #endif

        // Print out how many milliseconds have passed during this test.
        std::cout << time_span.count() << " ms \t";
        
        #ifdef WIN32
            SetConsoleTextAttribute(hConsole, 10); // green
        #endif

        // Print test message
        cout << test_message << endl;

        #ifdef WIN32
            SetConsoleTextAttribute(hConsole, 13); // purple
        #endif
    }
    

};
};

#endif // INEXOR_ENTSYS_PERFORMANCE_PROFILER_HEADER
