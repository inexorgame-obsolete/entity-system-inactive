// Inexor entity system prototype
// (c)2018 Inexor

#include "DataContainer.hpp"

namespace inexor {
namespace entsys {


    void DataContainer::reset_memory()
    {
        int64_data = 0;
        integer_data = 0;
        float_data = 0.0f;
        double_data = 0.0;
        boolean_data = false;
        string_data = std::string("");
    }


    DataContainer::DataContainer(const ENTSYS_DATA_TYPE& data_type)
    {
        data_container_data_type = data_type;
        reset_memory();
    }


    DataContainer::DataContainer()
    {
        reset_memory();
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
    }

    
    const ENTSYS_RETURN_CODE DataContainer::set_data_type(const ENTSYS_DATA_TYPE& data_type)
    {
        data_container_data_type = data_type;
        return ENTSYS_RETURN_SUCCESS;
    }


    // Set methods.

    const DataContainer DataContainer::set(const std::int64_t int64_val)
    {
        if(ENTSYS_DATA_TYPE_BIG_INT == get_data_type())
        {
            int64_data = int64_val;
            return DataContainer(get_bigintval());
        }
        // else // TODO: Memory type mismaching! what to do now?
        return DataContainer(0);
    }

    const DataContainer DataContainer::set(const int int_val)
    {
        if(ENTSYS_DATA_TYPE_INT == get_data_type())
        {
            integer_data = int_val;
            return DataContainer(get_intval());
        }
        // else // TODO: Memory type mismaching! what to do now?
        return DataContainer(0);
    }

    const DataContainer DataContainer::set(const double double_val)
    {
        if(ENTSYS_DATA_TYPE_DOUBLE == get_data_type())
        {
            double_data = double_val;
            return DataContainer(get_doubleval());
        }
        // else // TODO: Memory type mismaching! what to do now?
        return DataContainer(0);
    }

    const DataContainer DataContainer::set(const float float_val)
    {
        if(ENTSYS_DATA_TYPE_FLOAT == get_data_type())
        {
            float_data = float_val;
            return DataContainer(get_floatval());
        }
        // else // TODO: Memory type mismaching! what to do now?
        return DataContainer(0);
    }

    const DataContainer DataContainer::set(const bool bool_val)
    {
        if(ENTSYS_DATA_TYPE_BOOL == get_data_type())
        {
            boolean_data = bool_val;
            return DataContainer(get_boolval());
        }
        // else // TODO: Memory type mismaching! what to do now?
        return DataContainer(false);
    }

    const DataContainer DataContainer::set(const std::string string_val)
    {
        if(ENTSYS_DATA_TYPE_STRING == get_data_type())
        {
            string_data = string_val;
            return DataContainer(get_stringval());
        }
        // else // TODO: Memory type mismaching! what to do now?
        return DataContainer(std::string(""));
    }


    // Only numeric data containers can execute math operations!
    // Check is this data container's type is numeric
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


    // Math operations.
    
    const DataContainer DataContainer::add(const DataContainer& addend)
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
        return DataContainer(std::int64_t(0));
    }

    const DataContainer DataContainer::sub(const DataContainer& minuend)
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
        return DataContainer(std::int64_t(0));
    }

    const DataContainer DataContainer::mul(const DataContainer& coeffizient)
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
        return DataContainer(std::int64_t(0));
    }

    const DataContainer DataContainer::div(const DataContainer& divisor)
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
        return DataContainer(std::int64_t(0));
    }

    
    // Overloaded operators.

    const DataContainer DataContainer::operator+(const DataContainer& addend)
    {
        return add(addend);
    }
    
    const DataContainer DataContainer::operator-(const DataContainer& minuend)
    {
        return sub(minuend);
    }

    const DataContainer DataContainer::operator*(const DataContainer& coeffizient)
    {
        return mul(coeffizient);
    }

    const DataContainer DataContainer::operator/(const DataContainer& divisor)
    {
        return div(divisor);
    }


    // Overloaded set operators.

    const DataContainer DataContainer::operator=(const int& new_int_val)
    {
        return set(new_int_val);
    }
    
    const DataContainer DataContainer::operator=(const double& new_double_val)
    {
        return set(new_double_val);
    }

    const DataContainer DataContainer::operator=(const float& new_float_val)
    {
        return set(new_float_val);
    }

    const DataContainer DataContainer::operator=(const bool& new_bool_val)
    {
        return set(new_bool_val);
    }

    const DataContainer DataContainer::operator=(const std::int64_t& new_bigint_val)
    {
        return set(new_bigint_val);
    }

    const DataContainer DataContainer::operator=(const std::string& new_string_val)
    {
        return set(new_string_val);
    }


    // Get methods.

    const int DataContainer::get_intval() const
    {
        if(ENTSYS_DATA_TYPE_INT == get_data_type()) return integer_data;
        // else // TODO: Memory type mismaching! what to do now?
        return 0;
    }

    const std::int64_t DataContainer::get_bigintval() const
    {
        if(ENTSYS_DATA_TYPE_BIG_INT == get_data_type()) return int64_data;
        // else // TODO: Memory type mismaching! what to do now?
        return 0;
    }

    const double DataContainer::get_doubleval() const
    {
        if(ENTSYS_DATA_TYPE_DOUBLE == get_data_type()) return double_data;
        // else // TODO: Memory type mismaching! what to do now?
        return 0;
    }

    const float DataContainer::get_floatval() const
    {
        if(ENTSYS_DATA_TYPE_FLOAT == get_data_type()) return float_data;
        // else // TODO: Memory type mismaching! what to do now?
        return 0;
    }

    const bool DataContainer::get_boolval() const
    {
        if(ENTSYS_DATA_TYPE_BOOL == get_data_type()) return boolean_data;
        // else // TODO: Memory type mismaching! what to do now?
        return 0;
    }

    const std::string DataContainer::get_stringval() const
    {
        if(ENTSYS_DATA_TYPE_STRING == get_data_type()) return string_data;
        // else // TODO: Memory type mismaching! what to do now?
        return 0;
    }


    const ENTSYS_DATA_TYPE DataContainer::get_data_type() const
    {
        return data_container_data_type;
    }

};
};
