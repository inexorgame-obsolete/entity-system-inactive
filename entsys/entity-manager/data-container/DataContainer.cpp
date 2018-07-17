// Inexor entity system prototype
// (c)2018 Inexor

#include "DataContainer.hpp"

namespace inexor {
namespace entsys {

    DataContainer::DataContainer()
    {
        container_data_type = ENTSYS_DATA_TYPE_INVALID;
        reset_memory();
    }

    DataContainer::DataContainer(ENTSYS_DATA_TYPE data_type)
    {
        container_data_type = data_type;
        reset_memory();
    }

    void DataContainer::reset_memory()
    {
        int_data = 0;
        float_data = 0.0f;
        double_data = 0.0;
        boolean_data = false;
        string_data = std::string("");
    }

    DataContainer::DataContainer(const std::int64_t int_val)
    {
        container_data_type = ENTSYS_DATA_TYPE_INT;
        int_data = int_val;
    }

    DataContainer::DataContainer(const double double_val)
    {
        container_data_type = ENTSYS_DATA_TYPE_DOUBLE;
        double_data = double_val;
    }

    DataContainer::DataContainer(const float float_val)
    {
        container_data_type = ENTSYS_DATA_TYPE_FLOAT;
        float_data = float_val;
    }

    DataContainer::DataContainer(const bool bool_val)
    {
        container_data_type = ENTSYS_DATA_TYPE_BOOL;
        boolean_data = bool_val;
    }

    DataContainer::DataContainer(const std::string string_val)
    {
        container_data_type = ENTSYS_DATA_TYPE_STRING;
        string_data = string_val;
    }

    DataContainer::~DataContainer()
    {
    }

    void DataContainer::set(std::int64_t int_val)
    {
        if(ENTSYS_DATA_TYPE_INT == container_data_type) int_data = int_val;
        // else // TODO: Memory type mismaching! what to do now?
    }
    void DataContainer::set(double double_val)
    {
        if(ENTSYS_DATA_TYPE_DOUBLE == container_data_type) double_data = double_val;
        // else // TODO: Memory type mismaching! what to do now?
    }

    void DataContainer::set(float float_val)
    {
        if(ENTSYS_DATA_TYPE_FLOAT == container_data_type) float_data = float_val;
        // else // TODO: Memory type mismaching! what to do now?
    }

    void DataContainer::set(bool bool_val)
    {
        if(ENTSYS_DATA_TYPE_BOOL == container_data_type) boolean_data = bool_val;
        // else // TODO: Memory type mismaching! what to do now?
    }

    void DataContainer::set(std::string string_val)
    {
        if(ENTSYS_DATA_TYPE_STRING == container_data_type) string_data = string_val;
        // else // TODO: Memory type mismaching! what to do now?
    }

    const std::int64_t DataContainer::get_intval() const
    {
        if(ENTSYS_DATA_TYPE_INT == container_data_type) return int_data;
        // else // TODO: Memory type mismaching! what to do now?
        return 0;
    }

    const double DataContainer::get_doubleval() const
    {
        if(ENTSYS_DATA_TYPE_DOUBLE == container_data_type) return double_data;
        // else // TODO: Memory type mismaching! what to do now?
        return 0;
    }

    const float DataContainer::get_floatval() const
    {
        if(ENTSYS_DATA_TYPE_FLOAT == container_data_type) return float_data;
        // else // TODO: Memory type mismaching! what to do now?
        return 0;
    }

    const bool DataContainer::get_boolval() const
    {
        if(ENTSYS_DATA_TYPE_BOOL == container_data_type) return boolean_data;
        // else // TODO: Memory type mismaching! what to do now?
        return 0;
    }

    const std::string DataContainer::get_stringval() const
    {
        if(ENTSYS_DATA_TYPE_STRING == container_data_type) return string_data;
        // else // TODO: Memory type mismaching! what to do now?
        return 0;
    }

    const ENTSYS_DATA_TYPE DataContainer::get_data_type() const
    {
        return container_data_type;
    }

};
};
