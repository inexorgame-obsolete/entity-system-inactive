// Inexor entity system
// (c)2018 Inexor

#include "ConnectorManager.hpp"

using namespace inexor::entity_system;
using namespace std;
using namespace xg;

namespace inexor {
namespace visual_scripting {


	ConnectorManager::ConnectorManager(
		shared_ptr<EntityInstanceManager> entity_instance_manager,
		shared_ptr<RelationInstanceManager> relation_instance_manager
	)
	{
		this->entity_instance_manager = entity_instance_manager;
		this->relation_instance_manager = relation_instance_manager;
	}

	ConnectorManager::~ConnectorManager()
	{
	}

	void ConnectorManager::init()
	{
	}

	optional<shared_ptr<Connector>> ConnectorManager::create_connector(const ENT_ATTR_INST& output_attr, const ENT_ATTR_INST& input_attr)
	{
		Guid output_attr_GUID = output_attr->get_GUID();
		Guid input_attr_GUID = input_attr->get_GUID();
		// Check non-equal uuid
		// Check equal data type
		// Check if output attribute has feature OUTPUT
		// Check if input attribute has feature INPUT
		// Check if input is not occupied
		if (output_attr_GUID != input_attr_GUID
			&& output_attr->type == input_attr->type
			&& output_attr->get_entity_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
			&& input_attr->get_entity_attribute_type()->get_attribute_features().test(Feature::INPUT)
			&& !input_occupied(input_attr_GUID))
		{
			return optional<shared_ptr<Connector>> { make_shared<Connector>(output_attr_GUID, input_attr_GUID) };
		}
		return nullopt;
	}

	optional<shared_ptr<Connector>> ConnectorManager::create_connector(const Guid& connector_GUID, const ENT_ATTR_INST& output_attr, const ENT_ATTR_INST& input_attr)
	{
		Guid output_attr_GUID = output_attr->get_GUID();
		Guid input_attr_GUID = input_attr->get_GUID();
		// Check if connector uuid doesn't exist
		// Check non-equal uuid
		// Check equal data type
		// Check if output attribute has feature OUTPUT
		// Check if input attribute has feature INPUT
		// Check if input is not occupied
		if (!connector_exists(connector_GUID)
			&& output_attr_GUID != input_attr_GUID
			&& output_attr->type == input_attr->type
			&& output_attr->get_entity_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
			&& input_attr->get_entity_attribute_type()->get_attribute_features().test(Feature::INPUT)
			&& !input_occupied(input_attr_GUID))
		{
			return optional<shared_ptr<Connector>> { make_shared<Connector>(connector_GUID, output_attr_GUID, input_attr_GUID) };
		}
		return nullopt;
	}

	optional<shared_ptr<Connector>> ConnectorManager::create_connector(const ENT_ATTR_INST& output_attr, const REL_ATTR_INST& input_attr)
	{
		Guid output_attr_GUID = output_attr->get_GUID();
		Guid input_attr_GUID = input_attr->get_GUID();
		// Check equal data type
		// Check if output attribute has feature OUTPUT
		// Check if input attribute has feature INPUT
		// Check if input is already occupied
		if (output_attr->type == input_attr->type
			&& output_attr->get_entity_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
			&& input_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::INPUT)
			&& !input_occupied(input_attr_GUID))
		{
			return optional<shared_ptr<Connector>> { make_shared<Connector>(output_attr_GUID, input_attr_GUID) };
		}
		return nullopt;
	}

