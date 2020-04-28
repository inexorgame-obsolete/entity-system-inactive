#include <entity-system/serializers/EntityInstanceJsonSerializer.hpp>

#include "spdlog/spdlog.h"
#include <nlohmann/json.hpp>

#include "entity-system/builders/entities/entity-instance-builder/EntityInstanceBuilder.hpp"

namespace inexor::entity_system::serializers {

using EntityInstanceBuilderPtr = std::shared_ptr<EntityInstanceBuilder>;
using AttributeList = std::unordered_map<std::string, std::pair<DataType, Features>>;
using json = nlohmann::json;

EntityInstanceJsonSerializer::EntityInstanceJsonSerializer(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory, EntityTypeManagerPtr entity_type_manager) : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
    this->entity_type_manager = std::move(entity_type_manager);
}

EntityInstancePtrOpt EntityInstanceJsonSerializer::load(const std::string &instance_definition_str)
{
    return load(instance_definition_str, false);
}

EntityInstancePtrOpt EntityInstanceJsonSerializer::load(const std::string &instance_definition_str, bool random_uuid)
{
    using namespace magic_enum::bitwise_operators;
    json instance_definition = json::parse(instance_definition_str);
    auto model = instance_definition["model"].get<std::string>();
    auto type_uuid = instance_definition["type_uuid"].get<std::string>();
    auto type_name = instance_definition["type"].get<std::string>();
    if (model == "entity_instance")
    {
        EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(type_name);
        if (o_ent_type.has_value())
        {
            EntityTypePtr ent_type = o_ent_type.value();
            EntityInstanceBuilderPtr builder = entity_instance_builder_factory->get_builder(type_name);
            if (!random_uuid) {
                auto uuid = instance_definition["uuid"].get<std::string>();
                builder->uuid(uuid);
            } else {
                builder->uuid(xg::newGuid().str());
            }
            json attrs = instance_definition["attributes"];
            for (auto attr : attrs)
            {
                auto attr_inst_uuid = attr["uuid"].get<std::string>();
                // auto attr_type_uuid = attr["type_uuid"].get<std::string>();
                auto attr_name = attr["name"].get<std::string>();

                EntityAttributeTypePtrOpt o_ent_attr_type = ent_type->get_attribute_type(attr_name);
                if (o_ent_attr_type.has_value())
                {
                    EntityAttributeTypePtr ent_attr_type = o_ent_attr_type.value();
                    DataType data_type = ent_attr_type->get_attribute_data_type();
                    spdlog::info("DATATYPE: {}", std::string(magic_enum::enum_name(data_type)));
                    switch (data_type)
                    {
                        case DataType::BOOL:
                            {
                                const auto &b_value = attr["value"].get<bool>();
                                spdlog::info("b_value: {}={}", attr_name, b_value);
                                builder->attribute(attr_name, b_value);
                                break;
                            }
                        case DataType::INT:
                            {
                                const auto &i_value = attr["value"].get<int>();
                                spdlog::info("i_value: {}={}", attr_name, i_value);
                                builder->attribute(attr_name, i_value);
                                break;
                            }
                        case DataType::BIG_INT:
                            {
                                const auto &bi_value = attr["value"].get<int64_t>();
                                spdlog::info("bi_value: {}={}", attr_name, bi_value);
                                builder->attribute(attr_name, bi_value);
                                break;
                            }
                        case DataType::DOUBLE:
                            {
                                const auto &d_value = attr["value"].get<double>();
                                spdlog::info("d_value: {}={}", attr_name, d_value);
                                builder->attribute(attr_name, d_value);
                                break;
                            }
                        case DataType::FLOAT:
                            {
                                const auto &f_value = attr["value"].get<float>();
                                spdlog::info("f_value: {}={}", attr_name, f_value);
                                builder->attribute(attr_name, f_value);
                                break;
                            }
                        case DataType::STRING:
                            {
                                const auto &s_value = attr["value"].get<std::string>();
                                spdlog::info("f_value: {}={}", attr_name, s_value);
                                builder->attribute(attr_name, s_value);
                                break;
                            }
                        default:
                            break;
                    }
                }
            }
            EntityInstancePtrOpt ent_inst_opt = builder->build();
            if (ent_inst_opt.has_value())
            {
                spdlog::info("Successfully created {} {} [UUID: {}]", type_uuid, type_name, ent_inst_opt.value()->get_GUID().str());
                return ent_inst_opt;
            } else
            {
                spdlog::error("Failed to create {} type {}", type_uuid, type_name);
            }
        } else
        {
            spdlog::error("Invalid type: {}", type_uuid);
        }
    }
    return std::nullopt;
}

