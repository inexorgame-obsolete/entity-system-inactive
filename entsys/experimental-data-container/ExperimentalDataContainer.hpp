// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_EXPERIMENTAL_DATA_CONTAINER_CLASS_HEADER
#define INEXOR_ENTSYS_EXPERIMENTAL_DATA_CONTAINER_CLASS_HEADER

#include <any>
#include <string>
#include <iostream>
#include <utility>

#include "../data-container/DataTypes.hpp"


namespace inexor {
namespace entity_system {

	class ExperimentalDataContainer
	{
		private:

			ENTSYS_DATA_TYPE data_container_data_type;

			// Is this defined yet?
			std::any data_container;

		public:

			ExperimentalDataContainer();
			//ExperimentalDataContainer(const std::int64_t&);
			ExperimentalDataContainer(int value_int);
			ExperimentalDataContainer(const std::string&);
			ExperimentalDataContainer(const double&);
			ExperimentalDataContainer(const float&);
			ExperimentalDataContainer(const bool&);
			ExperimentalDataContainer(const int&);

			~ExperimentalDataContainer();


	};

};
};

#endif // INEXOR_ENTSYS_EXPERIMENTAL_DATA_CONTAINER_CLASS_HEADER
