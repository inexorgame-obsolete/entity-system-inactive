// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <cstdint>
#include <thread>
#include <mutex>

#include "DataTypes.hpp"
#include "../return-codes/ReturnCodes.hpp"


namespace inexor {
namespace entity_system {


	// TODO: Instead of accessing maps by value every time a write operation occurs, 
    // why not store a pointer to the value pair of the map in the write operation?
    // This could speed the entity system very much!

    // A flexible, multiple purpose data container.
    class DataContainer
    {
        private:

			// Use C++11 initialisation instead of constructor.
            ENTSYS_DATA_TYPE data_container_data_type = ENTSYS_DATA_TYPE_UNDEFINED;
            std::string string_data = "";
            std::int64_t int64_data = 0;
            int integer_data = 0;
            double double_data = 0.0;
            float float_data = 0.0f;
            bool boolean_data = false;
			
		public:

			// We have to make these public since there
			// is a problem with operator= and EntityTypeInstace!
			// TODO: Fix EntityTypeInstance DataContainer operator= issue!

            // Thread-safe set methods.
            const int& set(const int&);
            const bool& set(const bool&);
            const float& set(const float&);
            const double& set(const double&);
            const std::string& set(const std::string&);
            const std::int64_t& set(const std::int64_t&);

			// Multithreading safety mutex.
			std::mutex data_container_mutex;

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
			ENTSYS_RESULT set_container_data_type(const ENTSYS_DATA_TYPE&);

			// Returns the current data type of the data container.
			ENTSYS_DATA_TYPE get_container_data_type() const;

			// Assign operators.
			// Do these have to be of const type ?
            const int& operator=(const int&);
            const bool& operator=(const bool&);
            const float& operator=(const float&);
            const double& operator=(const double&);
            const std::string& operator=(const std::string&);
            const std::int64_t& operator=(const std::int64_t&);

			// Get methods.
			const int get_int() const;
			const bool get_bool() const;
			const float get_float() const;
			const double get_double() const;
			const std::string get_string() const;
			const std::int64_t get_int64() const;

			// Reset all memory.
			void reset_memory();

	};


};
};
