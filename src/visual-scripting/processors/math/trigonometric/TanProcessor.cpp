#include "TanProcessor.hpp"

#include <utility>

#include "spdlog/spdlog.h"

namespace inexor::visual_scripting {

using TanEntityTypeProvider = entity_system::type_system::TanEntityTypeProvider;
using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

TanProcessor::TanProcessor(const TanEntityTypeProviderPtr &entity_type_provider, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(entity_type_provider->get_type()), entity_type_provider(entity_type_provider), entity_instance_manager(std::move(entity_instance_manager)), log_manager(std::move(log_manager))
{
}

TanProcessor::~TanProcessor() = default;

void TanProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
    entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
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

    EntityAttributeInstancePtrOpt o_attr_tan_input = entity_instance->get_attribute_instance(TanEntityTypeProvider::TAN_INPUT);
    EntityAttributeInstancePtrOpt o_attr_tan_value = entity_instance->get_attribute_instance(TanEntityTypeProvider::TAN_VALUE);

    if (o_attr_tan_input.has_value() && o_attr_tan_value.has_value())
    {
        signals[entity_instance->get_GUID()] = MakeSignal(o_attr_tan_input.value()->value, [](DataValue tan_input) { return entity_system::DataValue(tanf(std::get<DataType::FLOAT>(tan_input))); });
        o_attr_tan_value.value()->signal_wrapper <<= signals[entity_instance->get_GUID()];
        // o_attr_tan_value.value()->value = signals[entity_instance->get_GUID()];
    } else
    {
        spdlog::get(LOGGER_NAME)
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    TanEntityTypeProvider::TAN_INPUT, TanEntityTypeProvider::TAN_VALUE);
    }
}

} // namespace inexor::visual_scripting
