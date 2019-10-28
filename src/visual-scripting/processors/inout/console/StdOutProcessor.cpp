#include "StdOutProcessor.hpp"

#include <utility>

#include "react/Algorithm.h"
#include "react/Domain.h"
#include "react/Event.h"
#include "react/Observer.h"

namespace inexor::visual_scripting {

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;
using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

using EntityTypePtr = std::shared_ptr<entity_system::EntityType>;

StdOutProcessor::StdOutProcessor(const StdOutEntityTypeProviderPtr &entity_type_provider, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager) : Processor(entity_type_provider->get_type())
{
    this->entity_type_provider = entity_type_provider;
    this->entity_instance_manager = std::move(entity_instance_manager);
    this->log_manager = std::move(log_manager);
}

StdOutProcessor::~StdOutProcessor() = default;

void StdOutProcessor::init()
{
    entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
    entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
}

void StdOutProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
{
    make_signals(entity_instance);
}

void StdOutProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void StdOutProcessor::make_signals(const EntityInstancePtr &entity_instance)
{
    spdlog::info("Initializing processor CONSOLE_STDOUT for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    auto o_console_stdout = entity_instance->get_attribute_instance(StdOutEntityTypeProvider::CONSOLE_STDOUT);

    if (o_console_stdout.has_value())
    {
        observers[entity_instance->get_GUID()] = Observe(o_console_stdout.value()->value, [](DataValue console_stdout) { std::cout << std::get<DataType::STRING>(console_stdout) << std::endl; });
    } else
    {
        spdlog::error("Failed to initialize processor signals for entity instance {} of type {}: Missing attribute {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                      StdOutEntityTypeProvider::CONSOLE_STDOUT);
    }
}

} // namespace inexor::visual_scripting
