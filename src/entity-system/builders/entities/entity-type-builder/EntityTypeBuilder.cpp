#include "EntityTypeBuilder.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace entity_system {

	/// These using instructions help to shorten the following code.
	using EntityAttributeTypePtr = std::shared_ptr<EntityAttributeType>;
	using EntityAttributeTypePtrOpt = std::optional<EntityAttributeTypePtr>;

	EntityTypeBuilder::EntityTypeBuilder(
		EntityTypeManagerPtr entity_type_manager,
		EntityAttributeTypeManagerPtr entity_attribute_type_manager,
		EntityAttributeInstanceManagerPtr entity_attribute_instance_manager
	)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(entity_type_builder_mutex);

		this->entity_type_manager = entity_type_manager;
		this->entity_attribute_type_manager = entity_attribute_type_manager;
		this->entity_attribute_instance_manager = entity_attribute_instance_manager;
		entity_type_name = "";
		entity_type_uuid = "";
	}

	EntityTypeBuilder::~EntityTypeBuilder()
	{
	}

	EntityTypeBuilderPtr EntityTypeBuilder::name(std::string entity_type_name)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(entity_type_builder_mutex);

		this->entity_type_name = entity_type_name;
		return shared_from_this();
	}

	EntityTypeBuilderPtr EntityTypeBuilder::uuid(std::string entity_type_uuid)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(entity_type_builder_mutex);

		this->entity_type_uuid = entity_type_uuid;
		return shared_from_this();
	}

	EntityTypeBuilderPtr EntityTypeBuilder::attribute(const std::string& attribute_name, const DataType& attribute_datatype, const EnumSet<Feature>& attribute_features)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(entity_type_builder_mutex);
		entity_type_attributes[attribute_name] = { attribute_datatype, attribute_features };
		return shared_from_this();
	}

	EntityTypeBuilderPtr EntityTypeBuilder::input(const std::string& attribute_name, const DataType& attribute_datatype)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(entity_type_builder_mutex);

		entity_type_attributes[attribute_name] = { attribute_datatype, { 1 << Feature::INPUT } };
		return shared_from_this();
	}

	EntityTypeBuilderPtr EntityTypeBuilder::output(const std::string& attribute_name, const DataType& attribute_datatype)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(entity_type_builder_mutex);

		entity_type_attributes[attribute_name] = { attribute_datatype, { 1 << Feature::OUTPUT } };
		return shared_from_this();
	}

	EntityTypeBuilderPtr EntityTypeBuilder::inout(const std::string& attribute_name, const DataType& attribute_datatype)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(entity_type_builder_mutex);

		entity_type_attributes[attribute_name] = { attribute_datatype, { 1 << Feature::INPUT | 1 << Feature::OUTPUT } };
		return shared_from_this();
	}

	EntityTypePtrOpt EntityTypeBuilder::build()
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(entity_type_builder_mutex);

		EntityTypePtrOpt o_entity_type;

		if(!entity_type_uuid.empty())
		{
			o_entity_type = entity_type_manager->create_entity_type(xg::Guid(entity_type_uuid), entity_type_name);
		}
		else
		{
			o_entity_type = entity_type_manager->create_entity_type(entity_type_name);
		}
		if(o_entity_type.has_value())
		{
			EntityTypePtr entity_type = o_entity_type.value();
			for(auto& attribute_entry : entity_type_attributes)
			{
				EntityAttributeTypePtrOpt o_attribute_type = entity_attribute_type_manager->create_entity_attribute_type(attribute_entry.first, attribute_entry.second.first, attribute_entry.second.second);
				if(o_attribute_type.has_value())
				{
					EntityAttributeTypePtr attribute_type = o_attribute_type.value();
					entity_type->link_attribute_type(attribute_type);
					spdlog::debug("Created entity type attribute '{}' of data type '{}'", attribute_entry.first, attribute_entry.second.first._to_string());
				}
				else
				{
					spdlog::error("Failed to create entity type '{}': Failed to create entity type attribute '{}' of data type '{}'", entity_type_name, attribute_entry.first, attribute_entry.second.first._to_string());
					return std::nullopt;
				}
			}
			return entity_type;
		}
		else
		{
			spdlog::error("Failed to create entity type '{}'", entity_type_name);
			return std::nullopt;
		}
	}

}
}
