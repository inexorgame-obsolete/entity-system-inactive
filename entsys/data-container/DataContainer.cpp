// Inexor entity system prototype
// (c)2018 Inexor

#include "DataContainer.hpp"


namespace inexor {
namespace entsys {


    DataContainer::DataContainer(const ENTSYS_DATA_TYPE& data_type)
    {
        data_container_data_type = data_type;
    }


    DataContainer::DataContainer()
    {
    }


    DataContainer::DataContainer(const std::int64_t& int_val)
    {
        data_container_data_type = ENTSYS_DATA_TYPE_BIG_INT;
        int64_data = int_val;
    }


    DataContainer::DataContainer(const double& double_val)
    {
        data_container_data_type = ENTSYS_DATA_TYPE_DOUBLE;
        double_data = double_val;
    }


    DataContainer::DataContainer(const float& float_val)
    {
        data_container_data_type = ENTSYS_DATA_TYPE_FLOAT;
        float_data = float_val;
    }


    DataContainer::DataContainer(const bool& bool_val)
    {
        data_container_data_type = ENTSYS_DATA_TYPE_BOOL;
        boolean_data = bool_val;
    }


    DataContainer::DataContainer(const std::string& string_val)
    {
        data_container_data_type = ENTSYS_DATA_TYPE_STRING;
        string_data = string_val;
    }


    DataContainer::DataContainer(const int& int_val)
    {
        data_container_data_type = ENTSYS_DATA_TYPE_INT;
        integer_data = int_val;
    }


    DataContainer::~DataContainer()
    {
        // TODO: Implement destructor.
    }

    
    ENTSYS_RETURN_CODE DataContainer::set_data_type(const ENTSYS_DATA_TYPE& data_type)
    {
        data_container_data_type = data_type;
        return ENTSYS_RETURN_SUCCESS;
    }


    ENTSYS_DATA_TYPE DataContainer::get_data_type() const
    {
        return data_container_data_type;
    }


    DataContainer DataContainer::set(const std::int64_t& int64_val)
    {
        int64_data = int64_val;
        return DataContainer(int64_data);
    }


    DataContainer DataContainer::set(const int& int_val)
    {
        integer_data = int_val;
        return DataContainer(integer_data);
    }


    DataContainer DataContainer::set(const double& double_val)
    {
        double_data = double_val;
        return DataContainer(double_data);
    }


    DataContainer DataContainer::set(const float& float_val)
    {
        float_data = float_val;
        return DataContainer(float_data);
    }


    DataContainer DataContainer::set(const bool& bool_val)
    {
        boolean_data = bool_val;
        return DataContainer(boolean_data);
    }


    DataContainer DataContainer::set(const std::string& string_val)
    {
        string_data = string_val;
        return DataContainer(string_data);
    }


    bool DataContainer::data_container_type_is_numeric()
    {
        switch(get_data_type())
        {
            case ENTSYS_DATA_TYPE_INT:
            case ENTSYS_DATA_TYPE_BIG_INT:
            case ENTSYS_DATA_TYPE_FLOAT:
            case ENTSYS_DATA_TYPE_DOUBLE:
            {
                return true;
                break;
            }
        }
        return false;
    }


    DataContainer DataContainer::add(const DataContainer& addend)
    {
        if(data_container_type_is_numeric())
        {
            switch(get_data_type())
            {
                case ENTSYS_DATA_TYPE_INT:
                {
                    integer_data += addend.get_intval();
                    return DataContainer(get_intval());
                    break;
                }
                case ENTSYS_DATA_TYPE_FLOAT:
                {
                    float_data += addend.get_floatval();
                    return DataContainer(get_floatval());
                    break;
                }
                case ENTSYS_DATA_TYPE_DOUBLE:
                {
                    double_data += addend.get_doubleval();
                    return DataContainer(get_doubleval());
                    break;
                }
            }
        }
        // TODO: DISCUSS: Is this a good idea ?
        return DataContainer(0);
    }


