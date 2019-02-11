// Inexor entity system
// (c)2018 Inexor

#include "RelationInstanceBuilder.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {


	RelationInstanceBuilder::RelationInstanceBuilder(
		shared_ptr<RelationInstanceManager> relation_instance_manager,
		shared_ptr<RelationTypeManager> relation_type_manager
	)
	{
		this->relation_instance_manager = relation_instance_manager;
		this->relation_type_manager = relation_type_manager;
		relation_type_name = "";
		o_relation_type = nullopt;
	}

	RelationInstanceBuilder::~RelationInstanceBuilder()
	{
	}

	shared_ptr<RelationInstanceBuilder> RelationInstanceBuilder::type(const string& relation_type_name)
	{
		this->relation_type_name = relation_type_name;
		return shared_from_this();
	}

	shared_ptr<RelationInstanceBuilder> RelationInstanceBuilder::type(const REL_TYPE& relation_type)
	{
		this->o_relation_type = { relation_type };
		return shared_from_this();
	}

	shared_ptr<RelationInstanceBuilder> RelationInstanceBuilder::uuid(const string& relation_instance_uuid)
	{
		this->relation_instance_uuid = relation_instance_uuid;
		return shared_from_this();
	}

	shared_ptr<RelationInstanceBuilder> RelationInstanceBuilder::source(ENT_INST ent_instance_source)
	{
		this->ent_instance_source = ent_instance_source;
		return shared_from_this();
	}

	shared_ptr<RelationInstanceBuilder> RelationInstanceBuilder::target(ENT_INST ent_instance_target)
	{
		this->ent_instance_target = ent_instance_target;
		return shared_from_this();
	}

	shared_ptr<RelationInstanceBuilder> RelationInstanceBuilder::attribute(const string& attribute_name, const DataContainerInitializer& initializer)
	{
		relation_instance_attributes[attribute_name] = {initializer.type, initializer.value };
		return shared_from_this();
	}

	shared_ptr<RelationInstanceBuilder> RelationInstanceBuilder::attribute(const string& attribute_name, const bool& value)
	{
		relation_instance_attributes[attribute_name] = {DataType::BOOL, value};
		return shared_from_this();
	}

	shared_ptr<RelationInstanceBuilder> RelationInstanceBuilder::attribute(const string& attribute_name, const int& value)
	{
		relation_instance_attributes[attribute_name] = {DataType::INT, value};
		return shared_from_this();
	}

	shared_ptr<RelationInstanceBuilder> RelationInstanceBuilder::attribute(const string& attribute_name, const int64_t& value)
	{
		relation_instance_attributes[attribute_name] = {DataType::BIG_INT, value};
		return shared_from_this();
	}

    shared_ptr<RelationInstanceBuilder> RelationInstanceBuilder::attribute(const string& attribute_name, const float& value)
	{
		relation_instance_attributes[attribute_name] = {DataType::FLOAT, value};
		return shared_from_this();
	}

    shared_ptr<RelationInstanceBuilder> RelationInstanceBuilder::attribute(const string& attribute_name, const double& value)
	{
		relation_instance_attributes[attribute_name] = {DataType::DOUBLE, value};
		return shared_from_this();
	}

	shared_ptr<RelationInstanceBuilder> RelationInstanceBuilder::attribute(const string& attribute_name, const string& value)
	{
		relation_instance_attributes[attribute_name] = {DataType::STRING, value};
		return shared_from_this();
	}

	O_REL_INST RelationInstanceBuilder::build()
	{
		O_REL_INST o_relation_instance = nullopt;
		if (!o_relation_type.has_value() && !relation_type_name.empty())
		{
			o_relation_type = relation_type_manager->get_relation_type(relation_type_name);
		}
		if (o_relation_type.has_value())
		{
			if (!relation_instance_uuid.empty())
			{
				o_relation_instance = relation_instance_manager->create_relation_instance(xg::Guid(relation_instance_uuid), o_relation_type.value(), ent_instance_source, ent_instance_target);
			} else {
				o_relation_instance = relation_instance_manager->create_relation_instance(o_relation_type.value(), ent_instance_source, ent_instance_target);
			}
		}
		if (o_relation_instance.has_value())
		{
			REL_INST relation_instance = o_relation_instance.value();
			// TODO: set attribute values
			for (auto& attr_entry : relation_instance_attributes) {
				string attr_name = attr_entry.first;
				DataContainerInitializer attr_value = attr_entry.second;
//				O_REL_ATTR_INST o_attr_inst = relation_instance->get_attribute_instance(attr_entry.first);
//				if (o_attr_inst.has_value()) {
//					REL_ATTR_INST attr_inst = o_attr_inst.value();
//					if (attr_inst->type == attr_value.type) {
//						attr_inst->value.Set(attr_value.value.Value());
//						switch (attr_inst->type)
//						{
//							case DataType::INT:
//								spdlog::debug("Set attribute {} = {}", attr_name, std::get<DataType::INT>(attr_inst->value.Value()));
//								break;
//							case DataType::STRING:
//								spdlog::debug("Set attribute {} = {}", attr_name, std::get<DataType::STRING>(attr_inst->value.Value()));
//								break;
//							default:
//								break;
//						}
//					} else {
//						// Error: Wrong datatype
//						spdlog::error("Wrong datatype for attribute {}: {} != {}", attr_name, attr_inst->type, attr_value.type);
//						return std::nullopt;
//					}
//				} else {
//					// Error: Attribute not found by name
//					spdlog::error("Relation instance attribute {} not found", attr_name);
//					return std::nullopt;
//				}
			}
			return o_relation_instance;
		} else {
			spdlog::error("Failed to create relation instance");
			return std::nullopt;
		}
	}

}
}
