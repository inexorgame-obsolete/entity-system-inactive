// Inexor entity system prototype
// (c)2018 Inexor

#include "DataContainer.hpp"


namespace inexor {
namespace entity_system {


    DataContainer::DataContainer(const ENTSYS_DATA_TYPE& data_type) :
		DataContainerTemplate<std::string>::DataContainerTemplate(std::string("")),
		DataContainerTemplate<std::int64_t>::DataContainerTemplate(std::int64_t(0)),
		DataContainerTemplate<int>::DataContainerTemplate(0),
		DataContainerTemplate<double>::DataContainerTemplate(0.0),
		DataContainerTemplate<float>::DataContainerTemplate(0.0f),
		DataContainerTemplate<bool>::DataContainerTemplate(false)
    {
		data_container_data_type = data_type;
    }


    DataContainer::DataContainer(const std::int64_t& int64val) :
		DataContainerTemplate<std::string>::DataContainerTemplate(std::string("")),
		DataContainerTemplate<std::int64_t>::DataContainerTemplate(std::int64_t(int64val)),
		DataContainerTemplate<int>::DataContainerTemplate(0),
		DataContainerTemplate<double>::DataContainerTemplate(0.0),
		DataContainerTemplate<float>::DataContainerTemplate(0.0f),
		DataContainerTemplate<bool>::DataContainerTemplate(false)
	{
		data_container_data_type = ENTSYS_DATA_TYPE_BIG_INT;
    }


    DataContainer::DataContainer(const double& double_val) :
		DataContainerTemplate<std::string>::DataContainerTemplate(std::string("")),
		DataContainerTemplate<std::int64_t>::DataContainerTemplate(std::int64_t(0)),
		DataContainerTemplate<int>::DataContainerTemplate(0),
		DataContainerTemplate<double>::DataContainerTemplate(double_val),
		DataContainerTemplate<float>::DataContainerTemplate(0.0f),
		DataContainerTemplate<bool>::DataContainerTemplate(false)
    {
		data_container_data_type = ENTSYS_DATA_TYPE_DOUBLE;
    }


    DataContainer::DataContainer(const float& float_val) :
		DataContainerTemplate<std::string>::DataContainerTemplate(std::string("")),
		DataContainerTemplate<std::int64_t>::DataContainerTemplate(std::int64_t(0)),
		DataContainerTemplate<int>::DataContainerTemplate(0),
		DataContainerTemplate<double>::DataContainerTemplate(0.0),
		DataContainerTemplate<float>::DataContainerTemplate(float_val),
		DataContainerTemplate<bool>::DataContainerTemplate(false)
    {
		data_container_data_type = ENTSYS_DATA_TYPE_FLOAT;
    }


    DataContainer::DataContainer(const bool& bool_val) :
		DataContainerTemplate<std::string>::DataContainerTemplate(std::string("")),
		DataContainerTemplate<std::int64_t>::DataContainerTemplate(std::int64_t(0)),
		DataContainerTemplate<int>::DataContainerTemplate(0),
		DataContainerTemplate<double>::DataContainerTemplate(0.0),
		DataContainerTemplate<float>::DataContainerTemplate(0.0f),
		DataContainerTemplate<bool>::DataContainerTemplate(bool_val)
    {
		data_container_data_type = ENTSYS_DATA_TYPE_BOOL;
    }


    DataContainer::DataContainer(const std::string& string_val) :
		DataContainerTemplate<std::string>::DataContainerTemplate(string_val),
		DataContainerTemplate<std::int64_t>::DataContainerTemplate(std::int64_t(0)),
		DataContainerTemplate<int>::DataContainerTemplate(0),
		DataContainerTemplate<double>::DataContainerTemplate(0.0),
		DataContainerTemplate<float>::DataContainerTemplate(0.0f),
		DataContainerTemplate<bool>::DataContainerTemplate(false)
    {
		data_container_data_type = ENTSYS_DATA_TYPE_STRING;
    }


    DataContainer::DataContainer(const int& int_val) :
		DataContainerTemplate<std::string>::DataContainerTemplate(std::string("")),
		DataContainerTemplate<std::int64_t>::DataContainerTemplate(std::int64_t(0)),
		DataContainerTemplate<int>::DataContainerTemplate(int_val),
		DataContainerTemplate<double>::DataContainerTemplate(0.0),
		DataContainerTemplate<float>::DataContainerTemplate(0.0f),
		DataContainerTemplate<bool>::DataContainerTemplate(false)
    {
		data_container_data_type = ENTSYS_DATA_TYPE_INT;
    }


    DataContainer::~DataContainer()
    {
    }

    
    void DataContainer::set_data_type(const ENTSYS_DATA_TYPE& data_type)
    {
		data_container_data_type = data_type;
    }


    ENTSYS_DATA_TYPE DataContainer::get_data_type() const
    {
		return data_container_data_type;
    }
	

};
};