    DataContainer DataContainer::sub(const DataContainer& minuend)
    {
        if(data_container_type_is_numeric())
        {
            switch(get_data_type())
            {
                case ENTSYS_DATA_TYPE_INT:
                {
                    integer_data -= minuend.get_intval();
                    return DataContainer(get_intval());
                    break;
                }
                case ENTSYS_DATA_TYPE_FLOAT:
                {
                    float_data -= minuend.get_floatval();
                    return DataContainer(get_floatval());
                    break;
                }
                case ENTSYS_DATA_TYPE_DOUBLE:
                {
                    double_data -= minuend.get_doubleval();
                    return DataContainer(get_doubleval());
                    break;
                }
            }
        }
        return DataContainer(0);
    }


    DataContainer DataContainer::mul(const DataContainer& coeffizient)
    {
        if(data_container_type_is_numeric())
        {
            switch(get_data_type())
            {
                case ENTSYS_DATA_TYPE_INT:
                {
                    integer_data *= coeffizient.get_intval();
                    return DataContainer(get_intval());
                    break;
                }
                case ENTSYS_DATA_TYPE_FLOAT:
                {
                    float_data *= coeffizient.get_floatval();
                    return DataContainer(get_floatval());
                    break;
                }
                case ENTSYS_DATA_TYPE_DOUBLE:
                {
                    double_data *= coeffizient.get_doubleval();
                    return DataContainer(get_doubleval());
                    break;
                }
            }
        }
        return DataContainer(0);
    }


    DataContainer DataContainer::div(const DataContainer& divisor)
    {
        if(data_container_type_is_numeric())
        {
            switch(get_data_type())
            {
                case ENTSYS_DATA_TYPE_INT:
                {
                    integer_data /= divisor.get_intval();
                    return DataContainer(get_intval());
                    break;
                }
                case ENTSYS_DATA_TYPE_FLOAT:
                {
                    float_data /= divisor.get_floatval();
                    return DataContainer(get_floatval());
                    break;
                }
                case ENTSYS_DATA_TYPE_DOUBLE:
                {
                    double_data /= divisor.get_doubleval();
                    return DataContainer(get_doubleval());
                    break;
                }
            }
        }
        return DataContainer(0);
    }


    DataContainer DataContainer::operator+(const DataContainer& addend)
    {
        return add(addend);
    }

    
    DataContainer DataContainer::operator-(const DataContainer& minuend)
    {
        return sub(minuend);
    }


    DataContainer DataContainer::operator*(const DataContainer& coeffizient)
    {
        return mul(coeffizient);
    }


    DataContainer DataContainer::operator/(const DataContainer& divisor)
    {
        return div(divisor);
    }


    DataContainer DataContainer::operator=(const int& new_int_val)
    {
        return set(new_int_val);
    }
    
    
    DataContainer DataContainer::operator=(const double& new_double_val)
    {
        return set(new_double_val);
    }


    DataContainer DataContainer::operator=(const float& new_float_val)
    {
        return set(new_float_val);
    }


    DataContainer DataContainer::operator=(const bool& new_bool_val)
    {
        return set(new_bool_val);
    }


    DataContainer DataContainer::operator=(const std::int64_t& new_bigint_val)
    {
        return set(new_bigint_val);
    }


    DataContainer DataContainer::operator=(const std::string& new_string_val)
    {
        return set(new_string_val);
    }


    int DataContainer::get_intval() const
    {
        return integer_data;
    }


    std::int64_t DataContainer::get_bigintval() const
    {
        return int64_data;
    }


    double DataContainer::get_doubleval() const
    {
        return double_data;
    }


    float DataContainer::get_floatval() const
    {
        return float_data;
    }


    bool DataContainer::get_boolval() const
    {
        return boolean_data;
    }


    std::string DataContainer::get_stringval() const
    {
        return string_data;
    }


};
};