std::string EntityInstanceJsonSerializer::save(const EntityInstancePtr &ent_inst)
{
    using namespace magic_enum::bitwise_operators;

    EntityTypePtr ent_type = ent_inst->get_entity_type();

    json j_ent_type;
    j_ent_type["model"] = "entity_instance";
    j_ent_type["type"] = ent_type->get_type_name();
    j_ent_type["type_uuid"] = ent_type->get_GUID().str();
    j_ent_type["uuid"] = ent_inst->get_GUID().str();
    j_ent_type["attributes"] = json::array();
    std::optional<std::unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr>> o_ent_inst_attributes = ent_inst->get_instances();
    if (o_ent_inst_attributes.has_value())
    {
        std::unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr> ent_inst_attributes = o_ent_inst_attributes.value();
        for (const auto &ent_inst_attribute : ent_inst_attributes)
        {
            EntityAttributeTypePtr ent_attr_type = ent_inst_attribute.first;
            EntityAttributeInstancePtr ent_attr_inst = ent_inst_attribute.second;
            DataType dataType = ent_attr_type->get_attribute_data_type();
            std::string dataTypeAsStr = std::string(magic_enum::enum_name(dataType));
            DataValue dataValue = ent_attr_inst->value.Value();

            switch (dataType)
            {
                case DataType::BOOL:
                    j_ent_type["attributes"].push_back({ { "uuid", ent_attr_inst->get_GUID().str() }, /* { "type_uuid", ent_attr_type->get_GUID().str() }, */ { "name", ent_attr_type->get_type_name() }, { "value", std::get<DataType::BOOL>(dataValue) } });
                    break;
                case DataType::INT:
                    j_ent_type["attributes"].push_back({ { "uuid", ent_attr_inst->get_GUID().str() }, /* { "type_uuid", ent_attr_type->get_GUID().str() }, */ { "name", ent_attr_type->get_type_name() }, { "value", std::get<DataType::INT>(dataValue) } });
                    break;
                case DataType::BIG_INT:
                    j_ent_type["attributes"].push_back({ { "uuid", ent_attr_inst->get_GUID().str() }, /* { "type_uuid", ent_attr_type->get_GUID().str() }, */ { "name", ent_attr_type->get_type_name() }, { "value", std::get<DataType::BIG_INT>(dataValue) } });
                    break;
                case DataType::DOUBLE:
                    j_ent_type["attributes"].push_back({ { "uuid", ent_attr_inst->get_GUID().str() }, /* { "type_uuid", ent_attr_type->get_GUID().str() }, */ { "name", ent_attr_type->get_type_name() }, { "value", std::get<DataType::DOUBLE>(dataValue) } });
                    break;
                case DataType::FLOAT:
                    j_ent_type["attributes"].push_back({ { "uuid", ent_attr_inst->get_GUID().str() }, /* { "type_uuid", ent_attr_type->get_GUID().str() }, */ { "name", ent_attr_type->get_type_name() }, { "value", std::get<DataType::FLOAT>(dataValue) } });
                    break;
                case DataType::STRING:
                    j_ent_type["attributes"].push_back({ { "uuid", ent_attr_inst->get_GUID().str() }, /* { "type_uuid", ent_attr_type->get_GUID().str() }, */ { "name", ent_attr_type->get_type_name() }, { "value", std::get<DataType::STRING>(dataValue) } });
                    break;
                default:
                    break;
            }
        }
    }
    return j_ent_type.dump();
}

std::string EntityInstanceJsonSerializer::get_component_name()
{
    return "EntityInstanceJsonSerializer";
}

} // namespace inexor::entity_system::serializers
