// Inexor entity system
// (c)2018 Inexor

#include "EntityInstanceBuilder.hpp"
#include "spdlog/spdlog.h"

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
				O_ENT_ATTR_INST o_attr_inst = entity_instance->get_attribute_instance(attr_entry.first);
				if (o_attr_inst.has_value()) {
					ENT_ATTR_INST attr_inst = o_attr_inst.value();
					if (attr_inst->type == attr_entry.second.type) {
						attr_inst->value = attr_entry.second.value;
						spdlog::info("Set attribute");
						// spdlog::info("Set attribute {} = {}", attr_entry.first, attr_entry.second.value);
					} else {
						// Error: Wrong datatype
						spdlog::info("Wrong datatype for attribute");
						// spdlog::info("Wrong datatype for attribute {}: {} != {}", attr_entry.first, attr_inst->type, attr_entry.second.type);
						return std::nullopt;
					}
				} else {
					// Error: Attribute not found by name
					spdlog::info("Attribute not found");
					// spdlog::info("Attribute {} not found", attr_entry.first);
					return std::nullopt;
				}
			}
			return o_entity_instance;
		}
		return std::nullopt;
	}

}
}
