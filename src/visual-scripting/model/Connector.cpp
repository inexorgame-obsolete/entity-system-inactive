#include "Connector.hpp"

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace visual_scripting {

	using DataValue = entity_system::DataValue;
	using DataType = entity_system::DataType;

	Connector::Connector(
		const EntityAttributeInstancePtr& output_attr,
		const EntityAttributeInstancePtr& input_attr
	) : entity_system::GUIDBase()
	{
		this->output_attr = output_attr;
		this->input_attr = input_attr;
		this->output_attribute_GUID = output_attr->get_GUID();
		this->input_attribute_GUID = input_attr->get_GUID();
		this->debug_enabled = false;
		connect();
	};

	Connector::Connector(
		const xg::Guid& connector_GUID,
		const EntityAttributeInstancePtr& output_attr,
		const EntityAttributeInstancePtr& input_attr
	) : GUIDBase(connector_GUID)
	{
		this->output_attr = output_attr;
		this->input_attr = input_attr;
		this->output_attribute_GUID = output_attr->get_GUID();
		this->input_attribute_GUID = input_attr->get_GUID();
		this->debug_enabled = false;
		connect();
	};

	Connector::~Connector()
	{
		disconnect();
	}

	void Connector::connect()
	{
		input_attr->signal_wrapper <<= output_attr->value;
		spdlog::get(LOGGER_NAME)->debug(
			"Connect output {}.{} with input {}.{}",
			output_attr->get_GUID().str(),
			output_attr->get_entity_attribute_type()->get_type_name(),
			input_attr->get_GUID().str(),
			input_attr->get_entity_attribute_type()->get_type_name()
		);
	}

	void Connector::disconnect()
	{
		if (debug_enabled)
		{
			disable_debug();
		}
		input_attr->signal_wrapper <<= input_attr->own_value;
		spdlog::get(LOGGER_NAME)->debug(
			"Disconnected output {}.{} with input {}.{}",
			output_attr->get_GUID().str(),
			output_attr->get_entity_attribute_type()->get_type_name(),
			input_attr->get_GUID().str(),
			input_attr->get_entity_attribute_type()->get_type_name()
		);
	}

	xg::Guid Connector::connector() const
	{
		return get_GUID();
	}

	xg::Guid Connector::output() const
	{
		return output_attribute_GUID;
	}

	xg::Guid Connector::input() const
	{
		return input_attribute_GUID;
	}

	void Connector::enable_debug()
	{
		if (!debug_enabled)
		{
			this->observer = Observe(output_attr->value, [this] (DataValue value) {
				spdlog::get(LOGGER_NAME)->info(
					"{}.{} ---[{}]---> {}.{}",
					output_attr->get_GUID().str(),
					output_attr->get_entity_attribute_type()->get_type_name(),
					data_value_to_string(output_attr->type, value),
					input_attr->get_GUID().str(),
					input_attr->get_entity_attribute_type()->get_type_name()
				);
			});
			debug_enabled = true;
		}
	}

	void Connector::disable_debug()
	{
		if (debug_enabled)
		{
			this->observer.Detach();
			debug_enabled = false;
		}
	}

	bool Connector::is_debug_enabled()
	{
		return debug_enabled;
	}

}
}
