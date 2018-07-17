// Inexor entity system prototype
// (c)2018 Inexor

#include "DataContainer.hpp"

namespace inexor {
namespace entsys {

    MultipleDataTypeContainer::MultipleDataTypeContainer()
    {
        string_data = std::string("");
        int_data = 0;
    }


    DataContainer::DataContainer()
    {
        container_data_type = INEXOR_ENTSYS_DATA_TYPE_INVALID;
    }


    DataContainer::~DataContainer()
    {
    }

};
};