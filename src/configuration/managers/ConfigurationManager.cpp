#include "ConfigurationManager.hpp"

#include "spdlog/spdlog.h"

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

namespace inexor {
namespace configuration {

	ConfigurationManager::ConfigurationManager(
		BoolConstantFactoryPtr bool_constant_factory,
		IntConstantFactoryPtr int_constant_factory,
		FloatConstantFactoryPtr float_constant_factory,
		StringConstantFactoryPtr string_constant_factory
	)
	{
		this->bool_constant_factory = bool_constant_factory;
		this->int_constant_factory = int_constant_factory;
		this->float_constant_factory = float_constant_factory;
		this->string_constant_factory = string_constant_factory;
	}

	ConfigurationManager::~ConfigurationManager()
	{
	}

	void ConfigurationManager::init()
	{
#ifdef _WIN32
		set("PID", _getpid());
#else
		set("PID", getpid());
#endif
		set("SYS_NUM_CONCURRENT_THREADS", (int) std::thread::hardware_concurrency());
		list();
	}

	bool ConfigurationManager::exists(std::string config_name)
	{
		// TODO: c++20: return config_names.contains(config_name);
		return config_items.find(config_name) != config_items.end();
	}

	void ConfigurationManager::set(std::string config_name, bool value)
	{
		if (!exists(config_name))
		{
			insert(config_name, BOOL_CONSTANT_VALUE, bool_constant_factory->create_instance(config_name, value));
		} else {
			config_items[config_name]->own_value.Set(value);
		}
	}

	void ConfigurationManager::set(std::string config_name, int value)
	{
		if (!exists(config_name))
		{
			insert(config_name, INT_CONSTANT_VALUE, int_constant_factory->create_instance(config_name, value));
		} else {
			config_items[config_name]->own_value.Set(value);
		}
	}

	void ConfigurationManager::set(std::string config_name, float value)
	{
		if (!exists(config_name))
		{
			insert(config_name, FLOAT_CONSTANT_VALUE, float_constant_factory->create_instance(config_name, value));
		} else {
			config_items[config_name]->own_value.Set(value);
		}
	}

	void ConfigurationManager::set(std::string config_name, std::string value)
	{
		if (!exists(config_name))
		{
			insert(config_name, STRING_CONSTANT_VALUE, string_constant_factory->create_instance(config_name, value));
		} else {
			config_items[config_name]->own_value.Set(value);
		}
	}

	bool ConfigurationManager::get_bool(std::string config_name)
	{
		return std::get<DataType::BOOL>(config_items[config_name]->value.Value());
	}

	int ConfigurationManager::get_int(std::string config_name)
	{
		return std::get<DataType::INT>(config_items[config_name]->value.Value());
	}

	float ConfigurationManager::get_float(std::string config_name)
	{
		return std::get<DataType::FLOAT>(config_items[config_name]->value.Value());
	}

	std::string ConfigurationManager::get_string(std::string config_name)
	{
		return std::get<DataType::STRING>(config_items[config_name]->value.Value());
	}

	DataType ConfigurationManager::get_type(std::string config_name)
	{
		return config_items[config_name]->type;
	}

	void ConfigurationManager::list()
	{
		spdlog::info("Configuration items:");
		for (auto& it : config_items)
		{
			switch (it.second->type)
			{
				case DataType::BOOL:
					spdlog::info("  [{}] [{}] [{}]", it.first, it.second->type._to_string(), std::get<DataType::BOOL>(it.second->value.Value()));
					break;
				case DataType::INT:
					spdlog::info("  [{}] [{}] [{}]", it.first, it.second->type._to_string(), std::get<DataType::INT>(it.second->value.Value()));
					break;
				case DataType::FLOAT:
					spdlog::info("  [{}] [{}] [{}]", it.first, it.second->type._to_string(), std::get<DataType::FLOAT>(it.second->value.Value()));
					break;
				case DataType::STRING:
					spdlog::info("  [{}] [{}] [{}]", it.first, it.second->type._to_string(), std::get<DataType::STRING>(it.second->value.Value()));
					break;
				default:
					break;
			}
		}
	}

	void ConfigurationManager::insert(std::string config_name, std::string attribute_name, EntityInstancePtrOpt config_item)
	{
		if (config_item.has_value())
		{
			EntityInstancePtr entity_instance = config_item.value();
			EntityAttributeInstancePtrOpt o_attribute_instance = entity_instance->get_attribute_instance(attribute_name);
			if (o_attribute_instance.has_value())
			{
				config_items[config_name] = o_attribute_instance.value();
				switch (config_items[config_name]->type)
				{
					case DataType::BOOL:
						spdlog::info("Added configuration: [{}] [{}] [{}]", config_name, config_items[config_name]->type._to_string(), std::get<DataType::BOOL>(config_items[config_name]->value.Value()));
						break;
					case DataType::INT:
						spdlog::info("Added configuration: [{}] [{}] [{}]", config_name, config_items[config_name]->type._to_string(), std::get<DataType::INT>(config_items[config_name]->value.Value()));
						break;
					case DataType::FLOAT:
						spdlog::info("Added configuration: [{}] [{}] [{}]", config_name, config_items[config_name]->type._to_string(), std::get<DataType::FLOAT>(config_items[config_name]->value.Value()));
						break;
					case DataType::STRING:
						spdlog::info("Added configuration: [{}] [{}] [{}]", config_name, config_items[config_name]->type._to_string(), std::get<DataType::STRING>(config_items[config_name]->value.Value()));
						break;
					default:
						break;
				}
			}
		}
	}

}
}
