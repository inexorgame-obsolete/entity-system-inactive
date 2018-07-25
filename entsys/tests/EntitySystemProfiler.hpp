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
    
    // Define color code macros for 
    // changing the output console's color.
    #define CCOLOR_GREEN  10
    #define CCOLOR_BLUE   9
    #define CCOLOR_PURPLE 13

    void Change_Output_Console_Color(int k)
    {
        // Windows specific only!
        #ifdef WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
        #endif
    }



    high_resolution_clock::time_point t1;
    unsigned int test_repititions = 1;
    std::string test_message = "";


    void start_test(std::string msg, unsigned int repetitions = 1)
    {
        t1 = high_resolution_clock::now();
        test_repititions = repetitions;
        test_message = msg;
    }


    void end_test()
    {
        // Calculate time difference in milliseconds.
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double, std::milli> time_span = t2 - t1;

        // Calculate the average time passed for one function call.
        double average_time_per_call = time_span.count() / test_repititions;

        Change_Output_Console_Color(CCOLOR_GREEN);

        // Print out how many milliseconds have passed during this test.
        cout << time_span.count() << " ms \t";
        
        Change_Output_Console_Color(CCOLOR_GREEN);

        // Print out number of test repititions.
        cout << test_repititions << "x\t\t";
         
        Change_Output_Console_Color(CCOLOR_GREEN);

        cout << average_time_per_call << " ms\t";

        // Print out test message
        cout << "\t\t" << test_message << endl;

        Change_Output_Console_Color(CCOLOR_PURPLE);

        cout << endl;
    }

    
    // Every test series starts with 
    // this table header as console output.
    void Print_TestResultTableHeader()
    {
        Change_Output_Console_Color(CCOLOR_GREEN);
        
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        cout << "Time passed" << "\t" << "Repetitions" << "\t" << "Average Time passed/call" << "\t" << "Function call" << endl;
        cout << "---------------------------------------------------------------------------------------------------" << endl;
    }


};
};

#endif // INEXOR_ENTSYS_PERFORMANCE_PROFILER_HEADER
