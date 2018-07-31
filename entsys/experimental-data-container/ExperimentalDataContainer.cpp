// Inexor entity system prototype
// (c)2018 Inexor

#include "ExperimentalDataContainer.hpp"


namespace inexor {
namespace entity_system {


	ExperimentalDataContainer::ExperimentalDataContainer()
	{
	}

	    
	ExperimentalDataContainer::ExperimentalDataContainer(const ENTSYS_DATA_TYPE& data_type)
	{
		try
		{
			data_container_data_type = data_type;
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
			data_container_data_type = ENTSYS_DATA_TYPE_STRING;
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
			data_container_data_type = ENTSYS_DATA_TYPE_DOUBLE;
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
			data_container_data_type = ENTSYS_DATA_TYPE_FLOAT;
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
			data_container_data_type = ENTSYS_DATA_TYPE_BOOL;
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
			data_container_data_type = ENTSYS_DATA_TYPE_INT;
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


	void ExperimentalDataContainer::set_data_type(const ENTSYS_DATA_TYPE& data_type)
	{
		data_container_data_type = data_type;
	}


	ExperimentalDataContainer ExperimentalDataContainer::set(const std::string& value_string)
	{
		try
		{
			data_container_data_type = ENTSYS_DATA_TYPE_STRING;
			data_container = value_string;
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
		return ExperimentalDataContainer(std::any_cast<std::string>(data_container));
	}


	ExperimentalDataContainer ExperimentalDataContainer::set(const double& value_double)
	{
		try
		{
			data_container_data_type = ENTSYS_DATA_TYPE_DOUBLE;
			data_container = value_double;
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
		return ExperimentalDataContainer(std::any_cast<double>(data_container));
	}


	ExperimentalDataContainer ExperimentalDataContainer::set(const float& value_float)
	{
		try
		{
			data_container_data_type = ENTSYS_DATA_TYPE_FLOAT;
			data_container = value_float;
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
		return ExperimentalDataContainer(std::any_cast<float>(data_container));
	}


	ExperimentalDataContainer ExperimentalDataContainer::set(const bool& value_bool)
	{
		try
		{
			data_container_data_type = ENTSYS_DATA_TYPE_BOOL;
			data_container = value_bool;
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
		return ExperimentalDataContainer(std::any_cast<bool>(data_container));
	}


	ExperimentalDataContainer ExperimentalDataContainer::set(const int& value_int)
	{
		try
		{
			data_container_data_type = ENTSYS_DATA_TYPE_INT;
			data_container = value_int;
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
		return ExperimentalDataContainer(std::any_cast<int>(data_container));
	}


	ExperimentalDataContainer ExperimentalDataContainer::operator=(const int& value_int)
	{
		return set(value_int);
	}
	
	
	ExperimentalDataContainer ExperimentalDataContainer::operator=(const double& value_double)
	{
		return set(value_double);
	}
	
	
	ExperimentalDataContainer ExperimentalDataContainer::operator=(const float& value_float)
	{
		return set(value_float);
	}
	
	
	ExperimentalDataContainer ExperimentalDataContainer::operator=(const bool& value_bool)
	{
		return set(value_bool);
	}


	ExperimentalDataContainer ExperimentalDataContainer::operator=(const std::string& value_string)
	{
		return set(value_string);
	}


	ENTSYS_DATA_TYPE ExperimentalDataContainer::get_data_type() const
	{
		return data_container_data_type;
	}


	void ExperimentalDataContainer::get(std::string& reference_string) const
	{
		try
		{
			// TODO: Debug
			reference_string = std::any_cast<std::string>(data_container);
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
	}


	void ExperimentalDataContainer::get(double& reference_double) const
	{
		try
		{
			// TODO: Debug
			reference_double = std::any_cast<double>(data_container);
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
	}


	void ExperimentalDataContainer::get(float& reference_float) const
	{
		try
		{
			// TODO: Debug
			reference_float = std::any_cast<float>(data_container);
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
	}


	void ExperimentalDataContainer::get(bool& reference_bool) const
	{
		try
		{
			// TODO: Debug
			reference_bool = std::any_cast<bool>(data_container);
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
	}


	void ExperimentalDataContainer::get(int& reference_int) const
	{
		try
		{
			// TODO: Debug
			reference_int = std::any_cast<int>(data_container);
		}
		catch (const std::bad_any_cast& e)
		{
			std::cout << e.what() << std::endl;
		}
	}


};
};
