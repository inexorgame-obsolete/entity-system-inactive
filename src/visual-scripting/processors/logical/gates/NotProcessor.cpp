#include "NotProcessor.hpp"

#include <utility>

namespace inexor::visual_scripting {

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;
using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

NotProcessor::NotProcessor(const NotEntityTypeProviderPtr &entity_type_provider, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(entity_type_provider->get_type()), entity_type_provider(entity_type_provider), entity_instance_manager(std::move(entity_instance_manager)), log_manager(std::move(log_manager))
{
}

NotProcessor::~NotProcessor() = default;

void NotProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
    entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
}

void NotProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
{
    make_signals(entity_instance);
}

void NotProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void NotProcessor::make_signals(const EntityInstancePtr &entity_instance)
{
    spdlog::get(LOGGER_NAME)->debug("Initializing processor NOT for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    auto o_not_input = entity_instance->get_attribute_instance(NotEntityTypeProvider::NOT_INPUT);
    auto o_not_result = entity_instance->get_attribute_instance(NotEntityTypeProvider::NOT_RESULT);

    if (o_not_input.has_value() && o_not_result.has_value())
    {
        signals[entity_instance->get_GUID()] = MakeSignal(With(o_not_input.value()->value), [](DataValue not_input) { return DataValue(!std::get<DataType::BOOL>(not_input)); });
        o_not_result.value()->value = signals[entity_instance->get_GUID()];
    } else
    {
        spdlog::get(LOGGER_NAME)
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    NotEntityTypeProvider::NOT_INPUT, NotEntityTypeProvider::NOT_RESULT);
    }
}

} // namespace inexor::visual_scripting
