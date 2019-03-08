// Inexor entity system
// (c)2018 Inexor

#include "LoggerFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace logging {


	LoggerFactory::LoggerFactory(
		shared_ptr<LoggerEntityTypeProvider> logger_entity_type_provider,
		shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager,
		shared_ptr<EntityInstanceManager> entity_instance_manager
	)
	{
		this->logger_entity_type_provider = logger_entity_type_provider;
		this->entity_instance_builder_manager = entity_instance_builder_manager;
		this->entity_instance_manager = entity_instance_manager;
	}

	LoggerFactory::~LoggerFactory()
	{
	}

	O_ENT_INST LoggerFactory::create_instance()
	{
		return entity_instance_builder_manager->get_builder()
			->type(logger_entity_type_provider->get_type())
			->attribute("logger_name", "")
			->attribute("log_level", spdlog::level::level_enum::info)
			->build();
	}

	O_ENT_INST LoggerFactory::create_instance(string logger_name)
	{
		return entity_instance_builder_manager->get_builder()
			->type(logger_entity_type_provider->get_type())
			->attribute("logger_name", logger_name)
			->attribute("log_level", spdlog::level::level_enum::info)
			->build();
	}

	O_ENT_INST LoggerFactory::create_instance(string logger_name, spdlog::level::level_enum log_level)
	{
		return entity_instance_builder_manager->get_builder()
			->type(logger_entity_type_provider->get_type())
			->attribute("logger_name", logger_name)
			->attribute("log_level", log_level)
			->build();
	}

	vector<ENT_INST> LoggerFactory::create_instances(int count)
	{
		vector<ENT_INST> instances;
		for (int i = 0; i < count; i++)
		{
			O_ENT_INST o_ent_inst = create_instance();
			if (o_ent_inst.has_value()) {
				instances.push_back(o_ent_inst.value());
			}
		}
		return instances;
	}

}
}
