#include "LoggerFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	LoggerFactory::LoggerFactory(
		LoggerEntityTypeProviderPtr logger_entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->logger_entity_type_provider = logger_entity_type_provider;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	LoggerFactory::~LoggerFactory()
	{
	}

	void LoggerFactory::init()
	{
	}

	EntityInstancePtrOpt LoggerFactory::create_instance()
	{
		return entity_instance_builder_factory->get_builder()
			->type(logger_entity_type_provider->get_type())
			->attribute(LoggerEntityTypeProvider::LOGGER_NAME, "")
			->attribute(LoggerEntityTypeProvider::LOG_LEVEL, spdlog::level::level_enum::info)
			->attribute(LoggerEntityTypeProvider::LOG_MESSAGE, std::string(""))
			->build();
	}

	EntityInstancePtrOpt LoggerFactory::create_instance(std::string logger_name)
	{
		return entity_instance_builder_factory->get_builder()
			->type(logger_entity_type_provider->get_type())
			->attribute(LoggerEntityTypeProvider::LOGGER_NAME, logger_name)
			->attribute(LoggerEntityTypeProvider::LOG_LEVEL, spdlog::level::level_enum::info)
			->attribute(LoggerEntityTypeProvider::LOG_MESSAGE, std::string(""))
			->build();
	}

	EntityInstancePtrOpt LoggerFactory::create_instance(std::string logger_name, spdlog::level::level_enum log_level)
	{
		return entity_instance_builder_factory->get_builder()
			->type(logger_entity_type_provider->get_type())
			->attribute(LoggerEntityTypeProvider::LOGGER_NAME, logger_name)
			->attribute(LoggerEntityTypeProvider::LOG_LEVEL, log_level)
			->attribute(LoggerEntityTypeProvider::LOG_MESSAGE, std::string(""))
			->build();
	}

	std::vector<EntityInstancePtr> LoggerFactory::create_instances(int count)
	{
		std::vector<EntityInstancePtr> instances;
		for (int i = 0; i < count; i++)
		{
			EntityInstancePtrOpt o_ent_inst = create_instance();
			if (o_ent_inst.has_value()) {
				instances.push_back(o_ent_inst.value());
			}
		}
		return instances;
	}

}
}
}
