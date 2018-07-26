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

// This defines how often a test will be repeated.
#define ENTSYS_TEST_REPETITION 100000
    
// Define color code macros for 
// changing the output console's color.
#define CCOLOR_GREEN  10
#define CCOLOR_BLUE   9
#define CCOLOR_PURPLE 13

// Windows specific only
#ifdef WIN32
    #include <Windows.h>
#endif


namespace inexor {
namespace entity_system {
    

    // Global variables for automatic tests.
    high_resolution_clock::time_point t1;
    unsigned int test_repetitions = 1;
    std::string test_message = "";


    // Change the text color of the (Windows) console.
    void Change_Output_Console_Color(int k)
    {
        // Windows specific only!
        #ifdef WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
        #endif
    }


    // Print the headline of a series of tests with another output color.
    void Print_TestHeadline(std::string msg)
    {
        Change_Output_Console_Color(CCOLOR_PURPLE);
        cout << endl << endl << msg << endl;
    }


    // Print minimum and maximum memory values.
    void Print_MinimumMaximumMemoryValues()
    {
        Change_Output_Console_Color(CCOLOR_PURPLE);
        cout << endl << endl << "Printing system specific minimum and maximum values of memory types." << endl;

        Change_Output_Console_Color(CCOLOR_GREEN);
        cout << "-----------------------------------------------------------------------" << endl;
        cout << "DATA TYPE" << "\t\t" << "MINIMUM" << "\t\t\t" << "MAXIMUM" << endl; 
        cout << "-----------------------------------------------------------------------" << endl;
        cout << "char\t\t\t"                 << CHAR_MIN  << "\t\t\t" << CHAR_MAX         << endl;
        cout << "signed char\t\t"            << SCHAR_MIN << "\t\t\t" << SCHAR_MAX        << endl;
        cout << "unsigned char\t\t"          << 0         << "\t\t\t" << UCHAR_MAX        << endl;
        cout << "wchar_t\t\t\t"              << SCHAR_MIN << "\t\t\t" << WCHAR_MAX        << endl;
        cout << "char16_t\t\t"               << 0         << "\t\t\t" << UINT_LEAST16_MAX << endl;
        cout << "char32_t\t\t"               << 0         << "\t\t\t" << UINT_LEAST32_MAX << endl;
        cout << "short\t\t\t"                << SHRT_MIN  << "\t\t\t" << SHRT_MAX         << endl;
        cout << "unsigned short\t\t"         << 0         << "\t\t\t" << USHRT_MAX        << endl;
        cout << "int\t\t\t"                  << INT_MIN   << "\t\t"   << INT_MAX          << endl;
        cout << "unsigned int\t\t"           << 0         << "\t\t\t" << UINT_MAX         << endl;
        cout << "long\t\t\t"                 << LONG_MIN  << "\t\t"   << LONG_MAX         << endl;
        cout << "unsigned long\t\t"          << 0         << "\t\t\t" << ULONG_MAX        << endl;
        cout << "long long\t\t"              << LLONG_MIN << "\t"     << LLONG_MAX        << endl;
        cout << "unsigned long long\t"       << 0         << "\t\t\t" << ULLONG_MAX       << endl;
        cout << "float\t\t\t"                << FLT_MIN   << "\t\t"   << FLT_MAX          << endl;
        cout << "double\t\t\t"               << DBL_MIN   << "\t\t"   << DBL_MAX          << endl;
        cout << "long double\t\t"            << LDBL_MIN  << "\t\t"   << LDBL_MAX         << endl;
        cout << "-----------------------------------------------------------------------" << endl;
    }


    // Start an automatic test.
    void start_test(std::string msg, unsigned int repetitions = 1)
    {
        t1 = high_resolution_clock::now();
        test_repetitions = repetitions;
        test_message = msg;
    }


    // End an automatic test.
    void end_test()
    {
        // Calculate time difference in milliseconds.
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double, std::milli> time_span = t2 - t1;

        // Print out how many milliseconds have passed during this test.
        Change_Output_Console_Color(CCOLOR_GREEN);
        cout << time_span.count() << " ms \t";

        // Print out number of test repetitions.
        Change_Output_Console_Color(CCOLOR_GREEN);
        cout << test_repetitions << "x\t\t";

        // Calculate the average time passed for one function call.
        double average_time_per_call = time_span.count() / test_repetitions;

        // Print out average time per function call.
        Change_Output_Console_Color(CCOLOR_GREEN);
        cout << average_time_per_call << " ms\t";

        // Print out test message (name of the function call).
        cout << "\t\t" << test_message << endl;
        Change_Output_Console_Color(CCOLOR_PURPLE);
        cout << endl;
    }

    
    // Every test series starts with this table header as console output.
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
