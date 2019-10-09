#include "RelationTypeBuilder.hpp"

#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/relations/relation-types/RelationType.hpp"
#include "entity-system/model/relation-attributes/relation-attribute-types/RelationAttributeType.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace entity_system {

	/// These using instructions help to shorten the following code.
	using RelationAttributeTypePtr = std::shared_ptr<RelationAttributeType>;
	using RelationAttributeTypePtrOpt = std::optional<RelationAttributeTypePtr>;

	RelationTypeBuilder::RelationTypeBuilder(
		RelationTypeManagerPtr relation_type_manager,
		RelationAttributeTypeManagerPtr relation_attribute_type_manager,
		RelationAttributeInstanceManagerPtr relation_attribute_instance_manager
	)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_type_builder_mutex);
		
		this->relation_type_manager = relation_type_manager;
		this->relation_attribute_type_manager = relation_attribute_type_manager;
		this->relation_attribute_instance_manager = relation_attribute_instance_manager;
		relation_type_name = "";
		relation_type_uuid = "";
	}

	RelationTypeBuilder::~RelationTypeBuilder()
	{
	}

	RelationTypeBuilderPtr RelationTypeBuilder::name(std::string relation_type_name)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_type_builder_mutex);

		this->relation_type_name = relation_type_name;
		return shared_from_this();
	}

	RelationTypeBuilderPtr RelationTypeBuilder::uuid(std::string relation_type_uuid)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_type_builder_mutex);

		this->relation_type_uuid = relation_type_uuid;
		return shared_from_this();
	}

	RelationTypeBuilderPtr RelationTypeBuilder::source(EntityTypePtr ent_type_source)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_type_builder_mutex);

		this->ent_type_source = ent_type_source;
		return shared_from_this();
	}

	RelationTypeBuilderPtr RelationTypeBuilder::target(EntityTypePtr ent_type_target)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_type_builder_mutex);

		this->ent_type_target = ent_type_target;
		return shared_from_this();
	}

	RelationTypeBuilderPtr RelationTypeBuilder::attribute(std::string attribute_name, DataType attribute_datatype, const EnumSet<Feature>& attribute_features)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_type_builder_mutex);

		relation_type_attributes[attribute_name] = { attribute_datatype, attribute_features };
		return shared_from_this();
	}

	RelationTypePtrOpt RelationTypeBuilder::build()
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_type_builder_mutex);
		
		RelationTypePtrOpt o_relation_type;
		
		if(!relation_type_uuid.empty())
		{
			o_relation_type = relation_type_manager->create_relation_type(xg::Guid(relation_type_uuid), relation_type_name, ent_type_source, ent_type_target);
		}
		else
		{
			o_relation_type = relation_type_manager->create_relation_type(relation_type_name, ent_type_source, ent_type_target);
		}
		if(o_relation_type.has_value())
		{
			std::shared_ptr<RelationType> relation_type = o_relation_type.value();
			for(auto& attribute_entry : relation_type_attributes)
			{
				RelationAttributeTypePtrOpt o_attribute_type = relation_attribute_type_manager->create_relation_attribute_type(attribute_entry.first, attribute_entry.second.first, attribute_entry.second.second);
				if(o_attribute_type.has_value())
				{
					RelationAttributeTypePtr attribute_type = o_attribute_type.value();
					relation_type->link_relation_attribute_type(attribute_type);
					spdlog::debug("Created relation type attribute {} of data type {}", attribute_entry.first, attribute_entry.second.first);
				}
				else
				{
					spdlog::error("Failed to create relation type attribute {} of data type {}", attribute_entry.first, attribute_entry.second.first);
					return std::nullopt;
				}
			}
			return relation_type;
		}
		else
		{
			spdlog::error("Failed to create relation type {}", relation_type_name);
			return std::nullopt;
		}
	}

}
}
