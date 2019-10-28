#include "CounterFloatProcessor.hpp"

#include <utility>

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"

#include "react/Algorithm.h"

#include "spdlog/spdlog.h"

namespace inexor::visual_scripting {

using CounterFloatEntityTypeProvider = entity_system::type_system::CounterFloatEntityTypeProvider;
using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

using DataValue = entity_system::DataValue;
using DataType = entity_system::DataType;

CounterFloatProcessor::CounterFloatProcessor(const CounterFloatEntityTypeProviderPtr &entity_type_provider, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(entity_type_provider->get_type()), entity_type_provider(entity_type_provider), entity_instance_manager(std::move(entity_instance_manager)), log_manager(std::move(log_manager))
{
}

CounterFloatProcessor::~CounterFloatProcessor() = default;

void CounterFloatProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
    entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
}

void CounterFloatProcessor::shutdown()
{
    for (auto kv : running)
    {
        kv.second = false;
    }
}

void CounterFloatProcessor::on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance)
{
    make_signals(entity_instance);
}

void CounterFloatProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void CounterFloatProcessor::make_signals(const std::shared_ptr<inexor::entity_system::EntityInstance> &entity_instance)
{
    spdlog::get(LOGGER_NAME)->debug("Initializing processor COUNTER_FLOAT for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    EntityAttributeInstancePtrOpt o_attr_counter_float_millis = entity_instance->get_attribute_instance(CounterFloatEntityTypeProvider::COUNTER_FLOAT_MILLIS);
    EntityAttributeInstancePtrOpt o_attr_counter_float_step = entity_instance->get_attribute_instance(CounterFloatEntityTypeProvider::COUNTER_FLOAT_STEP);
    EntityAttributeInstancePtrOpt o_attr_counter_float_reset = entity_instance->get_attribute_instance(CounterFloatEntityTypeProvider::COUNTER_FLOAT_RESET);
    EntityAttributeInstancePtrOpt o_attr_counter_float_count = entity_instance->get_attribute_instance(CounterFloatEntityTypeProvider::COUNTER_FLOAT_COUNT);

    if (o_attr_counter_float_millis.has_value() && o_attr_counter_float_step.has_value() && o_attr_counter_float_reset.has_value() && o_attr_counter_float_count.has_value())
    {
        xg::Guid guid = entity_instance->get_GUID();
        EntityAttributeInstancePtr attr_counter_float_millis = o_attr_counter_float_millis.value();
        EntityAttributeInstancePtr attr_counter_float_step = o_attr_counter_float_step.value();
        EntityAttributeInstancePtr attr_counter_float_reset = o_attr_counter_float_reset.value();
        EntityAttributeInstancePtr attr_counter_float_count = o_attr_counter_float_count.value();

        std::thread start_thread([this, guid, attr_counter_float_millis, attr_counter_float_step, attr_counter_float_reset, attr_counter_float_count]() {
            running[guid] = true;

            // Create event source
            event_sources[guid] = MakeEventSource<entity_system::D, int>();

            // Hold last signal value
            ticks[guid] = Hold(event_sources[guid], 0);

            // Create the signal
            signals[guid] = MakeSignal(With(ticks[guid]), [attr_counter_float_count, attr_counter_float_step, attr_counter_float_reset](int tick) {
                bool reset = std::get<DataType::BOOL>(attr_counter_float_reset->value.Value());
                if (!reset)
                {
                    // Increase counter_float_count by counter_float_step
                    return DataValue(std::get<DataType::FLOAT>(attr_counter_float_count->value.Value()) + std::get<DataType::FLOAT>(attr_counter_float_step->value.Value()));
                } else
                {
                    return DataValue(0);
                }
            });

            // Attach the signal to the signal_wrapper
            // o_attr_counter_float_count.value()->value = signals[guid];
            attr_counter_float_count->signal_wrapper <<= signals[guid];

            // Initialize the tick
            int tick = 0;

            while (running[guid])
            {
                // Tick
                tick++;
                this->event_sources[guid] << tick;

                // Wait for counter_float_millis milliseconds
                int millis = std::get<DataType::INT>(attr_counter_float_millis->value.Value());
                std::this_thread::sleep_for(std::chrono::milliseconds(millis));
            }
        });
        start_thread.detach();

    } else
    {
        spdlog::get(LOGGER_NAME)
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes {} {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    CounterFloatEntityTypeProvider::COUNTER_FLOAT_COUNT, CounterFloatEntityTypeProvider::COUNTER_FLOAT_MILLIS, CounterFloatEntityTypeProvider::COUNTER_FLOAT_RESET, CounterFloatEntityTypeProvider::COUNTER_FLOAT_STEP);
    }
}

} // namespace inexor::visual_scripting
