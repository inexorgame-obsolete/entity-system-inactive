#include <visual-scripting/managers/ConnectorManager.hpp>

#include <utility>

namespace inexor::visual_scripting {

using namespace magic_enum::bitwise_operators;

using Features = entity_system::Features;

ConnectorManager::ConnectorManager(EntityInstanceManagerPtr entity_instance_manager, RelationInstanceManagerPtr relation_instance_manager, LogManagerPtr log_manager)
    : LifeCycleComponent()
{
    this->entity_instance_manager = std::move(entity_instance_manager);
    this->relation_instance_manager = std::move(relation_instance_manager);
    this->log_manager = std::move(log_manager);
}

ConnectorManager::~ConnectorManager() = default;

std::string ConnectorManager::get_component_name()
{
    return "ConnectorManager";
}

ConnectorPtrOpt ConnectorManager::create_connector(const std::shared_ptr<class inexor::entity_system::EntityAttributeInstance> &output_attr, const std::shared_ptr<class inexor::entity_system::EntityAttributeInstance> &input_attr)
{
    xg::Guid output_attr_GUID = output_attr->get_GUID();
    xg::Guid input_attr_GUID = input_attr->get_GUID();
    // Check non-equal uuid
    // Check equal data type
    // Check if output attribute has feature OUTPUT
    // Check if input attribute has feature INPUT
    // Check if input is not occupied
    if (output_attr_GUID != input_attr_GUID
        && output_attr->type == input_attr->type
        && magic_enum::enum_integer(output_attr->get_entity_attribute_type()->get_attribute_features() & Features::OUTPUT)
        && magic_enum::enum_integer(input_attr->get_entity_attribute_type()->get_attribute_features() & Features::INPUT)
        && !input_occupied(input_attr_GUID))
    {
        ConnectorPtr connector = std::make_shared<Connector>(output_attr, input_attr);
        connectors[connector->get_GUID()] = connector;
        output_to_connectors[output_attr_GUID].push_back(connector);
        input_to_connector[input_attr_GUID] = connector;
        spdlog::trace("Successfully created connector from {} to {}", output_attr_GUID.str(), input_attr_GUID.str());
        return ConnectorPtrOpt{connector};
    } else {
        spdlog::trace("Not creating connector from {} to {}", output_attr_GUID.str(), input_attr_GUID.str());
    }
    return std::nullopt;
}

ConnectorPtrOpt ConnectorManager::create_connector(const xg::Guid &connector_GUID, const std::shared_ptr<class inexor::entity_system::EntityAttributeInstance> &output_attr,
                                                   const std::shared_ptr<class inexor::entity_system::EntityAttributeInstance> &input_attr)
{
    xg::Guid output_attr_GUID = output_attr->get_GUID();
    xg::Guid input_attr_GUID = input_attr->get_GUID();
    // Check if connector uuid doesn't exist
    // Check non-equal uuid
    // Check equal data type
    // Check if output attribute has feature OUTPUT
    // Check if input attribute has feature INPUT
    // Check if input is not occupied
    if (!connector_exists(connector_GUID)
        && output_attr_GUID != input_attr_GUID
        && output_attr->type == input_attr->type
        && magic_enum::enum_integer(output_attr->get_entity_attribute_type()->get_attribute_features() & Features::OUTPUT)
        && magic_enum::enum_integer(input_attr->get_entity_attribute_type()->get_attribute_features() & Features::INPUT)
        && !input_occupied(input_attr_GUID))
    {
        ConnectorPtr connector = std::make_shared<Connector>(connector_GUID, output_attr, input_attr);
        connectors[connector->get_GUID()] = connector;
        output_to_connectors[output_attr_GUID].push_back(connector);
        input_to_connector[input_attr_GUID] = connector;
        spdlog::trace("Successfully created connector from {} to {}", output_attr_GUID.str(), input_attr_GUID.str());
        return ConnectorPtrOpt{connector};
    } else {
        spdlog::trace("Not creating connector from {} to {}", output_attr_GUID.str(), input_attr_GUID.str());
    }
    return std::nullopt;
}

//	ConnectorPtrOpt ConnectorManager::create_connector(const EntityAttributeInstancePtr& output_attr, const RelationAttributeInstancePtr& input_attr)
//	{
//		xg::Guid output_attr_GUID = output_attr->get_GUID();
//		xg::Guid input_attr_GUID = input_attr->get_GUID();
//		// Check equal data type
//		// Check if output attribute has feature OUTPUT
//		// Check if input attribute has feature INPUT
//		// Check if input is already occupied
//		if (output_attr->type == input_attr->type
//			&& output_attr->get_entity_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
//			&& input_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::INPUT)
//			&& !input_occupied(input_attr_GUID))
//		{
//			return ConnectorPtrOpt { make_shared<Connector>(output_attr_GUID, input_attr_GUID) };
//		}
//		return nullopt;
//	}
//
//	ConnectorPtrOpt ConnectorManager::create_connector(const xg::Guid& connector_GUID, const EntityAttributeInstancePtr& output_attr, const RelationAttributeInstancePtr& input_attr)
//	{
//		xg::Guid output_attr_GUID = output_attr->get_GUID();
//		xg::Guid input_attr_GUID = input_attr->get_GUID();
//		// Check if connector uuid doesn't exist
//		// Check equal data type
//		// Check if output attribute has feature OUTPUT
//		// Check if input attribute has feature INPUT
//		// Check if input is already occupied
//		if (!connector_exists(connector_GUID)
//			&& output_attr->type == input_attr->type
//			&& output_attr->get_entity_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
//			&& input_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::INPUT)
//			&& !input_occupied(input_attr_GUID))
//		{
//			return ConnectorPtrOpt { make_shared<Connector>(connector_GUID, output_attr_GUID, input_attr_GUID) };
//		}
//		return nullopt;
//	}
//
//	ConnectorPtrOpt ConnectorManager::create_connector(const RelationAttributeInstancePtr& output_attr, const EntityAttributeInstancePtr& input_attr)
//	{
//		xg::Guid output_attr_GUID = output_attr->get_GUID();
//		xg::Guid input_attr_GUID = input_attr->get_GUID();
//		// Check equal data type
//		// Check if output attribute has feature OUTPUT
//		// Check if input attribute has feature INPUT
//		// Check if input is already occupied
//		if (output_attr->type == input_attr->type
//			&& output_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
//			&& input_attr->get_entity_attribute_type()->get_attribute_features().test(Feature::INPUT)
//			&& !input_occupied(input_attr_GUID))
//		{
//			return ConnectorPtrOpt { make_shared<Connector>(output_attr_GUID, input_attr_GUID) };
//		}
//		return nullopt;
//	}
//
//	ConnectorPtrOpt ConnectorManager::create_connector(const xg::Guid& connector_GUID, const RelationAttributeInstancePtr& output_attr, const EntityAttributeInstancePtr& input_attr)
//	{
//		xg::Guid output_attr_GUID = output_attr->get_GUID();
//		xg::Guid input_attr_GUID = input_attr->get_GUID();
//		// Check if connector uuid doesn't exist
//		// Check equal data type
//		// Check if output attribute has feature OUTPUT
//		// Check if input attribute has feature INPUT
//		// Check if input is already occupied
//		if (!connector_exists(connector_GUID)
//			&& output_attr->type == input_attr->type
//			&& output_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
//			&& input_attr->get_entity_attribute_type()->get_attribute_features().test(Feature::INPUT)
//			&& !input_occupied(input_attr_GUID))
//		{
//			return ConnectorPtrOpt { make_shared<Connector>(connector_GUID, output_attr_GUID, input_attr_GUID) };
//		}
//		return nullopt;
//	}
//
//	ConnectorPtrOpt ConnectorManager::create_connector(const RelationAttributeInstancePtr& output_attr, const RelationAttributeInstancePtr& input_attr)
//	{
//		xg::Guid output_attr_GUID = output_attr->get_GUID();
//		xg::Guid input_attr_GUID = input_attr->get_GUID();
//		// Check non-equal uuid
//		// Check equal data type
//		// Check if output attribute has feature OUTPUT
//		// Check if input attribute has feature INPUT
//		// Check if input is already occupied
//		if (output_attr_GUID != input_attr_GUID
//			&& output_attr->type == input_attr->type
//			&& output_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
//			&& input_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::INPUT)
//			&& !input_occupied(input_attr_GUID))
//		{
//			return ConnectorPtrOpt { make_shared<Connector>(output_attr_GUID, input_attr_GUID) };
//		}
//		return nullopt;
//	}
//
//	ConnectorPtrOpt ConnectorManager::create_connector(const xg::Guid& connector_GUID, const RelationAttributeInstancePtr& output_attr, const RelationAttributeInstancePtr& input_attr)
//	{
//		xg::Guid output_attr_GUID = output_attr->get_GUID();
//		xg::Guid input_attr_GUID = input_attr->get_GUID();
//		// Check if connector uuid doesn't exist
//		// Check non-equal uuid
//		// Check equal data type
//		// Check if output attribute has feature OUTPUT
//		// Check if input attribute has feature INPUT
//		// Check if input is already occupied
//		if (!connector_exists(connector_GUID)
//			&& output_attr_GUID != input_attr_GUID
//			&& output_attr->type == input_attr->type
//			&& output_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::OUTPUT)
//			&& input_attr->get_relation_attribute_type()->get_attribute_features().test(Feature::INPUT)
//			&& !input_occupied(input_attr_GUID))
//		{
//			return ConnectorPtrOpt { make_shared<Connector>(connector_GUID, output_attr_GUID, input_attr_GUID) };
//		}
//		return nullopt;
//	}

void ConnectorManager::delete_connector_by_input(const EntityAttributeInstancePtr &input_attr)
{
    delete_connector(input_to_connector[input_attr->get_GUID()]);
}

void ConnectorManager::delete_connector_by_input(const RelationAttributeInstancePtr &input_attr)
{
    delete_connector(input_to_connector[input_attr->get_GUID()]);
}

void ConnectorManager::delete_connectors_by_output(const EntityAttributeInstancePtr &output_attr)
{
    for (const ConnectorPtr& connector : output_to_connectors[output_attr->get_GUID()])
    {
        delete_connector(connector);
    }
}

void ConnectorManager::delete_connectors_by_output(const RelationAttributeInstancePtr &output_attr)
{
    for (const ConnectorPtr& connector : output_to_connectors[output_attr->get_GUID()])
    {
        delete_connector(connector);
    }
}

void ConnectorManager::delete_connector(const xg::Guid &connector_GUID)
{
    if (connector_exists(connector_GUID))
    {
        delete_connector(connectors[connector_GUID]);
    }
}

void ConnectorManager::delete_connector(const ConnectorPtr &connector)
{
    // TODO: mutex!
    xg::Guid connector_GUID = connector->get_GUID();
    xg::Guid output_GUID = connector->output();
    xg::Guid input_GUID = connector->input();
    std::vector<ConnectorPtr> output_connectors = output_to_connectors[output_GUID];
    output_connectors.erase(remove(output_connectors.begin(), output_connectors.end(), connector), output_connectors.end());
    input_to_connector.erase(input_GUID);
    connectors[connector_GUID]->disconnect();
    connectors.erase(connector_GUID);
}

void ConnectorManager::delete_connector(const ConnectorPtrOpt &connector)
{
    if (connector.has_value())
    {
        delete_connector(connector.value());
    }
}

bool ConnectorManager::connector_exists(const xg::Guid &connector_GUID)
{
    return !(connectors.end() == connectors.find(connector_GUID));
}

bool ConnectorManager::input_occupied(const xg::Guid &input_attr_GUID)
{
    return !(input_to_connector.end() == input_to_connector.find(input_attr_GUID));
}

void ConnectorManager::enable_debug(const ConnectorPtrOpt &connector)
{
    if (connector.has_value())
    {
        connector.value()->enable_debug();
    }
}

void ConnectorManager::disable_debug(const ConnectorPtrOpt &connector)
{
    if (connector.has_value())
    {
        connector.value()->disable_debug();
    }
}

} // namespace inexor::visual_scripting
