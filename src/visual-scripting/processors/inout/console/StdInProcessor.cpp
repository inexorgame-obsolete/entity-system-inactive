#include "StdInProcessor.hpp"

#include <type-system/types/inout/console/StdIn.hpp>
#include <utility>

#include "react/Algorithm.h"
#include "react/Event.h"
#include "react/Observer.h"

namespace inexor::visual_scripting {

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;

using StdIn = entity_system::type_system::StdIn;
using EntityTypePtrOpt = std::optional<EntityTypePtr>;
using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

StdInProcessor::StdInProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager) : Processor(), entity_type_manager(std::move(entity_type_manager)), entity_instance_manager(std::move(entity_instance_manager)), log_manager(log_manager)
{
}

StdInProcessor::~StdInProcessor() = default;

void StdInProcessor::init()
{
    init_processor();
}

void StdInProcessor::init_processor()
{
    EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(StdIn::TYPE_NAME);
    if (o_ent_type.has_value()) {
        this->entity_type = o_ent_type.value();
        entity_instance_manager->register_on_created(this->entity_type->get_GUID(), shared_from_this());
        entity_instance_manager->register_on_deleted(this->entity_type->get_GUID(), shared_from_this());
    } else {
        spdlog::error("Failed to initialize processor {}: Entity type does not exist", StdIn::TYPE_NAME);
    }
}

void StdInProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
{
    make_signals(entity_instance);
}

void StdInProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void StdInProcessor::make_signals(const EntityInstancePtr &entity_instance)
{
    spdlog::info("Initializing processor CONSOLE_STDIN for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    auto o_console_stdin = entity_instance->get_attribute_instance(StdIn::STDIN);

    if (o_console_stdin.has_value())
    {
        xg::Guid guid = entity_instance->get_GUID();
        std::shared_ptr<inexor::entity_system::EntityAttributeInstance> attr_console_stdin = o_console_stdin.value();

        std::thread start_thread([this, guid, attr_console_stdin]() {
            // Create event source
            event_sources[guid] = MakeEventSource<entity_system::D, std::string>();

            // Hold last signal value
            last_event_signals[guid] = Hold(event_sources[guid], "");

            // Create the signal
            signals[guid] = MakeSignal(last_event_signals[guid], [](std::string stdin_line) { return entity_system::DataValue(stdin_line); });

            // Attach the signal to the signal_wrapper
            attr_console_stdin->signal_wrapper <<= signals[guid];

            // Loop endless
            // TODO: exit std::getline + loop on application shutdown
            while (true)
            {
                for (std::string line; std::getline(std::cin, line);)
                {
                    this->event_sources[guid] << line;
                }
            }
        });
        start_thread.detach();
    } else
    {
        spdlog::error("Failed to initialize processor signals for entity instance {} of type {}: Missing attribute {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                      StdIn::STDIN);
    }
}

} // namespace inexor::visual_scripting