	optional<shared_ptr<Connector>> ConnectorManager::create_connector(const Guid& connector_GUID, const ENT_ATTR_INST& output_attr, const REL_ATTR_INST& input_attr)
	{
		Guid output_attr_GUID = output_attr->get_GUID();
		Guid input_attr_GUID = input_attr->get_GUID();
		// Check if connector uuid doesn't exist
		// Check equal data type
		// Check if output attribute has feature OUTPUT
		// Check if input attribute has feature INPUT
		// Check if input is already occupied
		if (!connector_exists(connector_GUID)
			&& output_attr->type == input_attr->type
			&& output_attr->get_entity_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
			&& input_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::INPUT)
			&& !input_occupied(input_attr_GUID))
		{
			return optional<shared_ptr<Connector>> { make_shared<Connector>(connector_GUID, output_attr_GUID, input_attr_GUID) };
		}
		return nullopt;
	}

	optional<shared_ptr<Connector>> ConnectorManager::create_connector(const REL_ATTR_INST& output_attr, const ENT_ATTR_INST& input_attr)
	{
		Guid output_attr_GUID = output_attr->get_GUID();
		Guid input_attr_GUID = input_attr->get_GUID();
		// Check equal data type
		// Check if output attribute has feature OUTPUT
		// Check if input attribute has feature INPUT
		// Check if input is already occupied
		if (output_attr->type == input_attr->type
			&& output_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
			&& input_attr->get_entity_attribute_type()->get_attribute_features().test(Feature::INPUT)
			&& !input_occupied(input_attr_GUID))
		{
			return optional<shared_ptr<Connector>> { make_shared<Connector>(output_attr_GUID, input_attr_GUID) };
		}
		return nullopt;
	}

	optional<shared_ptr<Connector>> ConnectorManager::create_connector(const Guid& connector_GUID, const REL_ATTR_INST& output_attr, const ENT_ATTR_INST& input_attr)
	{
		Guid output_attr_GUID = output_attr->get_GUID();
		Guid input_attr_GUID = input_attr->get_GUID();
		// Check if connector uuid doesn't exist
		// Check equal data type
		// Check if output attribute has feature OUTPUT
		// Check if input attribute has feature INPUT
		// Check if input is already occupied
		if (!connector_exists(connector_GUID)
			&& output_attr->type == input_attr->type
			&& output_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
			&& input_attr->get_entity_attribute_type()->get_attribute_features().test(Feature::INPUT)
			&& !input_occupied(input_attr_GUID))
		{
			return optional<shared_ptr<Connector>> { make_shared<Connector>(connector_GUID, output_attr_GUID, input_attr_GUID) };
		}
		return nullopt;
	}

	optional<shared_ptr<Connector>> ConnectorManager::create_connector(const REL_ATTR_INST& output_attr, const REL_ATTR_INST& input_attr)
	{
		Guid output_attr_GUID = output_attr->get_GUID();
		Guid input_attr_GUID = input_attr->get_GUID();
		// Check non-equal uuid
		// Check equal data type
		// Check if output attribute has feature OUTPUT
		// Check if input attribute has feature INPUT
		// Check if input is already occupied
		if (output_attr_GUID != input_attr_GUID
			&& output_attr->type == input_attr->type
			&& output_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
			&& input_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::INPUT)
			&& !input_occupied(input_attr_GUID))
		{
			return optional<shared_ptr<Connector>> { make_shared<Connector>(output_attr_GUID, input_attr_GUID) };
		}
		return nullopt;
	}

	optional<shared_ptr<Connector>> ConnectorManager::create_connector(const Guid& connector_GUID, const REL_ATTR_INST& output_attr, const REL_ATTR_INST& input_attr)
	{
		Guid output_attr_GUID = output_attr->get_GUID();
		Guid input_attr_GUID = input_attr->get_GUID();
		// Check if connector uuid doesn't exist
		// Check non-equal uuid
		// Check equal data type
		// Check if output attribute has feature OUTPUT
		// Check if input attribute has feature INPUT
		// Check if input is already occupied
		if (!connector_exists(connector_GUID)
			&& output_attr_GUID != input_attr_GUID
			&& output_attr->type == input_attr->type
			&& output_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
			&& input_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::INPUT)
			&& !input_occupied(input_attr_GUID))
		{
			return optional<shared_ptr<Connector>> { make_shared<Connector>(connector_GUID, output_attr_GUID, input_attr_GUID) };
		}
		return nullopt;
	}

	void ConnectorManager::delete_connector_by_input(const ENT_ATTR_INST& input_attr)
	{
		delete_connector(input_to_connector[input_attr->get_GUID()]);
	}

	void ConnectorManager::delete_connector_by_input(const REL_ATTR_INST& input_attr)
	{
		delete_connector(input_to_connector[input_attr->get_GUID()]);
	}

	void ConnectorManager::delete_connectors_by_output(const ENT_ATTR_INST& output_attr)
	{
		for (shared_ptr<Connector> connector : output_to_connectors[output_attr->get_GUID()])
		{
			delete_connector(connector);
		}
	}

	void ConnectorManager::delete_connectors_by_output(const REL_ATTR_INST& output_attr)
	{
		for (shared_ptr<Connector> connector : output_to_connectors[output_attr->get_GUID()])
		{
			delete_connector(connector);
		}
	}

	void ConnectorManager::delete_connector(const Guid& connector_GUID)
	{
		if (connector_exists(connector_GUID)) {
			delete_connector(connectors[connector_GUID]);
		}
	}

	void ConnectorManager::delete_connector(const shared_ptr<Connector>& connector)
	{
		// TODO: mutex!
		Guid connector_GUID = connector->get_GUID();
		Guid output_GUID = connector->output();
		Guid input_GUID = connector->input();
		vector<shared_ptr<Connector>> output_connectors = output_to_connectors[output_GUID];
		output_connectors.erase(remove(output_connectors.begin(), output_connectors.end(), connector), output_connectors.end());
		input_to_connector.erase(input_GUID);
		connectors.erase(connector_GUID);
	}

	bool ConnectorManager::connector_exists(const Guid& connector_GUID)
	{
		return ! (connectors.end() == connectors.find(connector_GUID));
	}

	bool ConnectorManager::input_occupied(const Guid& input_attr_GUID)
	{
		return ! (input_to_connector.end() == input_to_connector.find(input_attr_GUID));
	}

}
}
