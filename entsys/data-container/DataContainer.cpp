// Inexor entity system prototype
// (c)2018 Inexor

#include "DataContainer.hpp"


namespace inexor {
namespace entity_system {


    DataContainer::DataContainer(const ENTSYS_DATA_TYPE& data_type)
    {
		std::lock_guard<std::mutex> lock(data_container_mutex);
        data_container_data_type = data_type;
    }


	void DataContainer::reset_memory()
	{
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
		data_container_data_type = ENTSYS_DATA_TYPE_UNDEFINED;
		string_data = "";
		int64_data = 0;
		integer_data = 0;
		double_data = 0.0;
		float_data = 0.0f;
		boolean_data = false;
	}


    DataContainer::DataContainer(const std::int64_t& int_val)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
		data_container_data_type = ENTSYS_DATA_TYPE_BIG_INT;
        int64_data = int_val;
    }


    DataContainer::DataContainer(const double& double_val)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
		data_container_data_type = ENTSYS_DATA_TYPE_DOUBLE;
        double_data = double_val;
    }


    DataContainer::DataContainer(const float& float_val)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
		data_container_data_type = ENTSYS_DATA_TYPE_FLOAT;
        float_data = float_val;
    }


    DataContainer::DataContainer(const bool& bool_val)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
		data_container_data_type = ENTSYS_DATA_TYPE_BOOL;
        boolean_data = bool_val;
    }


    DataContainer::DataContainer(const std::string& string_val)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
		data_container_data_type = ENTSYS_DATA_TYPE_STRING;
        string_data = string_val;
    }


    DataContainer::DataContainer(const int& int_val)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
		data_container_data_type = ENTSYS_DATA_TYPE_INT;
        integer_data = int_val;
    }


    DataContainer::~DataContainer()
    {
		// TODO: Implement!
    }

    
    ENTSYS_RESULT DataContainer::set_data_type(const ENTSYS_DATA_TYPE& data_type)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
        data_container_data_type = data_type;
        return ENTSYS_SUCCESS;
    }


    ENTSYS_DATA_TYPE DataContainer::get_data_type() const
    {
        return data_container_data_type;
    }
	

    const std::int64_t& DataContainer::set(const std::int64_t& int64_val)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
		int64_data = int64_val;
		return int64_val;
    }


    const int& DataContainer::set(const int& int_val)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
        integer_data = int_val;
		return integer_data;
    }


    const double& DataContainer::set(const double& double_val)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
        double_data = double_val;
		return double_data;
    }


    const float& DataContainer::set(const float& float_val)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
		float_data = float_val;
		return float_data;
    }


    const bool& DataContainer::set(const bool& bool_val)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
		boolean_data = bool_val;
		return boolean_data;
    }


    const std::string& DataContainer::set(const std::string& string_val)
    {
		// Lock mutex using lock guards to ensure thread-safety.
		std::lock_guard<std::mutex> lock(data_container_mutex);
		string_data = string_val;
        return string_data;
    }


    const int& DataContainer::operator=(const int& new_int_val)
    {
        return set(new_int_val);
    }
    
    
    const double& DataContainer::operator=(const double& new_double_val)
    {
        return set(new_double_val);
    }


    const float& DataContainer::operator=(const float& new_float_val)
    {
        return set(new_float_val);
    }


    const bool& DataContainer::operator=(const bool& new_bool_val)
    {
        return set(new_bool_val);
    }


    const std::int64_t& DataContainer::operator=(const std::int64_t& new_bigint_val)
    {
        return set(new_bigint_val);
    }


    const std::string& DataContainer::operator=(const std::string& new_string_val)
    {
        return set(new_string_val);
    }


	const int DataContainer::get_int() const
	{
		return integer_data;
	}
	

	const bool DataContainer::get_bool() const
	{
		return boolean_data;
	}


	const float DataContainer::get_float() const
	{
		return float_data;
	}

	const double DataContainer::get_double() const
	{
		return double_data;
	}
	

	const std::string DataContainer::get_string() const
	{
		return string_data;
	}
	

	const std::int64_t DataContainer::get_int64() const
	{
		return int64_data;
	}


};
};
