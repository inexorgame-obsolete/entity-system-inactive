// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
#define INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER

// Minimum and maximum values for memory.
#include <cstdint>
#include <limits>

#include "../EntitySystem.hpp"
extern inexor::entity_system::EntitySystem* entsys;

// Start and end tests with the profiler.
#include "../tests/EntitySystemProfiler.hpp"


namespace inexor {
namespace entity_system {
    

    // Minimum and maximum values.
    void Print_MinimumMaximumMemoryValues()
    {
        // Windows specific only
        #ifdef WIN32
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 14); // purple
        #endif

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

    
    // Test by making false API calls.

    void ErrorTest_DataContainer()
    {
        // Test constructors.
        // Undefined type and undefined memory value.
        DataContainer undefinedCont;

        // Defined type and undefined memory value.
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
    }
    
    // Test by making correct API calls.

};
};

#endif // INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
