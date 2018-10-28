// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <cstdint>
#include <thread>
#include <mutex>

#include "DataTypes.hpp"
#include "../return-codes/ReturnCodes.hpp"
#include "../templates/DataContainerTemplate.hpp"


namespace inexor {
namespace entity_system {


	// TODO: Instead of accessing maps by value every time a write operation occurs, 
    // why not store a pointer to the value pair of the map in the write operation?
    // This could speed the entity system very much!
	
    // A flexible, multiple purpose data container.
    class DataContainer : public DataContainerTemplate<std::string>,
						  public DataContainerTemplate<std::int64_t>,
		                  public DataContainerTemplate<int>,
		                  public DataContainerTemplate<double>,
		                  public DataContainerTemplate<float>,
		                  public DataContainerTemplate<bool>
					      // TODO: Add more data types here!
    {
        private:

			// Use C++11 initialisation instead of constructor.
            ENTSYS_DATA_TYPE data_container_data_type = ENTSYS_DATA_TYPE_UNDEFINED;
			
			// Multithreading safety mutex.
			//std::mutex container_mutex;

		public:

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
			

	};


};
};
