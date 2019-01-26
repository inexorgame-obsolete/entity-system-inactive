// Inexor entity system
// (c)2018 Inexor

#include "LogManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace logging {


	LogManager::LogManager(
		shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager,
		shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager,
		shared_ptr<EntityInstanceManager> entity_instance_manager
	)
	{
		this->entity_type_builder_manager = entity_type_builder_manager;
		this->entity_instance_builder_manager = entity_instance_builder_manager;
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
		O_ENT_TYPE o_entity_type_logger = entity_type_builder_manager->get_builder()
		  ->name("LOGGER")
		  ->attribute("logger_name", ENTSYS_DATA_TYPE_STRING)
		  ->build();
		if (o_entity_type_logger.has_value())
		{
			entity_type_logger = o_entity_type_logger.value();
			spdlog::get("inexor.logging.LogManager")->info("Created entity type {} (UUID: {})", entity_type_logger->get_type_name(), entity_type_logger->get_GUID().str());
		}
	}

	void LogManager::register_logger(std::string logger_name) {
		spdlog::register_logger(std::make_shared<spdlog::async_logger>(logger_name, sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block));
		spdlog::get("inexor.logging.LogManager")->info("Registered logger {}", logger_name);

		DataContainer attribute_logger_name = {ENTSYS_DATA_TYPE_STRING, logger_name};
		O_ENT_INST o_logger_instance = entity_instance_builder_manager->get_builder()
			->type(entity_type_logger)
			->attribute("logger_name", attribute_logger_name)
			->build();

		if (o_logger_instance.has_value())
		{
			ENT_INST logger_instance = o_logger_instance.value();
			spdlog::get("inexor.logging.LogManager")->info("Created entity instance (UUID: {}) of type {} (UUID: {})", logger_instance->get_GUID().str(), entity_type_logger->get_type_name(), entity_type_logger->get_GUID().str());
			O_ENT_ATTR_INST o_ent_attr_inst = logger_instance->get_attribute_instance("logger_name");
			if (o_ent_attr_inst.has_value()) {
				ENT_ATTR_INST ent_attr_inst = o_ent_attr_inst.value();
				string value = std::get<ENTSYS_DATA_TYPE_STRING>(ent_attr_inst->value);
				spdlog::get("inexor.logging.LogManager")->info("logger_name = {}", value);
			}
		} else {
			spdlog::get("inexor.logging.LogManager")->info("Failed to create entity instance of type {}", entity_type_logger->get_type_name());
		}
	}

	void LogManager::unregister_logger(std::string logger_name) {
		spdlog::drop(logger_name);
	}

}
}
