#include <entity-system/serializers/EntityTypeJsonSerializer.hpp>

#include "spdlog/spdlog.h"
#include <nlohmann/json.hpp>

#include "entity-system/builders/entities/entity-type-builder/EntityTypeBuilder.hpp"

namespace inexor::entity_system::serializers {

using EntityTypeBuilderPtr = std::shared_ptr<EntityTypeBuilder>;
using AttributeList = std::unordered_map<std::string, std::pair<DataType, Features>>;
using json = nlohmann::json;

EntityTypeJsonSerializer::EntityTypeJsonSerializer(EntityTypeBuilderFactoryPtr entity_type_builder_factory) : LifeCycleComponent()
{
    this->entity_type_builder_factory = std::move(entity_type_builder_factory);
}

EntityTypePtrOpt EntityTypeJsonSerializer::load(const std::string &type_definition_str)
{
    using namespace magic_enum::bitwise_operators;
    json type_definition = json::parse(type_definition_str);
    auto type = type_definition["type"].get<std::string>();
    auto type_name = type_definition["name"].get<std::string>();
    if (type == "entity")
    {
        EntityTypeBuilderPtr builder = entity_type_builder_factory->get_builder();
        builder->name(type_name);
        json attrs = type_definition["attributes"];
        for (auto attr : attrs)
        {
            auto attr_name = attr["name"].get<std::string>();
            auto attr_datatype_str = attr["datatype"].get<std::string>();
            auto attr_datatype = magic_enum::enum_cast<DataType>(attr_datatype_str);
            json attr_features = attr["features"];
            Features attr_features_bitset = Features::NONE;
            for (const auto &attr_feature : attr_features)
            {
                auto attr_feature_name_str = attr_feature.get<std::string>();
                auto attr_feature_name = magic_enum::enum_cast<Features>(attr_feature_name_str);
                if (attr_feature_name.has_value())
                {
                    attr_features_bitset = attr_features_bitset | attr_feature_name.value();
                } else
                {
                    spdlog::error("Failed to add feature attribute {}.{}: {}", type_name, attr_name, attr_feature_name_str);
                }
            }
            if (attr_datatype.has_value())
            {
                int features_as_int = magic_enum::enum_integer(attr_features_bitset);
                constexpr auto all_features = magic_enum::enum_values<Features>();
                for (Features feature : all_features)
                {
                    std::string feature_name = std::string(magic_enum::enum_name(feature));
                    bool has_feature = magic_enum::enum_integer(attr_features_bitset & feature);
                    spdlog::debug("{}.{} {}={}", type_name, attr_name, feature_name, has_feature ? "true" : "false");
                }
                builder->attribute(attr_name, attr_datatype.value(), attr_features_bitset);
                spdlog::info("Successfully added attribute {}.{} of data type {}", type_name, attr_name, attr_datatype_str);
            } else
            {
                spdlog::error("Failed to add attribute {}.{}: Unknown data type: {}", type_name, attr_name, attr_datatype_str);
            }
        }
        // Random uuid
        builder->uuid(xg::newGuid().str());
        EntityTypePtrOpt ent_type_opt = builder->build();
        if (ent_type_opt.has_value())
        {
            spdlog::info("Successfully created {} type {} [UUID: {}]", type, type_name, ent_type_opt.value()->get_GUID().str());
            return ent_type_opt;
        } else
        {
            spdlog::error("Failed to create {} type {}", type, type_name);
        }
    } else
    {
        spdlog::error("Invalid type: {}", type);
    }
    return std::nullopt;
}

std::string EntityTypeJsonSerializer::save(const EntityTypePtr &ent_type)
{
    using namespace magic_enum::bitwise_operators;
    json j_ent_type;
    j_ent_type["type"] = "entity";
    j_ent_type["name"] = ent_type->get_type_name();
    j_ent_type["uuid"] = ent_type->get_GUID().str();
    j_ent_type["attributes"] = json::array();
    std::optional<EntityAttributeTypePtrList> o_ent_type_attributes = ent_type->get_linked_attribute_types();
    if (o_ent_type_attributes.has_value())
    {
        std::vector<EntityAttributeTypePtr> ent_type_attributes = o_ent_type_attributes.value();
        for (const auto &ent_type_attribute : ent_type_attributes)
        {
            std::string datatype = std::string(magic_enum::enum_name(ent_type_attribute->get_attribute_data_type()));
            json j_features = json::array();
            Features attr_features = ent_type_attribute->get_attribute_features();
            constexpr auto all_features = magic_enum::enum_values<Features>();
            for (Features feature : all_features)
            {
                bool has_feature = magic_enum::enum_integer(attr_features & feature);
                if (has_feature)
                {
                    std::string feature_name = std::string(magic_enum::enum_name(feature));
                    j_features.push_back(feature_name);
                }
            }
            j_ent_type["attributes"].push_back(
                {
                    { "uuid", ent_type_attribute->get_GUID().str() },
                    { "name", ent_type_attribute->get_type_name() },
                    { "datatype", datatype },
                    { "features", j_features }
                }
            );
        }
    }
    return j_ent_type.dump();
}

std::string EntityTypeJsonSerializer::get_component_name()
{
    return "EntityTypeJsonSerializer";
}

} // namespace inexor::entity_system::serializers
