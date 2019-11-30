#include "StdErrProcessor.hpp"

#include <type-system/types/inout/console/StdErr.hpp>
#include <utility>

#include "react/Algorithm.h"
#include "react/Event.h"
#include "react/Observer.h"

namespace inexor::visual_scripting {

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;

using StdErr = entity_system::type_system::StdErr;
using EntityTypePtrOpt = std::optional<EntityTypePtr>;
using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

StdErrProcessor::StdErrProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, const LogManagerPtr &log_manager)
    : Processor(), LifeCycleComponent(), entity_type_manager(std::move(entity_type_manager)), entity_instance_manager(std::move(entity_instance_manager))
{
}

StdErrProcessor::~StdErrProcessor() = default;

void StdErrProcessor::init()
{
    init_processor();
}

void StdErrProcessor::init_processor()
{
    EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(StdErr::TYPE_NAME);
    if (o_ent_type.has_value()) {
        this->entity_type = o_ent_type.value();
        entity_instance_manager->register_on_created(this->entity_type->get_GUID(), shared_from_this());
        entity_instance_manager->register_on_deleted(this->entity_type->get_GUID(), shared_from_this());
    } else {
        spdlog::error("Failed to initialize processor {}: Entity type does not exist", StdErr::TYPE_NAME);
    }
}

std::string StdErrProcessor::get_component_name()
{
    return "StdErrProcessor";
}

void StdErrProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
{
    make_signals(entity_instance);
}

void StdErrProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void StdErrProcessor::make_signals(const EntityInstancePtr &entity_instance)
{
    spdlog::info("Initializing processor CONSOLE_STDERR for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());
    auto o_console_stderr = entity_instance->get_attribute_instance(StdErr::STDERR);

    if (o_console_stderr.has_value())
    {
        observers[entity_instance->get_GUID()] = Observe(o_console_stderr.value()->value, [](DataValue console_stderr) { std::cout << std::get<DataType::STRING>(console_stderr) << std::endl; });
    } else
    {
        spdlog::info("Failed to initialize processor signals for entity instance {} of type {}: Missing attribute {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                     StdErr::STDERR);
    }
}

} // namespace inexor::visual_scripting
