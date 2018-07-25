// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_DATA_CONTAINER_CLASS_HEADER
#define INEXOR_ENTSYS_DATA_CONTAINER_CLASS_HEADER

// TODO: Add multithreading safety.

#include <string>
#include <cstdint>

#include "DataTypes.hpp"

#include "../return-codes/ReturnCodes.hpp"
#include "../tests/EntitySystemDebugging.hpp"


namespace inexor {
namespace entity_system {


    // TODO: Instead of accessing maps by value every time a write operation occurs, 
    // why not store a pointer to the value pair of the map in the write operation?
    // This could speed the entity system very much!

    // TODO: DISCUSS: If we left out type checking during set operations we 
    // could save up quite some time. However this could lead to entity system errors!

    // A flexible, multiple purpose data container.
    class DataContainer
    {
        private:

            ENTSYS_DATA_TYPE data_container_data_type;

            // TODO: Implement template class for data storage + thread safety

            // TODO: DISCUSS: Make this an union ?

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

            // Only numeric data containers can execute math operations!
            // Check is this data container's type is numeric
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
            ENTSYS_RETURN_CODE set_data_type(const ENTSYS_DATA_TYPE&);
            
            // Set methods.
            DataContainer set(const std::int64_t&);
            DataContainer set(const std::string&);
            DataContainer set(const double&);
            DataContainer set(const float&);
            DataContainer set(const bool&);
            DataContainer set(const int&);

            // Operators.
            DataContainer operator+(const DataContainer&);
            DataContainer operator-(const DataContainer&);
            DataContainer operator*(const DataContainer&);
            DataContainer operator/(const DataContainer&);

            // Assign operators.
            DataContainer operator=(const int&);
            DataContainer operator=(const double&);
            DataContainer operator=(const float&);
            DataContainer operator=(const bool&);
            DataContainer operator=(const std::int64_t&);
            DataContainer operator=(const std::string&);

            // Get methods.
            ENTSYS_DATA_TYPE get_data_type() const;


    };

};
};

#endif // INEXOR_ENTSYS_DATA_CONTAINER_CLASS_HEADER
