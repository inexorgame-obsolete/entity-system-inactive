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

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::type(string entity_type_name)
	{
		this->entity_type_name = entity_type_name;
		return shared_from_this();
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::type(const ENT_TYPE& entity_type)
	{
		this->o_entity_type = { entity_type };
		return shared_from_this();
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::uuid(string entity_instance_uuid)
	{
		this->entity_instance_uuid = entity_instance_uuid;
		return shared_from_this();
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::attribute(string attribute_name, DataContainer value)
	{
		entity_instance_attributes[attribute_name] = value;
		return shared_from_this();
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::attribute(string attribute_name, string value)
	{
		entity_instance_attributes[attribute_name] = {ENTSYS_DATA_TYPE_STRING, value};
		return shared_from_this();
	}

	shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::attribute(string attribute_name, int value)
	{
		entity_instance_attributes[attribute_name] = {ENTSYS_DATA_TYPE_INT, value};
		return shared_from_this();
	}

    shared_ptr<EntityInstanceBuilder> EntityInstanceBuilder::attribute(string attribute_name, float value)
	{
		entity_instance_attributes[attribute_name] = {ENTSYS_DATA_TYPE_FLOAT, value};
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
			o_entity_instance = entity_instance_manager->create_entity_instance(o_entity_type.value());
		}
		if (o_entity_instance.has_value())
		{
			ENT_INST entity_instance = o_entity_instance.value();
			// TODO: set attribute values
			for (auto& attr_entry : entity_instance_attributes) {
				string attr_name = attr_entry.first;
				DataContainer attr_value = attr_entry.second;
				O_ENT_ATTR_INST o_attr_inst = entity_instance->get_attribute_instance(attr_entry.first);
				if (o_attr_inst.has_value()) {
					ENT_ATTR_INST attr_inst = o_attr_inst.value();
					if (attr_inst->type == attr_value.type) {
						attr_inst->value = attr_value.value;
						switch (attr_inst->type)
						{
							case ENTSYS_DATA_TYPE_INT:
								spdlog::debug("Set attribute {} = {}", attr_name, std::get<ENTSYS_DATA_TYPE_INT>(attr_inst->value));
								break;
							case ENTSYS_DATA_TYPE_STRING:
								spdlog::debug("Set attribute {} = {}", attr_name, std::get<ENTSYS_DATA_TYPE_STRING>(attr_inst->value));
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
			spdlog::info("Created entity instance (UUID: {}) of type {} (UUID: {})", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(), entity_instance->get_entity_type()->get_GUID().str());
			return o_entity_instance;
		} else {
			spdlog::error("Failed to create entity instance");
			return std::nullopt;
		}
	}

}
}
