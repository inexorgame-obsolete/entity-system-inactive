// Inexor entity system
// (c)2018 Inexor

#include "LogManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace logging {


	LogManager::LogManager(
		shared_ptr<LoggerEntityTypeProvider> logger_entity_type_provider,
		shared_ptr<LoggerFactory> logger_factory,
		shared_ptr<EntityInstanceManager> entity_instance_manager
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

		O_ENT_INST o_logger_instance = logger_factory->create_instance(logger_name, spdlog::level::level_enum::info);
		if (o_logger_instance.has_value())
		{
			ENT_INST logger_instance = o_logger_instance.value();
			O_ENT_ATTR_INST o_logger_name = logger_instance->get_attribute_instance("logger_name");
			O_ENT_ATTR_INST o_log_level = logger_instance->get_attribute_instance("log_level");
			if (o_logger_name.has_value() && o_log_level.has_value()) {
				spdlog::get("inexor.logging.LogManager")->info("logger_name = {}, log_level = {}", std::get<ENTSYS_DATA_TYPE_STRING>(o_logger_name.value()->value), std::get<ENTSYS_DATA_TYPE_INT>(o_log_level.value()->value));
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
			O_ENT_ATTR_INST o_ent_attr_inst = logger_instances[logger_name]->get_attribute_instance("level");
			if (o_ent_attr_inst.has_value()) {
				o_ent_attr_inst.value()->value = level;
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
