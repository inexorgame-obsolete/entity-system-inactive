// Inexor entity system prototype
// (c)2018 Inexor

#include "DataContainer.hpp"


namespace inexor {
namespace entity_system {


    DataContainer::DataContainer(const ENTSYS_DATA_TYPE& data_type)
    {
		data_container_data_type = data_type;
    }


    DataContainer::DataContainer(const std::int64_t& int64val)
	{
		data_container_data_type = ENTSYS_DATA_TYPE_BIG_INT;
		data_int64 = int64val;
    }


    DataContainer::DataContainer(const double& double_val)
    {
		data_container_data_type = ENTSYS_DATA_TYPE_DOUBLE;
		data_double = double_val;
    }


    DataContainer::DataContainer(const float& float_val)
    {
		data_container_data_type = ENTSYS_DATA_TYPE_FLOAT;
		data_float = float_val;
    }


    DataContainer::DataContainer(const bool& bool_val)
    {
		data_container_data_type = ENTSYS_DATA_TYPE_BOOL;
		data_bool = bool_val;
    }


    DataContainer::DataContainer(const std::string& string_val)
    {
		data_container_data_type = ENTSYS_DATA_TYPE_STRING;
		data_string = string_val;
    }


    DataContainer::DataContainer(const int& int_val)
    {
		data_container_data_type = ENTSYS_DATA_TYPE_INT;
		data_int = int_val;
    }


    DataContainer::~DataContainer()
    {
    }


    void DataContainer::reset_memory()
	{
		data_container_data_type = ENTSYS_DATA_TYPE_UNDEFINED;
		data_int64 = 0;
		data_string = "";
		data_double = 0.0;
		data_float = 0.0f;
		data_bool = false;
		data_int = 0;
	}


    void DataContainer::set_data_type(const ENTSYS_DATA_TYPE& data_type)
    {
		reset_memory();
		data_container_data_type = data_type;
    }


    ENTSYS_DATA_TYPE DataContainer::get_data_type() const
    {
		return data_container_data_type;
    }

	
	DataContainer DataContainer::set_data(const DataContainer& data_container)
	{
		switch(data_container.get_data_type())
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
				return set_data(data_container.get_int64());
				break;
			case ENTSYS_DATA_TYPE_BOOL:
				return set_data(data_container.get_bool());
				break;
			case ENTSYS_DATA_TYPE_DOUBLE:
				return set_data(data_container.get_double());
				break;
			case ENTSYS_DATA_TYPE_FLOAT:
				return set_data(data_container.get_float());
				break;
			case ENTSYS_DATA_TYPE_INT:
				return set_data(data_container.get_int());
				break;
			case ENTSYS_DATA_TYPE_STRING:
				return set_data(data_container.get_string());
				break;
		}
		return DataContainer(ENTSYS_DATA_TYPE_UNDEFINED);
	}

			
	DataContainer DataContainer::set_data(const std::int64_t& int64_val)
	{
		data_int64 = int64_val;
		return *this;
	}
	
	
	DataContainer DataContainer::set_data(const std::string& string_val)
	{
		data_string = string_val;
		return this;
	}
	
	
	DataContainer DataContainer::set_data(const double& double_val)
	{
		data_double = double_val;
		return this;
	}


	DataContainer DataContainer::set_data(const float& float_val)
	{
		data_float = float_val;
		return this;
	}


	DataContainer DataContainer::set_data(const bool& bool_val)
	{
		data_bool = bool_val;
		return this;
	}


	DataContainer DataContainer::set_data(const int& int_val)
	{
		data_int = int_val;
		return *this;
	}

	
	std::int64_t DataContainer::get_int64() const
	{
		return data_int64;
	}


	std::string DataContainer::get_string() const
	{
		return data_string;
	}


	double DataContainer::get_double() const
	{
		return data_double;
	}


	float DataContainer::get_float() const
	{
		return data_float;
	}


	bool DataContainer::get_bool() const
	{
		return data_bool;
	}


	int DataContainer::get_int() const
	{
		return data_int;
	}


	DataContainer DataContainer::operator = (const DataContainer& cont)
	{
		return set_data(cont);
	}


	DataContainer DataContainer::operator = (const std::int64_t& int64val)
	{
		return set_data(int64val);
	}


	DataContainer DataContainer::operator = (const std::string& strval)
	{
		return set_data(strval);
	}


	DataContainer DataContainer::operator = (const double& dblval)
	{
		return set_data(dblval);
	}


	DataContainer DataContainer::operator = (const float& fltval)
	{
		return set_data(fltval);
	}
	
	
	DataContainer DataContainer::operator = (const bool& boolval)
	{
		return set_data(boolval);
	}


	DataContainer DataContainer::operator = (const int& intval)
	{
		return set_data(intval);
	}

	
	DataContainer DataContainer::operator++(int)
	{
		switch(data_container_data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				data_int64++;
				return set_data(data_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				data_int++;
				return set_data(data_int);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				data_double++;
				return set_data(data_double);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				data_float++;
				return set_data(data_float);
				break;
			}
			// Note: We can't increment std::string or bool!
		}				
		return *this;
	}


};
};
