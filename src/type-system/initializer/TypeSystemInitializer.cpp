#include <type-system/initializer/TypeSystemInitializer.hpp>

#include "spdlog/spdlog.h"
#include <nlohmann/json.hpp>

#include "entity-system/builders/entities/entity-type-builder/EntityTypeBuilder.hpp"

namespace inexor::entity_system::type_system {

using EntityTypeBuilderPtr = std::shared_ptr<EntityTypeBuilder>;
using AttributeList = std::unordered_map<std::string, std::pair<DataType, Features>>;
using json = nlohmann::json;

TypeSystemInitializer::TypeSystemInitializer(EntityTypeJsonSerializerPtr entity_type_json_serializer)
    : LifeCycleComponent()
{
    this->entity_type_json_serializer = std::move(entity_type_json_serializer);
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

void TypeSystemInitializer::load_type_definition(const Corrade::Utility::Resource &rs, const std::string &file)
{
    using namespace magic_enum::bitwise_operators;
    std::string type_definition_str = rs.get(file);
    EntityTypePtrOpt o_ent_type = entity_type_json_serializer->load(type_definition_str);
    if (o_ent_type.has_value())
    {
        EntityTypePtr ent_type = o_ent_type.value();
        std::string ent_type_json = entity_type_json_serializer->save(ent_type);
        spdlog::info(ent_type_json);
    }
}

} // namespace inexor::entity_system::type_system
