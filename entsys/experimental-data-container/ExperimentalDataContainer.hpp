// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_EXPERIMENTAL_DATA_CONTAINER_CLASS_HEADER
#define INEXOR_ENTSYS_EXPERIMENTAL_DATA_CONTAINER_CLASS_HEADER

#include <any>
#include <string>
#include <iostream>
#include <utility>

#include "../data-container/DataTypes.hpp"
#include "../return-codes/ReturnCodes.hpp"


namespace inexor {
namespace entity_system {

	class ExperimentalDataContainer
	{
		private:

			ENTSYS_DATA_TYPE data_container_data_type;

			std::any data_container;

		public:

			ExperimentalDataContainer();
			ExperimentalDataContainer(const ENTSYS_DATA_TYPE& data_type);
			ExperimentalDataContainer(const std::string&);
			ExperimentalDataContainer(const double&);
			ExperimentalDataContainer(const float&);
			ExperimentalDataContainer(const bool&);
			ExperimentalDataContainer(const int&);

			~ExperimentalDataContainer();

			void set_data_type(const ENTSYS_DATA_TYPE&);

			ENTSYS_DATA_TYPE get_data_type() const;


			ExperimentalDataContainer set(const std::string&);
			ExperimentalDataContainer set(const double&);
			ExperimentalDataContainer set(const float&);
			ExperimentalDataContainer set(const bool&);
			ExperimentalDataContainer set(const int&);


			ExperimentalDataContainer operator=(const int&);
			ExperimentalDataContainer operator=(const double&);
			ExperimentalDataContainer operator=(const float&);
			ExperimentalDataContainer operator=(const bool&);
			ExperimentalDataContainer operator=(const std::string&);


			void get(std::string&) const;
			void get(double&) const;
			void get(float&) const;
			void get(bool&) const;
			void get(int&) const;

	};

};
};

#endif // INEXOR_ENTSYS_EXPERIMENTAL_DATA_CONTAINER_CLASS_HEADER
