#include <entity-system/builders/entities/entity-type-builder/EntityTypeBuilder.hpp>

#include <magic_enum.hpp>
#include <utility>

#include "spdlog/spdlog.h"

#if !defined(_MSC_VER)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"
#endif

namespace inexor::entity_system {

/// These using instructions help to shorten the following code.
using EntityAttributeTypePtr = std::shared_ptr<EntityAttributeType>;
using EntityAttributeTypePtrOpt = std::optional<EntityAttributeTypePtr>;

EntityTypeBuilder::EntityTypeBuilder(EntityTypeManagerPtr entity_type_manager, EntityAttributeTypeManagerPtr entity_attribute_type_manager, EntityAttributeInstanceManagerPtr entity_attribute_instance_manager)
{
    this->entity_type_manager = std::move(entity_type_manager);
    this->entity_attribute_type_manager = std::move(entity_attribute_type_manager);
    this->entity_attribute_instance_manager = std::move(entity_attribute_instance_manager);
    entity_type_name = "";
    entity_type_uuid = "";
}

EntityTypeBuilder::~EntityTypeBuilder() = default;

EntityTypeBuilderPtr EntityTypeBuilder::name(const std::string &entity_type_name)
{
    this->entity_type_name = entity_type_name;
    return shared_from_this();
}

EntityTypeBuilderPtr EntityTypeBuilder::uuid(const std::string &entity_type_uuid)
{
    this->entity_type_uuid = entity_type_uuid;
    return shared_from_this();
}

EntityTypeBuilderPtr EntityTypeBuilder::uuid(const xg::Guid &entity_type_uuid)
{
    this->entity_type_uuid = entity_type_uuid.str();
    return shared_from_this();
}

EntityTypeBuilderPtr EntityTypeBuilder::attribute(const std::string &attribute_name, const DataType &attribute_datatype, const Features &attribute_features)
{
    entity_type_attributes[attribute_name] = {attribute_datatype, attribute_features};
    return shared_from_this();
}

EntityTypeBuilderPtr EntityTypeBuilder::input(const std::string &attribute_name, const DataType &attribute_datatype)
{
    entity_type_attributes[attribute_name] = {attribute_datatype, Features::INPUT};
    return shared_from_this();
}

EntityTypeBuilderPtr EntityTypeBuilder::output(const std::string &attribute_name, const DataType &attribute_datatype)
{
    entity_type_attributes[attribute_name] = {attribute_datatype, Features::OUTPUT};
    return shared_from_this();
}

EntityTypeBuilderPtr EntityTypeBuilder::inout(const std::string &attribute_name, const DataType &attribute_datatype)
{
    using namespace magic_enum::bitwise_operators;
    entity_type_attributes[attribute_name] = {attribute_datatype, Features::INPUT | Features::OUTPUT};
    return shared_from_this();
}

EntityTypePtrOpt EntityTypeBuilder::build()
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(entity_type_builder_mutex);

    EntityTypePtrOpt o_entity_type;

    if (!entity_type_uuid.empty())
    {
        o_entity_type = entity_type_manager->create_entity_type(xg::Guid(entity_type_uuid), entity_type_name);
    } else
    {
        o_entity_type = entity_type_manager->create_entity_type(entity_type_name);
    }
    if (o_entity_type.has_value())
    {
        EntityTypePtr entity_type = o_entity_type.value();
        for (auto &attribute_entry : entity_type_attributes)
        {
            EntityAttributeTypePtrOpt o_attribute_type = entity_attribute_type_manager->create_entity_attribute_type(attribute_entry.first, attribute_entry.second.first, attribute_entry.second.second);
            if (o_attribute_type.has_value())
            {
                EntityAttributeTypePtr attribute_type = o_attribute_type.value();
                if (!entity_type->link_attribute_type(attribute_type))
                {
                    spdlog::error("Failed to create entity type '{}': Failed to create entity type attribute '{}' of data type '{}'", entity_type_name, attribute_entry.first, magic_enum::enum_name(attribute_entry.second.first));
                    return std::nullopt;
                }
                spdlog::debug("Created entity type attribute '{}' of data type '{}'", attribute_entry.first, magic_enum::enum_name(attribute_entry.second.first));
            } else
            {
                spdlog::error("Failed to create entity type '{}': Failed to create entity type attribute '{}' of data type '{}'", entity_type_name, attribute_entry.first, magic_enum::enum_name(attribute_entry.second.first));
                return std::nullopt;
            }
        }
        return entity_type;
    } else
    {
        spdlog::error("Failed to create entity type '{}'", entity_type_name);
        return std::nullopt;
    }
}

} // namespace inexor::entity_system

#if !defined(_MSC_VER)
#pragma clang diagnostic pop
#endif
