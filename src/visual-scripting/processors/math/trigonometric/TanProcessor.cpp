#include "TanProcessor.hpp"

#include <utility>

#include "spdlog/spdlog.h"

namespace inexor::visual_scripting {

using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;
using EntityTypePtrOpt = std::optional<EntityTypePtr>;

TanProcessor::TanProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(), entity_type_manager(std::move(entity_type_manager)), entity_instance_manager(std::move(entity_instance_manager)), log_manager(std::move(log_manager))
{
}

TanProcessor::~TanProcessor() = default;

void TanProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    init_processor();
}

void TanProcessor::init_processor()
{
    EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(TYPE_NAME);
    if (o_ent_type.has_value()) {
        this->entity_type = o_ent_type.value();
        entity_instance_manager->register_on_created(this->entity_type->get_GUID(), shared_from_this());
        entity_instance_manager->register_on_deleted(this->entity_type->get_GUID(), shared_from_this());
    } else {
        spdlog::get(LOGGER_NAME)->error("Failed to initialize processor {}: Entity type does not exist", TYPE_NAME);
    }
}

void TanProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
{
    make_signals(entity_instance);
}

void TanProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void TanProcessor::make_signals(const EntityInstancePtr &entity_instance)
{
    spdlog::get(LOGGER_NAME)->debug("Initializing processor TAN for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    EntityAttributeInstancePtrOpt o_attr_tan_input = entity_instance->get_attribute_instance(TAN_INPUT);
    EntityAttributeInstancePtrOpt o_attr_tan_value = entity_instance->get_attribute_instance(TAN_VALUE);

    if (o_attr_tan_input.has_value() && o_attr_tan_value.has_value())
    {
        signals[entity_instance->get_GUID()] = MakeSignal(o_attr_tan_input.value()->value, [](DataValue tan_input) { return entity_system::DataValue(tanf(std::get<DataType::FLOAT>(tan_input))); });
        o_attr_tan_value.value()->signal_wrapper <<= signals[entity_instance->get_GUID()];
    } else
    {
        spdlog::get(LOGGER_NAME)
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    TAN_INPUT, TAN_VALUE);
    }
}

} // namespace inexor::visual_scripting
