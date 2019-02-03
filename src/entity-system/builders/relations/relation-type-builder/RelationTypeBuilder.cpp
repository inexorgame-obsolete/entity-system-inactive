// Inexor entity system
// (c)2018 Inexor

#include "RelationTypeBuilder.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {


	RelationTypeBuilder::RelationTypeBuilder(
		shared_ptr<RelationTypeManager> relation_type_manager,
		shared_ptr<RelationAttributeTypeManager> relation_attribute_type_manager,
		shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager
	)
	{
		this->relation_type_manager = relation_type_manager;
		this->relation_attribute_type_manager = relation_attribute_type_manager;
		this->relation_attribute_instance_manager = relation_attribute_instance_manager;
		relation_type_name = "";
		relation_type_uuid = "";
	}

	RelationTypeBuilder::~RelationTypeBuilder()
	{
	}

	shared_ptr<RelationTypeBuilder> RelationTypeBuilder::name(string relation_type_name)
	{
		this->relation_type_name = relation_type_name;
		return shared_from_this();
	}

	shared_ptr<RelationTypeBuilder> RelationTypeBuilder::uuid(string relation_type_uuid)
	{
		this->relation_type_uuid = relation_type_uuid;
		return shared_from_this();
	}

	shared_ptr<RelationTypeBuilder> RelationTypeBuilder::source(ENT_TYPE ent_type_source)
	{
		this->ent_type_source = ent_type_source;
		return shared_from_this();
	}

	shared_ptr<RelationTypeBuilder> RelationTypeBuilder::target(ENT_TYPE ent_type_target)
	{
		this->ent_type_target = ent_type_target;
		return shared_from_this();
	}

	shared_ptr<RelationTypeBuilder> RelationTypeBuilder::attribute(string attribute_name, ENTSYS_DATA_TYPE attribute_datatype)
	{
		relation_type_attributes[attribute_name] = attribute_datatype;
		return shared_from_this();
	}

	O_REL_TYPE RelationTypeBuilder::build()
	{
		O_REL_TYPE o_relation_type = relation_type_manager->create_relation_type(relation_type_name, ent_type_source, ent_type_target);
		if (o_relation_type.has_value())
		{
			shared_ptr<RelationType> relation_type = o_relation_type.value();
			for (auto& attribute_entry : relation_type_attributes) {
				O_REL_ATTR_TYPE o_attribute_type = relation_attribute_type_manager->create_relation_attribute_type(attribute_entry.first, attribute_entry.second);
				if (o_attribute_type.has_value()) {
					REL_ATTR_TYPE attribute_type = o_attribute_type.value();
					relation_type->link_relation_attribute_type(attribute_type);
					spdlog::debug("Created relation type attribute {} of data type {}", attribute_entry.first, attribute_entry.second);
				} else {
					spdlog::error("Failed to create relation type attribute {} of data type {}", attribute_entry.first, attribute_entry.second);
					return std::nullopt;
				}
			}
			return relation_type;
		} else {
			spdlog::error("Failed to create relation type {}", relation_type_name);
			return std::nullopt;
		}
	}

}
}
