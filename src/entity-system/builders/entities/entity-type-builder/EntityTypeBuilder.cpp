// Inexor entity system
// (c)2018 Inexor

#include "EntityTypeBuilder.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {


	EntityTypeBuilder::EntityTypeBuilder(
		shared_ptr<EntityTypeManager> entity_type_manager,
		shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager,
		shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager
	)
	{
		this->entity_type_manager = entity_type_manager;
		this->entity_attribute_type_manager = entity_attribute_type_manager;
		this->entity_attribute_instance_manager = entity_attribute_instance_manager;
		entity_type_name = "";
		entity_type_uuid = "";
	}

	EntityTypeBuilder::~EntityTypeBuilder()
	{
	}

	shared_ptr<EntityTypeBuilder> EntityTypeBuilder::name(string entity_type_name)
	{
		this->entity_type_name = entity_type_name;
		return shared_from_this();
	}

	shared_ptr<EntityTypeBuilder> EntityTypeBuilder::uuid(string entity_type_uuid)
	{
		this->entity_type_uuid = entity_type_uuid;
		return shared_from_this();
	}

	shared_ptr<EntityTypeBuilder> EntityTypeBuilder::attribute(string attribute_name, ENTSYS_DATA_TYPE attribute_datatype)
	{
		entity_type_attributes[attribute_name] = attribute_datatype;
		return shared_from_this();
	}

	O_ENT_TYPE EntityTypeBuilder::build()
	{
		O_ENT_TYPE o_entity_type = entity_type_manager->create_entity_type(entity_type_name);
		if (o_entity_type.has_value())
		{
			shared_ptr<EntityType> entity_type = o_entity_type.value();
			for (auto& attribute_entry : entity_type_attributes) {
				O_ENT_ATTR_TYPE o_attribute_type = entity_attribute_type_manager->create_entity_attribute_type(attribute_entry.first, attribute_entry.second);
				if (o_attribute_type.has_value()) {
					ENT_ATTR_TYPE attribute_type = o_attribute_type.value();
					entity_type->link_attribute_type(attribute_type);
					spdlog::debug("Created entity type attribute {} of data type {}", attribute_entry.first, attribute_entry.second);
				} else {
					spdlog::error("Failed to create entity type attribute {} of data type {}", attribute_entry.first, attribute_entry.second);
					return std::nullopt;
				}
			}
			spdlog::info("Created entity type {} (UUID: {})", entity_type->get_type_name(), entity_type->get_GUID().str());
			return entity_type;
		} else {
			spdlog::error("Failed to create entity type {}", entity_type_name);
			return std::nullopt;
		}
	}

}
}
