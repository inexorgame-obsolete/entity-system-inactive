#include <type-system/factories/inout/logger/LoggerFactory.hpp>

#include <utility>

#include <type-system/types/inout/logger/Logger.hpp>

namespace inexor::entity_system::type_system {

LoggerFactory::LoggerFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

LoggerFactory::~LoggerFactory() = default;

std::string LoggerFactory::get_component_name()
{
    return "LoggerFactory";
}

EntityInstancePtrOpt LoggerFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(Logger::TYPE_NAME)
        ->attribute(Logger::NAME, "")
        ->attribute(Logger::LEVEL, spdlog::level::level_enum::info)
        ->attribute(Logger::MESSAGE, std::string(""))
        ->build();
}

EntityInstancePtrOpt LoggerFactory::create_instance(const std::string &logger_name)
{
    return entity_instance_builder_factory->get_builder(Logger::TYPE_NAME)
        ->attribute(Logger::NAME, logger_name)
        ->attribute(Logger::LEVEL, spdlog::level::level_enum::info)
        ->attribute(Logger::MESSAGE, std::string(""))
        ->build();
}

EntityInstancePtrOpt LoggerFactory::create_instance(const std::string &logger_name, spdlog::level::level_enum log_level)
{
    return entity_instance_builder_factory->get_builder(Logger::TYPE_NAME)
        ->attribute(Logger::NAME, logger_name)
        ->attribute(Logger::LEVEL, log_level)
        ->attribute(Logger::MESSAGE, std::string(""))
        ->build();
}

std::vector<EntityInstancePtr> LoggerFactory::create_instances(int count)
{
    std::vector<EntityInstancePtr> instances;
    for (int i = 0; i < count; i++)
    {
        EntityInstancePtrOpt o_ent_inst = create_instance();
        if (o_ent_inst.has_value())
        {
            instances.push_back(o_ent_inst.value());
        }
    }
    return instances;
}

} // namespace inexor::entity_system::type_system
