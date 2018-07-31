// Inexor entity system prototype
// (c)2018 Inexor

#include "ExperimentalDataContainer.hpp"


namespace inexor {
namespace entity_system {


	ExperimentalDataContainer::ExperimentalDataContainer()
	{
	}


	ExperimentalDataContainer::ExperimentalDataContainer(int value_int)
	{
		try
		{
			data_container = value_int;
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
	}


	ExperimentalDataContainer::ExperimentalDataContainer(const std::string& value_string)
	{
		try
		{
			data_container = value_string;
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	
	ExperimentalDataContainer::ExperimentalDataContainer(const double& value_double)
	{
		try
		{
			data_container = value_double;
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	
	ExperimentalDataContainer::ExperimentalDataContainer(const float& value_float)
	{
		try
		{
			data_container = value_float;
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	
	ExperimentalDataContainer::ExperimentalDataContainer(const bool& value_bool)
	{
		try
		{
			data_container = value_bool;
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	
	ExperimentalDataContainer::ExperimentalDataContainer(const int& value_int)
	{
		try
		{
			data_container = value_int;
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	
	ExperimentalDataContainer::~ExperimentalDataContainer()
	{
	}


};
};
