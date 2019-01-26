// Inexor entity system
// (c)2018 Inexor

#include "LogManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace logging {


	LogManager::LogManager(
		shared_ptr<EntityTypeManager> entity_type_manager,
		shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager,
		shared_ptr<EntityInstanceManager> entity_instance_manager,
		shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager
	)
	{
		this->entity_type_manager = entity_type_manager;
		this->entity_attribute_type_manager = entity_attribute_type_manager;
		this->entity_instance_manager = entity_instance_manager;
		this->entity_attribute_instance_manager = entity_attribute_instance_manager;
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
		O_ENT_TYPE o_logger = entity_type_manager->create_entity_type("LOGGER");
		if (o_logger.has_value())
		{
			entity_type_logger = o_logger.value();
			O_ENT_ATTR_TYPE o_logger_name = entity_attribute_type_manager->create_entity_attribute_type("logger_name", ENTSYS_DATA_TYPE_STRING);
			if (o_logger_name.has_value()) {
				attr_logger_name = o_logger_name.value();
				entity_type_logger->link_attribute_type(attr_logger_name);
			}
		}

	}

	void LogManager::register_logger(std::string logger_name) {
		spdlog::register_logger(std::make_shared<spdlog::async_logger>(logger_name, sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block));
		spdlog::get("inexor.logging.LogManager")->info("Registered logger {}", logger_name);
		O_ENT_INST o_logger_instance = entity_instance_manager->create_entity_instance(entity_type_logger);
		if (o_logger_instance.has_value())
		{
			std::shared_ptr<inexor::entity_system::EntityInstance> logger_instance = o_logger_instance.value();
			O_ENT_ATTR_INST o_logger_instance_logger_name = entity_attribute_instance_manager->create_entity_attribute_instance(attr_logger_name);
			if (o_logger_instance_logger_name.has_value())
			{

			}
			spdlog::get("inexor.logging.LogManager")->info("Registered logger {}", logger_name);
		}
	}

	void LogManager::unregister_logger(std::string logger_name) {
		spdlog::drop(logger_name);
	}

}
}
