// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_DATA_CONTAINER_CLASS_HEADER
#define INEXOR_ENTSYS_DATA_CONTAINER_CLASS_HEADER

#include <string>
#include <cstdint>
#include "DataTypes.hpp"
#include "../return-codes/ReturnCodes.hpp"
#include "../tests/EntitySystemDebugging.hpp"


namespace inexor {
namespace entsys {
        
    // A flexible, multiple purpose data container.
    // TODO: Instead of accessing maps by value every time a write operation occurs, why not store a pointer to the value pair
    // of the map in the write operation? This could speed the entity system very much!
    class DataContainer
    {
        private:

            ENTSYS_DATA_TYPE data_container_data_type;

            // TODO: Implement template class for data storage.

            std::string string_data = std::string("");
            std::int64_t int64_data = 0;
            int integer_data = 0;
            double double_data = 0.0;
            float float_data = 0.0f;
            bool boolean_data = false;

            // TODO: Add more data types here
            // TODO: Implement real RBG color codes?
            // TODO: Add vec3 support by supporting GLM:
            // https://glm.g-truc.net/0.9.9/index.html

        protected:

            // Reset the memory of all members.
            void reset_memory();

            // Math operations can only be applied to numeric data containers.
            bool data_container_type_is_numeric();

        public:

            // We need this not overloaded constructor since sometimes
            // the data type of the container is not known yet.
            DataContainer();

            // Overloaded constructors.
            DataContainer(const ENTSYS_DATA_TYPE&);
            DataContainer(const std::int64_t&);
            DataContainer(const double&);
            DataContainer(const float&);
            DataContainer(const bool&);
            DataContainer(const int&);
            DataContainer(const std::string&);

            ~DataContainer();

            // Set the data type of the container.
            const ENTSYS_RETURN_CODE set_data_type(const ENTSYS_DATA_TYPE&);

            // TODO: DISCUSS: If we left out type checking during set operations we 
            // could save up quite some time. However this could lead to entity system errors!

            // TODO: DISCUSS: Do all methods have to be of const type?

            // Set methods.
            const DataContainer set(const std::int64_t);
            const DataContainer set(const double);
            const DataContainer set(const float);
            const DataContainer set(const bool);
            const DataContainer set(const int);
            const DataContainer set(const std::string);

            // Operators.
            const DataContainer operator+(const DataContainer&);
            const DataContainer operator-(const DataContainer&);
            const DataContainer operator*(const DataContainer&);
            const DataContainer operator/(const DataContainer&);

            // Assign operators.
            const DataContainer operator=(const int&);
            const DataContainer operator=(const double&);
            const DataContainer operator=(const float&);
            const DataContainer operator=(const bool&);
            const DataContainer operator=(const std::int64_t&);
            const DataContainer operator=(const std::string&);

            // Since ENTSYS_DATA_TYPE could be casted to operator=(int)
            // we want to delete this explicitely.
            // TODO: Find a better way to prevent this?
            DataContainer operator=(const ENTSYS_DATA_TYPE&) = delete;                                                

            // TODO: Make them protected ?
            // TODO: Overload the operators +=, -=, *=, /=..

            // Math operations.
            const DataContainer add(const DataContainer&);
            const DataContainer sub(const DataContainer&);
            const DataContainer mul(const DataContainer&);
            const DataContainer div(const DataContainer&);

            // Get methods.
            const std::int64_t get_bigintval() const;
            const std::string get_stringval() const;
            const double get_doubleval() const;
            const float get_floatval() const;
            const bool get_boolval() const;
            const int get_intval() const;

            const ENTSYS_DATA_TYPE get_data_type() const;

    };

};
};

#endif // INEXOR_ENTSYS_DATA_CONTAINER_CLASS_HEADER
