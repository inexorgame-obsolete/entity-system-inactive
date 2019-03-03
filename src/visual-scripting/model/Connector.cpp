// Inexor entity system
// (c)2018-2019 Inexor

#include "Connector.hpp"

using namespace inexor::entity_system;
using namespace std;
using namespace xg;

namespace inexor {
namespace visual_scripting {

	Connector::Connector(
		const std::shared_ptr<inexor::entity_system::EntityAttributeInstance> & output_attr,
		const std::shared_ptr<inexor::entity_system::EntityAttributeInstance> & input_attr
	) : GUIDBase()
	{
		this->output_attr = output_attr;
		this->input_attr = input_attr;
		this->output_attribute_GUID = output_attr->get_GUID();
		this->input_attribute_GUID = input_attr->get_GUID();
		connect();
	};

	Connector::Connector(
		const Guid& connector_GUID,
		const std::shared_ptr<inexor::entity_system::EntityAttributeInstance> & output_attr,
		const std::shared_ptr<inexor::entity_system::EntityAttributeInstance> & input_attr
	) : GUIDBase(connector_GUID)
	{
		this->output_attr = output_attr;
		this->input_attr = input_attr;
		this->output_attribute_GUID = output_attr->get_GUID();
		this->input_attribute_GUID = input_attr->get_GUID();
		connect();
	};

	Connector::~Connector()
	{
	}

	void Connector::connect()
	{
		this->observer = Observe(output_attr->value, [this] (DataValue value) {
			std::cout << output_attr->get_GUID().str() << "." << output_attr->get_entity_attribute_type()->get_type_name() << " has changed: ";
			switch (output_attr->type)
			{
				case DataType::BOOL:
					std::cout << std::get<DataType::BOOL>(value);
					break;
				case DataType::INT:
					std::cout << std::get<DataType::INT>(value);
					break;
				case DataType::BIG_INT:
					std::cout << std::get<DataType::BIG_INT>(value);
					break;
				case DataType::DOUBLE:
					std::cout << std::get<DataType::DOUBLE>(value);
					break;
				case DataType::FLOAT:
					std::cout << std::get<DataType::FLOAT>(value);
					break;
				case DataType::STRING:
					std::cout << std::get<DataType::STRING>(value);
					break;
				default:
					break;
			}
			std::cout << std::endl;
		});

		input_attr->signal_wrapper <<= output_attr->value;

		// Copy value unmodified
		// input_attr->own_value = MakeSignal(output_attr->value, [] (inexor::entity_system::DataValue v) { return v; });
		// connector_signal = MakeSignal(*output_attr->value, [] (inexor::entity_system::DataValue v) { return v; });
		// input_attr->value = &connector_signal;

//		auto connector_signal = MakeSignal(*output_attr->value, [] (inexor::entity_system::DataValue v) { return v; });
//		auto function_op = connector_signal.StealOp();
//		input_attr->value = &connector_signal;

		// input_attr->value->StealOp();
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
