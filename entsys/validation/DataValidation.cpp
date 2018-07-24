// Inexor entity system prototype
// (c)2018 Inexor

#include "DataValidation.hpp"


namespace inexor {
namespace entsys {


    DataValidation::DataValidation()
    {
    }


    DataValidation::~DataValidation()
    {
    }

    
    bool DataValidation::isvalid()
    {
        return data_is_valid;
    }


};
};
