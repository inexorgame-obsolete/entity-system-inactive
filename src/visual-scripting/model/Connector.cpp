// Inexor entity system
// (c)2018-2019 Inexor

#include "Connector.hpp"

using namespace inexor::entity_system;
using namespace std;
using namespace xg;

namespace inexor {
namespace visual_scripting {

//	Connector::Connector(const Guid& output_attribute_GUID, const Guid& input_attribute_GUID, const DataValue& output_value, const DataValue& input_value)
//		: GUIDBase()
//	{
//        this->output_attribute_GUID = output_attribute_GUID;
//        this->input_attribute_GUID = input_attribute_GUID;
//        this->output_value = MakeVar<D>
//	}
//
//	Connector::Connector(const Guid& connector_GUID, const Guid& output_attribute_GUID, const Guid& input_attribute_GUID, const DataValue& output_value, const DataValue& input_value)
//    	: GUIDBase(connector_GUID)
//    {
//        this->output_attribute_GUID = output_attribute_GUID;
//        this->input_attribute_GUID = input_attribute_GUID;
//    }

	Connector::~Connector()
	{
	}

	Guid Connector::connector() const
	{
		return get_GUID();
	}

	Guid Connector::output() const
	{
		return output_attribute_GUID;
	}

	Guid Connector::input() const
	{
		return input_attribute_GUID;
	}

};
};
