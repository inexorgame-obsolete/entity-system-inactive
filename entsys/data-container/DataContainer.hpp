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

			// Use C++11 initialisation style instead of constructor list.

            ENTSYS_DATA_TYPE data_type = ENTSYS_DATA_TYPE_UNDEFINED;

			std::int64_t data_int64 = 0;

			std::string data_string = "";

			double data_double = 0.0;

			float data_float = 0.0f;

			bool data_bool = false;

			int data_int = 0;
			
			// Multithreading safety mutex.
			//std::mutex container_mutex;

		public:

			// Don't use explicit keyword to prevent implicit conversion!
            DataContainer(const ENTSYS_DATA_TYPE&);
            DataContainer(const std::int64_t&);
            DataContainer(const std::string&);
            DataContainer(const double&);
            DataContainer(const float&);
            DataContainer(const bool&);
            DataContainer(const int&);

            ~DataContainer();

			// Set the data type of the container.
			void set_data_type(const ENTSYS_DATA_TYPE&);

			// Returns the current data type of the data container.
			ENTSYS_DATA_TYPE get_data_type() const;

			// Reset all memory.
			void reset_memory();

			// Get methods for memory access.
			// In C++ we can't have functions which only differ
			// in their return value. There is no general way of
			// implementing 'get_data()'.
			std::int64_t get_int64() const;
			std::string get_string() const;
			double get_double() const;
			float get_float() const;
			bool get_bool() const;
			int get_int() const;

			// Cast methods.
			std::int64_t cast_to_int64() const;

			// Set data methods.
			DataContainer set_data(const DataContainer&);
			DataContainer set_data(const std::int64_t&);
			DataContainer set_data(const std::string&);
			DataContainer set_data(const double&);
			DataContainer set_data(const float&);
			DataContainer set_data(const bool&);
			DataContainer set_data(const int&);


			// Initialisation operators.
			DataContainer operator = (const DataContainer&);
			DataContainer operator = (const std::int64_t&);
			DataContainer operator = (const std::string&);
			DataContainer operator = (const double&);
			DataContainer operator = (const float&);
			DataContainer operator = (const bool&);
			DataContainer operator = (const int&);
			

			// Increment and decrement operator.
			DataContainer operator ++ (int);
			DataContainer operator -- (int);


			// Arithmetic operators.
			DataContainer operator + (const int&);
			DataContainer operator + (const float&);
			DataContainer operator + (const double&);
			DataContainer operator + (const std::int64_t&);
			DataContainer operator + (const DataContainer&);
			
			DataContainer operator - (const int&);
			DataContainer operator - (const float&);
			DataContainer operator - (const double&);
			DataContainer operator - (const std::int64_t&);
			DataContainer operator - (const DataContainer&);

			DataContainer operator * (const int&);
			DataContainer operator * (const float&);
			DataContainer operator * (const double&);
			DataContainer operator * (const std::int64_t&);
			DataContainer operator * (const DataContainer&);

			DataContainer operator / (const int&);
			DataContainer operator / (const float&);
			DataContainer operator / (const double&);
			DataContainer operator / (const std::int64_t&);
			DataContainer operator / (const DataContainer&);

			DataContainer operator % (const int&);
			DataContainer operator % (const float&);
			DataContainer operator % (const double&);
			DataContainer operator % (const std::int64_t&);
			DataContainer operator % (const DataContainer&);


			// Compound assignment operators.
			DataContainer operator += (const int&);
			DataContainer operator += (const float&);
			DataContainer operator += (const double&);
			DataContainer operator += (const std::int64_t&);
			DataContainer operator += (const DataContainer&);

			DataContainer operator -= (const int&);
			DataContainer operator -= (const float&);
			DataContainer operator -= (const double&);
			DataContainer operator -= (const std::int64_t&);
			DataContainer operator -= (const DataContainer&);

			DataContainer operator *= (const int&);
			DataContainer operator *= (const float&);
			DataContainer operator *= (const double&);
			DataContainer operator *= (const std::int64_t&);
			DataContainer operator *= (const DataContainer&);

			DataContainer operator /= (const int&);
			DataContainer operator /= (const float&);
			DataContainer operator /= (const double&);
			DataContainer operator /= (const std::int64_t&);
			DataContainer operator /= (const DataContainer&);

			DataContainer operator %= (const int&);
			DataContainer operator %= (const float&);
			DataContainer operator %= (const double&);
			DataContainer operator %= (const std::int64_t&);
			DataContainer operator %= (const DataContainer&);


			// Compare operators.
			DataContainer operator == (const int&);
			DataContainer operator == (const float&);
			DataContainer operator == (const double&);
			DataContainer operator == (const std::int64_t&);
			DataContainer operator == (const DataContainer&);

			DataContainer operator != (const int&);
			DataContainer operator != (const float&);
			DataContainer operator != (const double&);
			DataContainer operator != (const std::int64_t&);
			DataContainer operator != (const DataContainer&);

			DataContainer operator >= (const int&);
			DataContainer operator >= (const float&);
			DataContainer operator >= (const double&);
			DataContainer operator >= (const std::int64_t&);
			DataContainer operator >= (const DataContainer&);

			DataContainer operator <= (const int&);
			DataContainer operator <= (const float&);
			DataContainer operator <= (const double&);
			DataContainer operator <= (const std::int64_t&);
			DataContainer operator <= (const DataContainer&);

			DataContainer operator > (const int&);
			DataContainer operator > (const float&);
			DataContainer operator > (const double&);
			DataContainer operator > (const std::int64_t&);
			DataContainer operator > (const DataContainer&);

			DataContainer operator < (const int&);
			DataContainer operator < (const float&);
			DataContainer operator < (const double&);
			DataContainer operator < (const std::int64_t&);
			DataContainer operator < (const DataContainer&);

			// TODO: Implement more operators.

	};


};
};
