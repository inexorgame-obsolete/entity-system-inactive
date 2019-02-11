// Inexor entity system
// (c)2018 Inexor

#include "EntityInstanceBuilder.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {


	EntityInstanceBuilder::EntityInstanceBuilder(
		shared_ptr<EntityInstanceManager> entity_instance_manager,
		shared_ptr<EntityTypeManager> entity_type_manager
	)
	{
		this->entity_instance_manager = entity_instance_manager;
		this->entity_type_manager = entity_type_manager;
		entity_type_name = "";
		o_entity_type = nullopt;
	}

	EntityInstanceBuilder::~EntityInstanceBuilder()
	{
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::type(const string& entity_type_name)
	{
		this->entity_type_name = entity_type_name;
		return shared_from_this();
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::type(const ENT_TYPE& entity_type)
	{
		this->o_entity_type = { entity_type };
		return shared_from_this();
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::uuid(const string& entity_instance_uuid)
	{
		this->entity_instance_uuid = entity_instance_uuid;
		return shared_from_this();
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::attribute(const string& attribute_name, const DataContainerInitializer& initializer)
	{
		entity_instance_attributes[attribute_name] = {initializer.type, initializer.value };
		return shared_from_this();
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::attribute(const string& attribute_name, const bool& value)
	{
		entity_instance_attributes[attribute_name] = {DataType::BOOL, value};
		return shared_from_this();
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::attribute(const string& attribute_name, const int& value)
	{
		entity_instance_attributes[attribute_name] = {DataType::INT, value};
		return shared_from_this();
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::attribute(const string& attribute_name, const int64_t& value)
	{
		entity_instance_attributes[attribute_name] = {DataType::BIG_INT, value};
		return shared_from_this();
	}

    shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::attribute(const string& attribute_name, const float& value)
	{
		entity_instance_attributes[attribute_name] = {DataType::FLOAT, value};
		return shared_from_this();
	}

    shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::attribute(const string& attribute_name, const double& value)
	{
		entity_instance_attributes[attribute_name] = {DataType::DOUBLE, value};
		return shared_from_this();
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::attribute(const string& attribute_name, const string& value)
	{
		entity_instance_attributes[attribute_name] = {DataType::STRING, value};
		return shared_from_this();
	}

	O_ENT_INST EntityInstanceBuilder::build()
	{
		O_ENT_INST o_entity_instance = nullopt;
		if (!o_entity_type.has_value() && !entity_type_name.empty())
		{
			o_entity_type = entity_type_manager->get_entity_type(entity_type_name);
		}
		if (o_entity_type.has_value())
		{
			if (!entity_instance_uuid.empty())
			{
				o_entity_instance = entity_instance_manager->create_entity_instance(xg::Guid(entity_instance_uuid), o_entity_type.value());
			} else {
				o_entity_instance = entity_instance_manager->create_entity_instance(o_entity_type.value());
			}
		}
		if (o_entity_instance.has_value())
		{
			ENT_INST entity_instance = o_entity_instance.value();
			// TODO: set attribute values
			for (auto& attr_entry : entity_instance_attributes) {
				string attr_name = attr_entry.first;
				DataContainerInitializer attr_value = attr_entry.second;
				O_ENT_ATTR_INST o_attr_inst = entity_instance->get_attribute_instance(attr_entry.first);
				if (o_attr_inst.has_value()) {
					ENT_ATTR_INST attr_inst = o_attr_inst.value();
					if (attr_inst->type == attr_value.type) {
						DataValue data_value = attr_value.value;
						switch (attr_inst->type)
						{
							case DataType::BOOL:
								attr_inst->value.Set(std::get<DataType::BOOL>(data_value));
								spdlog::debug("Set attribute {} = {}", attr_name, std::get<DataType::BOOL>(attr_inst->value.Value()));
								break;
							case DataType::INT:
								attr_inst->value.Set(std::get<DataType::INT>(data_value));
								spdlog::debug("Set attribute {} = {}", attr_name, std::get<DataType::INT>(attr_inst->value.Value()));
								break;
							case DataType::BIG_INT:
								attr_inst->value.Set(std::get<DataType::BIG_INT>(data_value));
								spdlog::debug("Set attribute {} = {}", attr_name, std::get<DataType::BIG_INT>(attr_inst->value.Value()));
								break;
							case DataType::DOUBLE:
								attr_inst->value.Set(std::get<DataType::DOUBLE>(data_value));
								spdlog::debug("Set attribute {} = {}", attr_name, std::get<DataType::DOUBLE>(attr_inst->value.Value()));
								break;
							case DataType::FLOAT:
								attr_inst->value.Set(std::get<DataType::FLOAT>(data_value));
								spdlog::debug("Set attribute {} = {}", attr_name, std::get<DataType::FLOAT>(attr_inst->value.Value()));
								break;
							case DataType::STRING:
								attr_inst->value.Set(std::get<DataType::STRING>(data_value));
								spdlog::debug("Set attribute {} = {}", attr_name, std::get<DataType::STRING>(attr_inst->value.Value()));
								break;
							default:
								break;
						}
					} else {
						// Error: Wrong datatype
						spdlog::error("Wrong datatype for attribute {}: {} != {}", attr_name, attr_inst->type, attr_value.type);
						return std::nullopt;
					}
				} else {
					// Error: Attribute not found by name
					spdlog::error("Entity instance attribute {} not found", attr_name);
					return std::nullopt;
				}
			}
			return o_entity_instance;
		} else {
			spdlog::error("Failed to create entity instance");
			return std::nullopt;
		}
	}

}
}
