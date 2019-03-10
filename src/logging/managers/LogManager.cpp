#include "LogManager.hpp"

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"

namespace inexor {
namespace logging {

	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

	LogManager::LogManager(
		LoggerEntityTypeProviderPtr logger_entity_type_provider,
		LoggerFactoryPtr logger_factory,
		EntityInstanceManagerPtr entity_instance_manager
	)
	{
		this->logger_entity_type_provider = logger_entity_type_provider;
		this->logger_factory = logger_factory;
		this->entity_instance_manager = entity_instance_manager;
	}

	LogManager::~LogManager()
	{
	}

	void LogManager::init()
	{
		spdlog::init_thread_pool(8192, 4);
		sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>("inexor.log", 1024 * 1024 * 10, 3));
		spdlog::register_logger(std::make_shared<spdlog::async_logger>("inexor.logging.LogManager", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block));
		spdlog::get("inexor.logging.LogManager")->info("Asynchronous logging initialized");
	}

	void LogManager::register_logger(std::string logger_name) {
		spdlog::register_logger(std::make_shared<spdlog::async_logger>(logger_name, sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block));
		spdlog::get("inexor.logging.LogManager")->info("Registered logger {}", logger_name);

		EntityInstancePtrOpt o_logger_instance = logger_factory->create_instance(logger_name, spdlog::level::level_enum::info);
		if (o_logger_instance.has_value())
		{
			EntityInstancePtr logger_instance = o_logger_instance.value();
			EntityAttributeInstancePtrOpt o_logger_name = logger_instance->get_attribute_instance(entity_system::type_system::LoggerEntityTypeProvider::LOGGER_NAME);
			EntityAttributeInstancePtrOpt o_log_level = logger_instance->get_attribute_instance(entity_system::type_system::LoggerEntityTypeProvider::LOG_LEVEL);
			if (o_logger_name.has_value() && o_log_level.has_value()) {
				spdlog::get("inexor.logging.LogManager")->info("logger_name = {}, log_level = {}", std::get<DataType::STRING>(o_logger_name.value()->value.Value()), std::get<DataType::INT>(o_log_level.value()->value.Value()));
			}
			logger_instances[logger_name] = logger_instance;
		} else {
			spdlog::get("inexor.logging.LogManager")->info("Failed to create entity instance of type {}", logger_entity_type_provider->get_type()->get_type_name());
		}
	}

	void LogManager::set_level(std::string logger_name, spdlog::level::level_enum level)
	{
		if (logger_instances.count(logger_name)) {
			spdlog::get(logger_name)->set_level(level);
			EntityAttributeInstancePtrOpt o_ent_attr_inst = logger_instances[logger_name]->get_attribute_instance(entity_system::type_system::LoggerEntityTypeProvider::LOG_LEVEL);
			if (o_ent_attr_inst.has_value()) {
				o_ent_attr_inst.value()->own_value.Set(level);
			}
		}
	}

	spdlog::level::level_enum LogManager::get_level(std::string logger_name)
	{
		if (logger_instances.count(logger_name)) {
			return spdlog::get(logger_name)->level();
		} else {
			return spdlog::level::level_enum::off;
		}
	}

	void LogManager::unregister_logger(std::string logger_name) {
		spdlog::drop(logger_name);
	}

}
}
