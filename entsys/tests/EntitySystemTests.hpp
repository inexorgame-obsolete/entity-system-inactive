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

    
    // Test DataContainer by making false API calls.
    void Test_DataContainer_ErrorUsage()
    {
        // TODO
    }
    
    // Test DataContainer by making correct API calls.
    void Test_DataContainer_CorrectUsage()
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
        
        // This defined how often a test will be repeated.
        #define ENTSYS_TEST_REPETITION 100000
        
        Change_Output_Console_Color(CCOLOR_PURPLE);
        cout << endl << endl << "Testing DataContainer::set methods for 6 different data types." << endl;
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
        for(unsigned int i=0; i<ENTSYS_TEST_REPETITION; i++) {
            BoolCont.set( (0==i%2) ? true : false );
        }
        end_test();

        start_test("DataContainer::set(int)", ENTSYS_TEST_REPETITION);
        for(int i=0; i<ENTSYS_TEST_REPETITION; i++) {
            IntCont.set(i);
        }
        end_test();

        start_test("DataContainer::set(std::string)", ENTSYS_TEST_REPETITION);
        for(unsigned int i=0; i<ENTSYS_TEST_REPETITION; i++) {
            std::string strval = std::to_string(i);
            StringCont.set(strval);
        }
        end_test();


        Change_Output_Console_Color(CCOLOR_PURPLE);
        cout << endl << endl << "Testing DataContainer::get methods for 6 different data types." << endl;
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
        for(unsigned int i=0; i<ENTSYS_TEST_REPETITION; i++) {
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
        for(unsigned int i=0; i<ENTSYS_TEST_REPETITION; i++) {
            StringCont.get(give_me_str);
        }
        end_test();

    }

};
};

#endif // INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
