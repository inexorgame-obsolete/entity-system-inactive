#include "LoggerProcessor.hpp"

#include <type-system/types/inout/logger/Logger.hpp>
#include <utility>

#include "react/Algorithm.h"
#include "react/Event.h"
#include "react/Observer.h"

namespace inexor::visual_scripting {

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;

using Logger = entity_system::type_system::Logger;
using EntityTypePtrOpt = std::optional<EntityTypePtr>;
using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

using EntityTypePtr = std::shared_ptr<entity_system::EntityType>;

LoggerProcessor::LoggerProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, const LogManagerPtr &logger_manager)
    : Processor(), LifeCycleComponent(), entity_type_manager(std::move(entity_type_manager)), entity_instance_manager(std::move(entity_instance_manager)), log_manager(log_manager)
{
    this->logger = spdlog::default_logger();
}

LoggerProcessor::~LoggerProcessor() = default;

void LoggerProcessor::init()
{
//    log_manager->register_logger(LOGGER_NAME);
    init_processor();
}

void LoggerProcessor::init_processor()
{
    EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(Logger::TYPE_NAME);
    if (o_ent_type.has_value()) {
        this->entity_type = o_ent_type.value();
        entity_instance_manager->register_on_created(this->entity_type->get_GUID(), shared_from_this());
        entity_instance_manager->register_on_deleted(this->entity_type->get_GUID(), shared_from_this());
    } else {
        spdlog::get(LOGGER_NAME)->error("Failed to initialize processor {}: Entity type does not exist", Logger::TYPE_NAME);
    }
}

std::string LoggerProcessor::get_component_name()
{
    return "LoggerProcessor";
}

void LoggerProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
{
    make_signals(entity_instance);
}

void LoggerProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void LoggerProcessor::make_signals(const EntityInstancePtr &entity_instance)
{
    logger->debug("Initializing processor LOGGER for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    auto o_logger_name = entity_instance->get_attribute_instance(Logger::NAME);
    auto o_log_message = entity_instance->get_attribute_instance(Logger::MESSAGE);

    if (o_logger_name.has_value() && o_log_message.has_value())
    {
        const std::string &logger_name = std::get<DataType::STRING>(o_logger_name.value()->value.Value());
        observers[entity_instance->get_GUID()] = Observe(o_log_message.value()->value, [logger_name](DataValue log_message) { spdlog::get(logger_name)->info(std::get<DataType::STRING>(log_message)); });
    } else
    {
        logger->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                      Logger::NAME, Logger::MESSAGE);
    }
}

} // namespace inexor::visual_scripting
