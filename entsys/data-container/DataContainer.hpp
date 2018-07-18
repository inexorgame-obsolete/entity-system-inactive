// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_DATA_AND_DATA_TYPE_CONTAINER_HEADER
#define INEXOR_ENTSYS_DATA_AND_DATA_TYPE_CONTAINER_HEADER

#include <string>
#include <cstdint>
#include "DataTypes.hpp"

namespace inexor {
namespace entsys {
        
    /// A flexible, multiple purpose data container.
    class DataContainer
    {
        private:

            // TODO: GOOD IDEA: instead of accessing maps by value every time
            // a write operation occurs, why not store a pointer to the value pair
            // of the map in the write operation?
            // This could speed the entity system very much!
            ENTSYS_DATA_TYPE data_container_data_type;

            std::string string_data;
            // Don't forget that the actual memory size of
            // every variable depends on the operating system!
            std::int64_t int64_data;
            int integer_data;
            double double_data;
            float float_data;
            bool boolean_data;

        protected:
            void reset_memory();                           // Automatic test available!
            bool data_container_is_numeric();

        public:

            // We need this not overloaded constructor since sometimes
            // the data type of the container is not known yet.
            DataContainer();

            // Overloaded constructors for fast initialization.
            DataContainer(ENTSYS_DATA_TYPE);
            DataContainer(const std::int64_t);              // Automatic test available!
            DataContainer(const double);                    // Automatic test available!
            DataContainer(const float);                     // Automatic test available!
            DataContainer(const bool);                      // Automatic test available!
            DataContainer(const int);                       // Automatic test available!
            DataContainer(const std::string);               // Automatic test available!

            ~DataContainer();

            // TODO: DISCUSS: If we left out type checking during set operations we 
            // could save up quite some time. However this could lead to entity system errors!

            // TODO: DISCUSS: Do all methods have to be of const type?

            // Set methods.
            const DataContainer set(const std::int64_t);    // Automatic test available!
            const DataContainer set(const double);          // Automatic test available!
            const DataContainer set(const float);           // Automatic test available!
            const DataContainer set(const bool);            // Automatic test available!
            const DataContainer set(const int);             // Automatic test available!
            const DataContainer set(const std::string);     // Automatic test available!

            // Overloaded operators.
            DataContainer operator+(const DataContainer&);
            DataContainer operator-(const DataContainer&);
            DataContainer operator*(const DataContainer&);
            DataContainer operator/(const DataContainer&);

            // Overloaded set operators.
            DataContainer operator=(const int&);            // Automatic test available!
            DataContainer operator=(const double&);         // Automatic test available!
            DataContainer operator=(const float&);          // Automatic test available!
            DataContainer operator=(const bool&);           // Automatic test available!
            DataContainer operator=(const std::int64_t&);   // Automatic test available!
            DataContainer operator=(const std::string&);    // Automatic test available!
                           
            // TODO: Make them protected and
            // overload the operators +=, -=, *=, /=..

            // Math operations.
            const DataContainer add(const DataContainer&);  // Automatic test available!
            const DataContainer sub(const DataContainer&);  // Automatic test available!
            const DataContainer mul(const DataContainer&);  // Automatic test available!
            const DataContainer div(const DataContainer&);  // Automatic test available!

            // Get methods.
            const std::int64_t get_bigintval() const;
            const double get_doubleval() const;
            const float get_floatval() const;
            const bool get_boolval() const;
            
            // Automatic test available
            const int get_intval() const;
            
            const std::string get_stringval() const;

            // Automatic test available
            const ENTSYS_DATA_TYPE get_data_type() const;

    };

};
};

#endif // INEXOR_ENTSYS_DATA_AND_DATA_TYPE_CONTAINER_HEADER
