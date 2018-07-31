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
	// EDIT: We can resolve this by using exception.


    // A flexible, multiple purpose data container.
    class DataContainer
    {
        private:

            ENTSYS_DATA_TYPE data_container_data_type;

            // TODO: Implement template class for data storage + thread safety

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
            

        public:

            // We need this standard constructor since sometimes
            // the data type of the container is not known yet.
            DataContainer();

            // Overloaded constructors.
            DataContainer(const ENTSYS_DATA_TYPE&);
            DataContainer(const std::int64_t&);
            DataContainer(const std::string&);
            DataContainer(const double&);
            DataContainer(const float&);
            DataContainer(const bool&);
            DataContainer(const int&);

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
            
            // Assign operators.
            DataContainer operator=(const int&);
            DataContainer operator=(const double&);
            DataContainer operator=(const float&);
            DataContainer operator=(const bool&);
            DataContainer operator=(const std::int64_t&);
            DataContainer operator=(const std::string&);

            ENTSYS_DATA_TYPE get_data_type() const;

            // Get methods: call by reference.
            void get(std::int64_t&) const;
            void get(std::string&) const;
            void get(double&) const;
            void get(float&) const;
            void get(bool&) const;
            void get(int&) const;

    };

};
};

#endif // INEXOR_ENTSYS_DATA_CONTAINER_CLASS_HEADER
