#include "EntityInstanceBuilder.hpp"

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace entity_system {

	/// These using instructions help to shorten the following code.
	using EntityAttributeInstancePtr = std::shared_ptr<EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

	EntityInstanceBuilder::EntityInstanceBuilder(
		EntityInstanceManagerPtr entity_instance_manager,
		EntityTypeManagerPtr entity_type_manager
	)
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);

		this->entity_instance_manager = entity_instance_manager;
		this->entity_type_manager = entity_type_manager;
		entity_type_name = "";
		o_entity_type = std::nullopt;
	}

	EntityInstanceBuilder::~EntityInstanceBuilder()
	{
	}

	EntityInstanceBuilderPtr EntityInstanceBuilder::type(const std::string& entity_type_name)
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);

		this->entity_type_name = entity_type_name;
		return shared_from_this();
	}

	EntityInstanceBuilderPtr EntityInstanceBuilder::type(const EntityTypePtr& entity_type)
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);

		this->o_entity_type = { entity_type };
		return shared_from_this();
	}

	EntityInstanceBuilderPtr EntityInstanceBuilder::uuid(const std::string& entity_instance_uuid)
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);

		this->entity_instance_uuid = entity_instance_uuid;
		return shared_from_this();
	}

	EntityInstanceBuilderPtr EntityInstanceBuilder::attribute(const std::string& attribute_name, const DataContainerInitializer& initializer)
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);

		entity_instance_attributes[attribute_name] = {initializer.type, initializer.value };
		return shared_from_this();
	}

	EntityInstanceBuilderPtr EntityInstanceBuilder::attribute(const std::string& attribute_name, const bool& value)
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);

		entity_instance_attributes[attribute_name] = {DataType::BOOL, value};
		return shared_from_this();
	}

	EntityInstanceBuilderPtr EntityInstanceBuilder::attribute(const std::string& attribute_name, const int& value)
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);

		entity_instance_attributes[attribute_name] = {DataType::INT, value};
		return shared_from_this();
	}

	EntityInstanceBuilderPtr EntityInstanceBuilder::attribute(const std::string& attribute_name, const int64_t& value)
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);

		entity_instance_attributes[attribute_name] = {DataType::BIG_INT, value};
		return shared_from_this();
	}

	EntityInstanceBuilderPtr EntityInstanceBuilder::attribute(const std::string& attribute_name, const float& value)
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);

		entity_instance_attributes[attribute_name] = {DataType::FLOAT, value};
		return shared_from_this();
	}

	EntityInstanceBuilderPtr EntityInstanceBuilder::attribute(const std::string& attribute_name, const double& value)
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);

		entity_instance_attributes[attribute_name] = {DataType::DOUBLE, value};
		return shared_from_this();
	}

	EntityInstanceBuilderPtr EntityInstanceBuilder::attribute(const std::string& attribute_name, const std::string& value)
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);

		entity_instance_attributes[attribute_name] = {DataType::STRING, value};
		return shared_from_this();
	}

	EntityInstancePtrOpt EntityInstanceBuilder::build()
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);

		bool error = false;
		EntityInstancePtrOpt o_entity_instance = std::nullopt;
		
		if(!o_entity_type.has_value() && !entity_type_name.empty())
		{
			o_entity_type = entity_type_manager->get_entity_type(entity_type_name);
		}
		if(o_entity_type.has_value())
		{
			if(!entity_instance_uuid.empty())
			{
				o_entity_instance = entity_instance_manager->create_entity_instance(
					xg::Guid(entity_instance_uuid),
					o_entity_type.value(),
					std::bind(&EntityInstanceBuilder::initialize_instance, this, std::placeholders::_1)
				);
			}
			else
			{
				o_entity_instance = entity_instance_manager->create_entity_instance(
					o_entity_type.value(),
					std::bind(&EntityInstanceBuilder::initialize_instance, this, std::placeholders::_1)
				);
			}
		}
		if(o_entity_instance.has_value() && !error)
		{
			return o_entity_instance;
		}
		else
		{
			spdlog::error("Failed to create entity instance");
			return std::nullopt;
		}
	}

	bool EntityInstanceBuilder::initialize_instance(EntityInstancePtr entity_instance)
	{
		// Use lock guard to ensure thread safety for the following write operations!
		std::lock_guard<std::mutex> lock(entity_instance_builder_mutex);
		
		for(auto& attr_entry : entity_instance_attributes)
		{
			std::string attr_name = attr_entry.first;
			DataContainerInitializer attr_value = attr_entry.second;
			EntityAttributeInstancePtrOpt o_attr_inst = entity_instance->get_attribute_instance(attr_entry.first);
			if (o_attr_inst.has_value())
			{
				EntityAttributeInstancePtr attr_inst = o_attr_inst.value();
				if(attr_inst->type == attr_value.type)
				{
					DataValue data_value = attr_value.value;
					switch(attr_inst->type)
					{
						case DataType::BOOL:
							attr_inst->own_value.Set(std::get<DataType::BOOL>(data_value));
							spdlog::debug("Set {} attribute {} = {}", DataType::_from_integral(attr_inst->type)._to_string(), attr_name, std::get<DataType::BOOL>(attr_inst->own_value.Value()));
							break;
						case DataType::INT:
							attr_inst->own_value.Set(std::get<DataType::INT>(data_value));
							spdlog::debug("Set {} attribute {} = {}", DataType::_from_integral(attr_inst->type)._to_string(), attr_name, std::get<DataType::INT>(attr_inst->own_value.Value()));
							break;
						case DataType::BIG_INT:
							attr_inst->own_value.Set(std::get<DataType::BIG_INT>(data_value));
							spdlog::debug("Set {} attribute {} = {}", DataType::_from_integral(attr_inst->type)._to_string(), attr_name, std::get<DataType::BIG_INT>(attr_inst->own_value.Value()));
							break;
						case DataType::DOUBLE:
							attr_inst->own_value.Set(std::get<DataType::DOUBLE>(data_value));
							spdlog::debug("Set {} attribute {} = {}", DataType::_from_integral(attr_inst->type)._to_string(), attr_name, std::get<DataType::DOUBLE>(attr_inst->own_value.Value()));
							break;
						case DataType::FLOAT:
							attr_inst->own_value.Set(std::get<DataType::FLOAT>(data_value));
							spdlog::debug("Set {} attribute {} = {}", DataType::_from_integral(attr_inst->type)._to_string(), attr_name, std::get<DataType::FLOAT>(attr_inst->own_value.Value()));
							break;
						case DataType::STRING:
							attr_inst->own_value.Set(std::get<DataType::STRING>(data_value));
							spdlog::debug("Set {} attribute {} = {}", DataType::_from_integral(attr_inst->type)._to_string(), attr_name, std::get<DataType::STRING>(attr_inst->own_value.Value()));
							break;
						default:
							spdlog::error("Failed to set attribute {}: Unknown data type {} {}", attr_name, DataType::_from_integral(attr_inst->type)._to_string(),  attr_inst->type);
							break;
					}
				}
				else
				{
					// Error: Wrong datatype
					spdlog::error("Wrong datatype for attribute {} of new entity instance of type {}: {} != {}", attr_name, o_entity_type.value()->get_type_name(), attr_inst->type._to_string(), attr_value.type._to_string());
					return false;
				}
			}
			else
			{
				// Error: Attribute not found by name
				spdlog::error("Entity instance attribute {} not found", attr_name);
				return false;
			}
		}
		return true;
	}

}
}
