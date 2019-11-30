#include "TypeSystemInitializer.hpp"

#include "spdlog/spdlog.h"
#include <nlohmann/json.hpp>

#include "entity-system/builders/entities/entity-type-builder/EntityTypeBuilder.hpp"

namespace inexor::entity_system::type_system {

using EntityTypeBuilderPtr = std::shared_ptr<EntityTypeBuilder>;
using AttributeList = std::unordered_map<std::string, std::pair<DataType, Features>>;
using json = nlohmann::json;

TypeSystemInitializer::TypeSystemInitializer(EntityTypeBuilderFactoryPtr entity_type_builder_factory)
    : LifeCycleComponent()
{
    this->entity_type_builder_factory = std::move(entity_type_builder_factory);
}

TypeSystemInitializer::~TypeSystemInitializer() = default;

void TypeSystemInitializer::pre_init()
{
    Corrade::Utility::Resource rs{RESOURCE_GROUP};
    load_type_definition(rs, "LOGGER.json");
}

void TypeSystemInitializer::init()
{
    Corrade::Utility::Resource rs{RESOURCE_GROUP};
    for (const std::string &file : rs.list())
    {
        load_type_definition(rs, file);
    }
}

std::string TypeSystemInitializer::get_component_name()
{
    return "TypeSystemInitializer";
}

void TypeSystemInitializer::load_type_definition(Corrade::Utility::Resource rs, const std::string &file)
{
    using namespace magic_enum::bitwise_operators;
    std::string type_definition_str = rs.get(file);
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
                    spdlog::error("[{}] Failed to add feature attribute {}.{}: {}", file, type_name, attr_name, attr_feature_name_str);
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
                    spdlog::debug("[{}] {}.{} {}={}", file, type_name, attr_name, feature_name, has_feature ? "true" : "false");
                }
                builder->attribute(attr_name, attr_datatype.value(), attr_features_bitset);
                spdlog::info("[{}] Successfully added attribute {}.{} of data type {}", file, type_name, attr_name, attr_datatype_str);
            } else
            {
                spdlog::error("[{}] Failed to add attribute {}.{}: Unknown data type: {}", file, type_name, attr_name, attr_datatype_str);
            }
        }
        // Random uuid
        builder->uuid(xg::newGuid().str());
        EntityTypePtrOpt ent_type_opt = builder->build();
        if (ent_type_opt.has_value())
        {
            spdlog::info("[{}] Successfully created {} type {} [UUID: {}]", file, type, type_name, ent_type_opt.value()->get_GUID().str());
        } else
        {
            spdlog::error("[{}] Failed to create {} type {}", file, type, type_name);
        }
    } else
    {
        spdlog::error("[{}] Invalid type: {}", file, type);
    }
}

} // namespace inexor::entity_system::type_system
