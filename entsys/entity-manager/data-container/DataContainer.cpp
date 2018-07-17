// Inexor entity system prototype
// (c)2018 Inexor

#include "DataContainer.hpp"

namespace inexor {
namespace entsys {

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
    
};
};
