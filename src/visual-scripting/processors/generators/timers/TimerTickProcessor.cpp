#include "TimerTickProcessor.hpp"

#include <type-system/types/generators/timers/TimerTick.hpp>
#include <utility>

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"

#include "react/Algorithm.h"

#include "spdlog/spdlog.h"

namespace inexor::visual_scripting {

using TimerTick = entity_system::type_system::TimerTick;
using EntityTypePtrOpt = std::optional<EntityTypePtr>;
using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

using DataValue = entity_system::DataValue;
using DataType = entity_system::DataType;

TimerTickProcessor::TimerTickProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(), entity_type_manager(std::move(entity_type_manager)), entity_instance_manager(std::move(entity_instance_manager)), log_manager(std::move(log_manager))
{
}

TimerTickProcessor::~TimerTickProcessor() = default;

void TimerTickProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    init_processor();
}

void TimerTickProcessor::init_processor()
{
    EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(TimerTick::TYPE_NAME);
    if (o_ent_type.has_value()) {
        this->entity_type = o_ent_type.value();
        entity_instance_manager->register_on_created(this->entity_type->get_GUID(), shared_from_this());
        entity_instance_manager->register_on_deleted(this->entity_type->get_GUID(), shared_from_this());
    } else {
        spdlog::error("Failed to initialize processor {}: Entity type does not exist", TimerTick::TYPE_NAME);
    }
}

void TimerTickProcessor::on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance)
{
    make_signals(entity_instance);
}

void TimerTickProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void TimerTickProcessor::make_signals(const std::shared_ptr<inexor::entity_system::EntityInstance> &entity_instance)
{
    spdlog::get(LOGGER_NAME)->debug("Initializing processor TIMER_TICK for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    EntityAttributeInstancePtrOpt o_attr_timer_tick_millis = entity_instance->get_attribute_instance(TimerTick::MILLIS);
    EntityAttributeInstancePtrOpt o_attr_timer_tick_value = entity_instance->get_attribute_instance(TimerTick::VALUE);

    if (o_attr_timer_tick_millis.has_value() && o_attr_timer_tick_value.has_value())
    {
        xg::Guid guid = entity_instance->get_GUID();
        EntityAttributeInstancePtr attr_timer_tick_millis = o_attr_timer_tick_millis.value();
        EntityAttributeInstancePtr attr_timer_tick_value = o_attr_timer_tick_value.value();

        std::thread start_thread([this, guid, attr_timer_tick_millis, attr_timer_tick_value]() {
            // Create event source
            event_sources[guid] = MakeEventSource<entity_system::D, int>();

            // Hold last signal value
            ticks[guid] = Hold(event_sources[guid], 0);

            // Create the signal
            signals[guid] = MakeSignal(ticks[guid], [attr_timer_tick_value](int tick) {
                // Toggle timer tick value
                return DataValue(!std::get<DataType::BOOL>(attr_timer_tick_value->value.Value()));
            });

            // Attach the signal to the signal_wrapper
            // o_attr_timer_tick_count.value()->value = signals[guid];
            attr_timer_tick_value->signal_wrapper <<= signals[guid];

            // Initialize the tick
            int tick = 0;

            // Loop while
            // TODO: exit loop on application shutdown or entity deletion
            while (true)
            {
                // Wait for timer_tick_millis milliseconds
                int millis = std::get<DataType::INT>(attr_timer_tick_millis->value.Value());
                std::this_thread::sleep_for(std::chrono::milliseconds(millis));

                // Tick
                tick++;
                this->event_sources[guid] << tick;
            }
        });
        start_thread.detach();

    } else
    {
        spdlog::get(LOGGER_NAME)
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    TimerTick::VALUE, TimerTick::MILLIS);
    }
}

} // namespace inexor::visual_scripting
