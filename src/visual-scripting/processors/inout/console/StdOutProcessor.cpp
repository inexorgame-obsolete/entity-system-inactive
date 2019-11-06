#include "StdOutProcessor.hpp"

#include <type-system/types/inout/console/StdOut.hpp>
#include <utility>

#include "react/Algorithm.h"
#include "react/Event.h"
#include "react/Observer.h"

namespace inexor::visual_scripting {

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;

using StdOut = entity_system::type_system::StdOut;
using EntityTypePtrOpt = std::optional<EntityTypePtr>;
using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

StdOutProcessor::StdOutProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(), entity_type_manager(std::move(entity_type_manager)), entity_instance_manager(std::move(entity_instance_manager)), log_manager(log_manager)
{
}

StdOutProcessor::~StdOutProcessor() = default;

void StdOutProcessor::init()
{
    init_processor();
}

void StdOutProcessor::init_processor()
{
    EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(StdOut::TYPE_NAME);
    if (o_ent_type.has_value()) {
        this->entity_type = o_ent_type.value();
        entity_instance_manager->register_on_created(this->entity_type->get_GUID(), shared_from_this());
        entity_instance_manager->register_on_deleted(this->entity_type->get_GUID(), shared_from_this());
    } else {
        spdlog::error("Failed to initialize processor {}: Entity type does not exist", StdOut::TYPE_NAME);
    }
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

    auto o_console_stdout = entity_instance->get_attribute_instance(StdOut::STDOUT);

    if (o_console_stdout.has_value())
    {
        observers[entity_instance->get_GUID()] = Observe(o_console_stdout.value()->value, [](DataValue console_stdout) { std::cout << std::get<DataType::STRING>(console_stdout) << std::endl; });
    } else
    {
        spdlog::error("Failed to initialize processor signals for entity instance {} of type {}: Missing attribute {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                      StdOut::STDOUT);
    }
}

} // namespace inexor::visual_scripting
