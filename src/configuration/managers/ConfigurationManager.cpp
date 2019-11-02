#include "ConfigurationManager.hpp"

#include <utility>

#include "entity-system/model/data/container/DataContainer.hpp"

#include "spdlog/spdlog.h"

namespace inexor::configuration {

ConfigurationManager::ConfigurationManager(BoolConstantFactoryPtr bool_constant_factory, IntConstantFactoryPtr int_constant_factory, FloatConstantFactoryPtr float_constant_factory, StringConstantFactoryPtr string_constant_factory,
                                           LogManagerPtr log_manager)
{
    this->bool_constant_factory = std::move(bool_constant_factory);
    this->int_constant_factory = std::move(int_constant_factory);
    this->float_constant_factory = std::move(float_constant_factory);
    this->string_constant_factory = std::move(string_constant_factory);
    this->log_manager = std::move(log_manager);
}

ConfigurationManager::~ConfigurationManager() = default;

void ConfigurationManager::init()
{
    log_manager->register_logger(LOGGER_NAME);
}

bool ConfigurationManager::exists(const std::string &config_name)
{
    // TODO: c++20: return config_names.contains(config_name);
    return config_items.find(config_name) != config_items.end();
}

void ConfigurationManager::set(const std::string &config_name, bool value)
{
    if (!exists(config_name))
    {
        insert(config_name, BOOL_CONSTANT_VALUE, bool_constant_factory->create_instance(config_name, value));
    } else
    {
        config_items[config_name]->own_value.Set(value);
    }
}

void ConfigurationManager::set(const std::string &config_name, int value)
{
    if (!exists(config_name))
    {
        insert(config_name, INT_CONSTANT_VALUE, int_constant_factory->create_instance(config_name, value));
    } else
    {
        config_items[config_name]->own_value.Set(value);
    }
}

void ConfigurationManager::set(const std::string &config_name, float value)
{
    if (!exists(config_name))
    {
        insert(config_name, FLOAT_CONSTANT_VALUE, float_constant_factory->create_instance(config_name, value));
    } else
    {
        config_items[config_name]->own_value.Set(value);
    }
}

void ConfigurationManager::set(const std::string &config_name, std::string value)
{
    if (!exists(config_name))
    {
        insert(config_name, STRING_CONSTANT_VALUE, string_constant_factory->create_instance(config_name, value));
    } else
    {
        config_items[config_name]->own_value.Set(value);
    }
}

bool ConfigurationManager::get_bool(const std::string &config_name)
{
    return std::get<DataType::BOOL>(config_items[config_name]->value.Value());
}

int ConfigurationManager::get_int(const std::string &config_name)
{
    return std::get<DataType::INT>(config_items[config_name]->value.Value());
}

float ConfigurationManager::get_float(const std::string &config_name)
{
    return std::get<DataType::FLOAT>(config_items[config_name]->value.Value());
}

std::string ConfigurationManager::get_string(const std::string &config_name)
{
    return std::get<DataType::STRING>(config_items[config_name]->value.Value());
}

DataType ConfigurationManager::get_type(const std::string &config_name)
{
    return config_items[config_name]->type;
}

void ConfigurationManager::list()
{
    spdlog::get(LOGGER_NAME)->info("Configuration items:");
    for (auto &it : config_items)
    {
        spdlog::get(LOGGER_NAME)->info("  [{}] [{}] [{}]", it.first, magic_enum::enum_name(it.second->type), data_value_to_string(it.second->type, it.second->value.Value()));
    }
}

void ConfigurationManager::insert(const std::string &config_name, const std::string& attribute_name, EntityInstancePtrOpt config_item)
{
    if (config_item.has_value())
    {
        EntityInstancePtr entity_instance = config_item.value();
        EntityAttributeInstancePtrOpt o_attribute_instance = entity_instance->get_attribute_instance(attribute_name);

        if (o_attribute_instance.has_value())
        {
            config_items[config_name] = o_attribute_instance.value();
            spdlog::get(LOGGER_NAME)->info("Added configuration: [{}] [{}] [{}]", config_name, magic_enum::enum_name(config_items[config_name]->type), data_value_to_string(config_items[config_name]->type, config_items[config_name]->value.Value()));
        }
    }
}

} // namespace inexor::configuration
