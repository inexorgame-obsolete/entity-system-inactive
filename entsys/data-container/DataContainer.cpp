// Inexor entity system prototype
// (c)2018 Inexor

#include "DataContainer.hpp"


namespace inexor {
namespace entity_system {


    DataContainer::DataContainer(const ENTSYS_DATA_TYPE& param_data_type)
    {
		data_type = param_data_type;
    }


    DataContainer::DataContainer(const std::int64_t& int64val)
	{
		data_type = ENTSYS_DATA_TYPE_BIG_INT;
		data_int64 = int64val;
    }


    DataContainer::DataContainer(const double& double_val)
    {
		data_type = ENTSYS_DATA_TYPE_DOUBLE;
		data_double = double_val;
    }


    DataContainer::DataContainer(const float& float_val)
    {
		data_type = ENTSYS_DATA_TYPE_FLOAT;
		data_float = float_val;
    }


    DataContainer::DataContainer(const bool& bool_val)
    {
		data_type = ENTSYS_DATA_TYPE_BOOL;
		data_bool = bool_val;
    }


    DataContainer::DataContainer(const std::string& string_val)
    {
		data_type = ENTSYS_DATA_TYPE_STRING;
		data_string = string_val;
    }


    DataContainer::DataContainer(const int& int_val)
    {
		data_type = ENTSYS_DATA_TYPE_INT;
		data_int = int_val;
    }



    DataContainer::~DataContainer()
    {
		// TODO: Implement!
    }


    void DataContainer::reset_memory()
	{
		data_type = ENTSYS_DATA_TYPE_UNDEFINED;
		data_int64 = 0;
		data_string = "";
		data_double = 0.0;
		data_float = 0.0f;
		data_bool = false;
		data_int = 0;
		// TODO: Add more reset mechanisms here.
	}


    void DataContainer::set_data_type(const ENTSYS_DATA_TYPE& param_data_type)
    {
		reset_memory();
		data_type = param_data_type;
    }


    ENTSYS_DATA_TYPE DataContainer::get_data_type() const
    {
		return data_type;
    }

	

