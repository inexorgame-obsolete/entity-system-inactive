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
	
    /// A multiple purpose data container which can hold data of various types.
    class DataContainer
    {
        private:

			// Use C++11 initialisation style instead of constructor list.

			/// The data type of this data container.
            ENTSYS_DATA_TYPE data_type = ENTSYS_DATA_TYPE_UNDEFINED;

			/// A 64 bit integer variable for storing data in the container.
			std::int64_t data_int64 = 0;

			/// A std::string variable for storing data in the container.
			std::string data_string = "";

			/// A double variable for storing data in the container.
			double data_double = 0.0;

			/// A float variable for storing data in the container.
			float data_float = 0.0f;

			/// A boolean variable for storing data in the container.
			bool data_bool = false;

			/// An integer variable for storing data in the container.
			int data_int = 0;
			
			// Multithreading safety mutex.
			//std::mutex container_mutex;

		public:

			// Don't use explicit keyword to prevent implicit conversion!

			/// Constructor.
			/// @param param_data_type The data type of this data container.
            DataContainer(const ENTSYS_DATA_TYPE&);

			/// Constructor.
			/// @param int64val A 64 bit integer value for initialisation of the data container.
            DataContainer(const std::int64_t&);

			/// Constructor.
			/// @param string_val A std::string value for initialisation of the data container.
			DataContainer(const std::string&);

			/// Constructor.
			/// @param double_val A double value for initialisation of the data container.
            DataContainer(const double&);

			/// Constructor.
			/// @param float_val A float value for initialisation of the data container.
			DataContainer(const float&);

			/// Constructor.
			/// @param bool_val A float value for initialisation of the data container.
			DataContainer(const bool&);

			/// Constructor.
			/// @param int_val An integer value for initialisation of the data container.
			DataContainer(const int&);

			/// Destructor.
            ~DataContainer();

			/// Sets the data type of the container.
			/// @param param_data_type The new data type of the data container.
			void set_data_type(const ENTSYS_DATA_TYPE&);

			/// Returns the current data type of the data container.
			/// @return The data type of this data container in the ENTSYS_DATA_TYPE format.
			ENTSYS_DATA_TYPE get_data_type() const;

			/// Resets all memory.
			void reset_memory();

			// Get methods for memory access.
			// In C++ we can't have functions which only differ
			// in their return value. There is no general way of
			// implementing 'get_data()'.

			/// Returns the data container's 64 bit integer variable.
			/// @return the data container's 64 bit integer variable.
			std::int64_t get_int64() const;

			/// Returns the data container's std::string variable.
			/// @return the data container's std::string variable.
			std::string get_string() const;

			/// Returns the data container's double variable.
			/// @return the data container's double variable.
			double get_double() const;
			
			/// Returns the data container's float variable.
			/// @return the data container's float variable.
			float get_float() const;

			/// Returns the data container's bool variable.
			/// @return the data container's bool variable.
			bool get_bool() const;

			/// Returns the data container's integer variable.
			/// @return the data container's integer variable.
			int get_int() const;

			/// Casts the container's data to 64 bit int.
			/// @return A 64 bit integer which contains
			/// which contains the casted memory.
			std::int64_t cast_to_int64() const;
			
			/// Casts the container's data to int.
			/// @return An integer variable which
			/// contains the casted memory.
			int cast_to_int() const;

			/// Casts the container's data to double.
			/// @return A double variable which
			/// contains the casted memory.
			double cast_to_double() const;

			/// Casts the container's data to float.
			/// @return A float variable which
			/// contains the casted memory.
			float cast_to_float() const;

			/// Sets the data of the container.
			/// @param data_container The source data container from which the memory will be copied.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer set_data(const DataContainer&);

			/// Sets the data of the container.
			/// @param int64_val The new 64 bit integer value of the data container.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer set_data(const std::int64_t&);

			/// Sets the data of the container.
			/// @param string_val The new std::string value of the data container.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer set_data(const std::string&);

			/// Sets the data of the container.
			/// @param double_val The new double value of the data container.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer set_data(const double&);

			/// Sets the data of the container.
			/// @param float_val The new float value of the data container.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer set_data(const float&);

			/// Sets the data of the container.
			/// @param bool_val The new bool value of the data container.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer set_data(const bool&);

			/// Sets the data of the container.
			/// @param int_val The new int value of the data container.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer set_data(const int&);

			/// Assign operator.
			/// @param cont The source data container from which data will be copied.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer operator = (const DataContainer&);

			/// Assign operator.
			/// @param int64val The source 64 bit integer from which data will be copied.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer operator = (const std::int64_t&);

			/// Assign operator.
			/// @param strval The source std::string from which data will be copied.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer operator = (const std::string&);

			/// Assign operator.
			/// @param dblval The source double from which data will be copied.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer operator = (const double&);

			/// Assign operator.
			/// @param fltval The source float from which data will be copied.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer operator = (const float&);

			/// Assign operator.
			/// @param boolval The source bool from which data will be copied.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer operator = (const bool&);

			/// Assign operator.
			/// @param intval The source int from which data will be copied.
			/// @return *this (The dereferenced value of the this pointer).
			DataContainer operator = (const int&);
			

	};


};
};