	DataContainer DataContainer::set_data(const DataContainer& data_container)
	{
		switch(data_container.get_data_type())
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
				set_data(data_container.get_int64());
				break;
			case ENTSYS_DATA_TYPE_BOOL:
				set_data(data_container.get_bool());
				break;
			case ENTSYS_DATA_TYPE_DOUBLE:
				set_data(data_container.get_double());
				break;
			case ENTSYS_DATA_TYPE_FLOAT:
				set_data(data_container.get_float());
				break;
			case ENTSYS_DATA_TYPE_INT:
				set_data(data_container.get_int());
				break;
			case ENTSYS_DATA_TYPE_STRING:
				set_data(data_container.get_string());
				break;
		}
		return *this;
	}

			
	DataContainer DataContainer::set_data(const std::int64_t& int64_val)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
				data_int64 = int64_val;
				break;
			case ENTSYS_DATA_TYPE_BOOL:
				data_bool = (int64_val > 0) ? true : false;
				break;
			case ENTSYS_DATA_TYPE_DOUBLE:
				data_double = static_cast<double>(int64_val);
				break;
			case ENTSYS_DATA_TYPE_FLOAT:
				data_float = static_cast<float>(int64_val);
				break;
			case ENTSYS_DATA_TYPE_INT:
				// TODO: We should not do this cast.
				data_int = static_cast<int>(int64_val);
				break;
			case ENTSYS_DATA_TYPE_STRING:
				data_string = std::to_string(int64_val);
				break;
		}
		return *this;
	}
	
	
	DataContainer DataContainer::set_data(const std::string& string_val)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
				// TODO: Convert std::string to std::int64_t!
				break;
			case ENTSYS_DATA_TYPE_BOOL:
				// TODO: Convert std::string to bool!
				break;
			case ENTSYS_DATA_TYPE_DOUBLE:
				// TODO: Convert std::string to double!
				break;
			case ENTSYS_DATA_TYPE_FLOAT:
				// TODO: Convert std::string to float!
				break;
			case ENTSYS_DATA_TYPE_INT:
				// TODO: Convert std::string to int!
				break;
			case ENTSYS_DATA_TYPE_STRING:
				data_string = string_val;
				break;
		}
		return this;
	}
	
	
	DataContainer DataContainer::set_data(const double& double_val)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
				data_int64 = static_cast<std::int64_t>(double_val);
				break;
			case ENTSYS_DATA_TYPE_BOOL:
				data_bool = (double_val > 0) ? true : false; 
				break;
			case ENTSYS_DATA_TYPE_DOUBLE:
				data_double = double_val;
				break;
			case ENTSYS_DATA_TYPE_FLOAT:
				data_float = static_cast<float>(double_val);
				break;
			case ENTSYS_DATA_TYPE_INT:
				data_int = static_cast<int>(double_val);
				break;
			case ENTSYS_DATA_TYPE_STRING:
				data_string = std::to_string(double_val);
				break;
		}
		return this;
	}


	DataContainer DataContainer::set_data(const float& float_val)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
				data_int64 = static_cast<std::int64_t>(float_val);
				break;
			case ENTSYS_DATA_TYPE_BOOL:
				data_bool = (float_val > 0) ? true : false;
				break;
			case ENTSYS_DATA_TYPE_DOUBLE:
				data_double = static_cast<double>(float_val);
				break;
			case ENTSYS_DATA_TYPE_FLOAT:
				data_float = float_val;
				break;
			case ENTSYS_DATA_TYPE_INT:
				data_int = static_cast<int>(float_val);
				break;
			case ENTSYS_DATA_TYPE_STRING:
				data_string = std::to_string(float_val);
				break;
		}
		return this;
	}


	DataContainer DataContainer::set_data(const bool& bool_val)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
				data_int = (bool_val) ? 1 : 0;
				break;
			case ENTSYS_DATA_TYPE_BOOL:
				data_bool = bool_val;
				break;
			case ENTSYS_DATA_TYPE_DOUBLE:
				data_double = (bool_val) ? 1.0 : 0.0;
				break;
			case ENTSYS_DATA_TYPE_FLOAT:
				data_float = (bool_val) ? 1.0f : 0.0f;
				break;
			case ENTSYS_DATA_TYPE_INT:
				data_int = (bool_val) ? 1 : 0;
				break;
			case ENTSYS_DATA_TYPE_STRING:
				data_string = (bool_val) ? std::string("1") : std::string("0");
				break;
		}
		return this;
	}


	DataContainer DataContainer::set_data(const int& int_val)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
				data_int64 = int_val;
				break;
			case ENTSYS_DATA_TYPE_BOOL:
				data_bool = (int_val > 0) ? 1 : 0;
				break;
			case ENTSYS_DATA_TYPE_DOUBLE:
				data_double = static_cast<double>(int_val);
				break;
			case ENTSYS_DATA_TYPE_FLOAT:
				data_float = static_cast<float>(int_val);
				break;
			case ENTSYS_DATA_TYPE_INT:
				data_int = int_val;
				break;
			case ENTSYS_DATA_TYPE_STRING:
				data_string = std::to_string(int_val);
				break;
		}
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

	

	DataContainer DataContainer::operator ++ (int)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				set_data(data_int64 + 1);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				set_data(data_int + 1);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				set_data(data_double + 1.0);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				set_data(data_float + 1.0f);
				break;
			}
			// Note: We can't increment std::string or bool!
		}				
		return *this;
	}


	DataContainer DataContainer::operator -- (int)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				set_data(data_int64 - 1);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				set_data(data_int - 1);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				set_data(data_double - 1.0);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				set_data(data_float - 1.0f);
				break;
			}
		}				
		return *this;
	}



	DataContainer DataContainer::operator + (const int& param_int)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				set_data(data_int64 + static_cast<int>(param_int));
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				set_data(data_int + static_cast<int>(param_int));
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				set_data(data_double + static_cast<int>(param_int));
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				set_data(data_float + static_cast<int>(param_int));
				break;
			}
		}				
		return *this;
	}


	DataContainer DataContainer::operator + (const float& param_float)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				set_data(data_int64 + static_cast<std::int64_t>(param_float));
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				return set_data(data_int + static_cast<int>(param_float));
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				return set_data(data_double + static_cast<double>(param_float));
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				return set_data(data_float + static_cast<float>(param_float));
				break;
			}
		}				
		return *this;	
	}


	DataContainer DataContainer::operator + (const double& param_double)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				set_data(data_int64 + static_cast<std::int64_t>(param_double));
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				set_data(data_int + static_cast<int>(param_double));
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				set_data(data_double + static_cast<double>(param_double));
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				set_data(data_float + static_cast<float>(param_double));
				break;
			}
		}				
		return *this;	
	}


	DataContainer DataContainer::operator + (const std::int64_t& param_int64)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				set_data(data_int64 + param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				set_data(data_int + static_cast<int>(param_int64));
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				set_data(data_double + static_cast<double>(param_int64));
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				set_data(data_float + static_cast<float>(param_int64));
				break;
			}
		}				
		return *this;
	}


	DataContainer DataContainer::operator + (const DataContainer& param_cont)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				std::int64_t container_value = param_cont.cast_to_int64();
				set_data(data_int64 + container_value);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				int container_value = param_cont.cast_to_int();
				set_data(data_int + static_cast<int>(container_value));
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				double container_value = param_cont.cast_to_double();
				set_data(data_double + static_cast<double>(container_value));
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				float container_value = param_cont.cast_to_float();
				set_data(data_float + static_cast<float>(container_value));
				break;
			}
		}				
		return *this;
	}



	DataContainer DataContainer::operator - (const int& param_int)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				set_data(data_int64 - static_cast<std::int64_t>(param_int));
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				set_data(data_int - static_cast<int>(param_int));
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				set_data(data_double - static_cast<double>(param_int));
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				set_data(data_float - static_cast<float>(param_int));
				break;
			}
		}				
		return *this;
	}
	
	
	DataContainer DataContainer::operator - (const float& param_float)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				set_data(data_int64 - static_cast<std::int64_t>(param_float));
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				set_data(data_int - static_cast<int>(param_float));
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				set_data(data_double - static_cast<double>(param_float));
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				set_data(data_float - static_cast<float>(param_float));
				break;
			}
		}				
		return *this;
	}


	DataContainer DataContainer::operator - (const double& param_double)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				set_data(data_int64 - static_cast<std::int64_t>(param_double));
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				set_data(data_int - static_cast<int>(param_double));
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				set_data(data_double - static_cast<double>(param_double));
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				set_data(data_float - static_cast<float>(param_double));
				break;
			}
		}				
		return *this;
	}


	DataContainer DataContainer::operator - (const std::int64_t& param_int64)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				set_data(data_int64 - static_cast<std::int64_t>(param_int64));
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				// TODO: We should not cast from big int to int.
				set_data(data_int- static_cast<int>(param_int64));
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				set_data(data_double - static_cast<double>(param_int64));
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				set_data(data_float - static_cast<float>(param_int64));
				break;
			}
		}
		return *this;
	}
	
	
	DataContainer DataContainer::operator - (const DataContainer& param_cont)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				std::int64_t param_int64 = param_cont.cast_to_int64();
				set_data(data_int64 - param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				int param_int = param_cont.cast_to_int();
				set_data(data_int - param_int);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				double param_double = param_cont.cast_to_double();
				set_data(data_double - param_double);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				float param_float = param_cont.cast_to_float();
				set_data(data_float - param_float);
				break;
			}
		}
		return *this;
	}



	DataContainer DataContainer::operator * (const int& param_int)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				std::int64_t param_int64 = static_cast<std::int64_t>(param_int);
				set_data(data_int64 * param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				set_data(data_int * param_int);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				float param_float = static_cast<float>(param_int);
				set_data(data_float * param_float);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				double param_double = static_cast<double>(param_int);
				set_data(data_double * param_double);
				break;
			}
		}
		return *this;
	}


	DataContainer DataContainer::operator * (const float& param_float)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				std::int64_t param_int64 = static_cast<std::int64_t>(param_float);
				set_data(data_int64 * param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				int param_int = static_cast<int>(param_float);
				set_data(data_int * param_int);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				set_data(data_float * param_float);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				double param_double = static_cast<double>(param_float);
				set_data(data_double * param_double);
				break;
			}
		}
		return *this;
	}


	DataContainer DataContainer::operator * (const double& param_double)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				std::int64_t param_int64 = static_cast<std::int64_t>(param_double);
				set_data(data_int64 * param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				int param_int = static_cast<int>(param_double);
				set_data(data_int * param_int);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				float param_float = static_cast<float>(param_double);
				set_data(data_float * param_float);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				set_data(data_double * param_double);
				break;
			}
		}
		return *this;
	}


	DataContainer DataContainer::operator * (const std::int64_t& param_int64)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				set_data(data_int64 * param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				int param_int = static_cast<int>(param_int64);
				set_data(data_int * param_int);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				float param_float = static_cast<float>(param_int64);
				set_data(data_float * param_float);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				double param_double = static_cast<double>(param_int64);
				set_data(data_double * param_double);
				break;
			}
		}
		return *this;
	}


	DataContainer DataContainer::operator * (const DataContainer& param_cont)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				std::int64_t param_int64 = param_cont.cast_to_int64();
				set_data(data_int64 * param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				int param_int = param_cont.cast_to_int();
				set_data(data_int * param_int);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				float param_float = param_cont.cast_to_float();
				set_data(data_float * param_float);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				double param_double = param_cont.cast_to_double();
				set_data(data_double * param_double);
				break;
			}
		}
		return *this;
	}


	DataContainer DataContainer::operator / (const int& param_int)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				std::int64_t param_int64 = static_cast<std::int64_t>(param_int);
				set_data(data_int64 / param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				set_data(data_int / param_int);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				float param_float = static_cast<float>(param_int);
				set_data(data_float / param_float);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				double param_double = static_cast<double>(param_int);
				set_data(data_double / param_double);
				break;
			}
		}
		return *this;
	}


	DataContainer DataContainer::operator / (const float& param_float)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				std::int64_t param_int64 = static_cast<std::int64_t>(param_float);
				set_data(data_int64 / param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				int param_int = static_cast<int>(param_float);
				set_data(data_int / param_int);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				set_data(data_float / param_float);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				double param_double = static_cast<double>(param_float);
				set_data(data_double / param_double);
				break;
			}
		}
		return *this;
	}


	DataContainer DataContainer::operator / (const double& param_double)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				std::int64_t param_int64 = static_cast<std::int64_t>(param_double);
				set_data(data_int64 / param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				int param_int = static_cast<int>(param_double);
				set_data(data_int / param_int);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				float param_float = static_cast<float>(param_double);
				set_data(data_float / param_float);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				set_data(data_double / param_double);
				break;
			}
		}
		return *this;
	}


	DataContainer DataContainer::operator / (const std::int64_t& param_int64)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				set_data(data_int64 / param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				int param_int = static_cast<int>(param_int64);
				set_data(data_int / param_int);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				float param_float = static_cast<float>(param_int64);
				set_data(data_float / param_float);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				double param_double = static_cast<double>(param_int64);
				set_data(data_double / param_double);
				break;
			}
		}
		return *this;
	}


	DataContainer DataContainer::operator / (const DataContainer& param_cont)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				std::int64_t param_int64 = param_cont.cast_to_int64();
				set_data(data_int64 / param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				int param_int = param_cont.cast_to_int();
				set_data(data_int / param_int);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				float param_float = param_cont.cast_to_float();
				set_data(data_float / param_float);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				double param_double = param_cont.cast_to_double();
				set_data(data_double / param_double);
				break;
			}
		}
		return *this;
	}



	DataContainer DataContainer::operator % (const int& param_int)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				std::int64_t param_int64 = static_cast<std::int64_t>(param_int);
				set_data(data_int64 % param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				set_data(data_int % param_int);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				float param_float = static_cast<float>(param_int);
				float result_float = fmod(data_float, param_float);
				set_data(result_float);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				double param_double = static_cast<double>(param_double);
				double result_double = fmod(data_double, param_double);
				set_data(result_double);
				break;
			}
		}
		return *this;
	}


	DataContainer DataContainer::operator % (const float& param_float)
	{
		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_BIG_INT:
			{
				std::int64_t param_int64 = static_cast<std::int64_t>(param_float);
				set_data(data_int64 % param_int64);
				break;
			}
			case ENTSYS_DATA_TYPE_INT:
			{
				// TODO: Is this a good idea?
				int result_int = fmod(data_int, param_float);
				set_data(result_int);
				break;
			}
			case ENTSYS_DATA_TYPE_FLOAT:
			{
				float param_float = static_cast<float>(param_int);
				float result_float = fmod(data_float, param_float);
				set_data(result_float);
				break;
			}
			case ENTSYS_DATA_TYPE_DOUBLE:
			{
				double param_double = static_cast<double>(param_double);
				double result_double = fmod(data_double, param_double);
				set_data(result_double);
				break;
			}
		}
		return *this;
	}


	DataContainer DataContainer::operator % (const double&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator % (const std::int64_t&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator % (const DataContainer&)
	{
		// TODO: Implement!
		return *this;
	}



	DataContainer DataContainer::operator += (const int&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator += (const float&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator += (const double&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator += (const std::int64_t&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator += (const DataContainer&)
	{
		// TODO: Implement!
		return *this;
	}



	DataContainer DataContainer::operator -= (const int&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator -= (const float&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator -= (const double&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator -= (const std::int64_t&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator -= (const DataContainer&)
	{
		// TODO: Implement!
		return *this;
	}


	
	DataContainer DataContainer::operator *= (const int&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator *= (const float&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator *= (const double&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator *= (const std::int64_t&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator *= (const DataContainer&)
	{
		// TODO: Implement!
		return *this;
	}



	DataContainer DataContainer::operator /= (const int&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator /= (const float&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator /= (const double&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator /= (const std::int64_t&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator /= (const DataContainer&)
	{
		// TODO: Implement!
		return *this;
	}



	DataContainer DataContainer::operator %= (const int&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator %= (const float&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator %= (const double&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator %= (const std::int64_t&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator %= (const DataContainer&)
	{
		// TODO: Implement!
		return *this;
	}



	DataContainer DataContainer::operator == (const int&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator == (const float&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator == (const double&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator == (const std::int64_t&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator == (const DataContainer&)
	{
		// TODO: Implement!
		return *this;
	}



	DataContainer DataContainer::operator != (const int&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator != (const float&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator != (const double&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator != (const std::int64_t&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator != (const DataContainer&)
	{
		// TODO: Implement!
		return *this;
	}



	DataContainer DataContainer::operator >= (const int&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator >= (const float&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator >= (const double&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator >= (const std::int64_t&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator >= (const DataContainer&)
	{
		// TODO: Implement!
		return *this;
	}



	DataContainer DataContainer::operator <= (const int&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator <= (const float&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator <= (const double&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator <= (const std::int64_t&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator <= (const DataContainer&)
	{
		// TODO: Implement!
		return *this;
	}



	DataContainer DataContainer::operator > (const int&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator > (const float&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator > (const double&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator > (const std::int64_t&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator > (const DataContainer&)
	{
		// TODO: Implement!
		return *this;
	}



	DataContainer DataContainer::operator < (const int&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator < (const float&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator < (const double&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator< (const std::int64_t&)
	{
		// TODO: Implement!
		return *this;
	}


	DataContainer DataContainer::operator < (const DataContainer&)
	{
		// TODO: Implement!
		return *this;
	}


	std::int64_t DataContainer::cast_to_int64() const
	{
		std::int64_t cast_value = 0;

		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_INT:
				cast_value = static_cast<std::int64_t>(data_int);
				break;

			case ENTSYS_DATA_TYPE_FLOAT:
				cast_value = static_cast<std::int64_t>(data_float);
				break;

			case ENTSYS_DATA_TYPE_DOUBLE:
				cast_value = static_cast<std::int64_t>(data_double);
				break;

			case ENTSYS_DATA_TYPE_BIG_INT:
				cast_value = data_int64;
				break;
		}
		return cast_value;
	}


	int DataContainer::cast_to_int() const
	{
		int cast_value = 0;

		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_INT:
				cast_value = static_cast<int>(data_int);
				break;

			case ENTSYS_DATA_TYPE_FLOAT:
				cast_value = static_cast<int>(data_float);
				break;

			case ENTSYS_DATA_TYPE_DOUBLE:
				cast_value = static_cast<int>(data_double);
				break;

			case ENTSYS_DATA_TYPE_BIG_INT:
				// This is not a good idea
				// We should not cast from int64 to int!
				cast_value = static_cast<int>(data_int64);
				break;
		}
		return cast_value;
	}


	double DataContainer::cast_to_double() const
	{
		double cast_value = 0.0;

		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_INT:
				cast_value = static_cast<double>(data_int);
				break;

			case ENTSYS_DATA_TYPE_FLOAT:
				cast_value = static_cast<double>(data_float);
				break;

			case ENTSYS_DATA_TYPE_DOUBLE:
				cast_value = static_cast<double>(data_double);
				break;

			case ENTSYS_DATA_TYPE_BIG_INT:
				// This is not a good idea
				// We should not cast from int64 to int!
				cast_value = static_cast<std::int64_t>(data_int64);
				break;
		}
		return cast_value;
	}


	float DataContainer::cast_to_float() const
	{
		float cast_value = 0.0f;

		switch(data_type)
		{
			case ENTSYS_DATA_TYPE_INT:
				cast_value = static_cast<float>(data_int);
				break;

			case ENTSYS_DATA_TYPE_FLOAT:
				cast_value = static_cast<float>(data_float);
				break;

			case ENTSYS_DATA_TYPE_DOUBLE:
				cast_value = static_cast<double>(data_double);
				break;

			case ENTSYS_DATA_TYPE_BIG_INT:
				cast_value = static_cast<std::int64_t>(data_int64);
				break;
		}
		return cast_value;
	}


};
};
