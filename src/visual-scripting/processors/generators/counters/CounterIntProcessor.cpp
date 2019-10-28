#include "CounterIntProcessor.hpp"

#include <utility>

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"

#include "react/Algorithm.h"
#include "react/Domain.h"
#include "react/Observer.h"

#include "spdlog/spdlog.h"

namespace inexor::visual_scripting {

using CounterIntEntityTypeProvider = entity_system::type_system::CounterIntEntityTypeProvider;
using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

using DataValue = entity_system::DataValue;
using DataType = entity_system::DataType;

CounterIntProcessor::CounterIntProcessor(const CounterIntEntityTypeProviderPtr &entity_type_provider, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(entity_type_provider->get_type()), entity_type_provider(entity_type_provider), entity_instance_manager(std::move(entity_instance_manager)), log_manager(std::move(log_manager))
{
}

CounterIntProcessor::~CounterIntProcessor() = default;

void CounterIntProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
    entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
}

void CounterIntProcessor::shutdown()
{
    //		for (auto kv : running)
    //		{
    //			kv.second = false;
    //		}
}

void CounterIntProcessor::on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance)
{
    make_signals(entity_instance);
}

void CounterIntProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void CounterIntProcessor::make_signals(const std::shared_ptr<inexor::entity_system::EntityInstance> &entity_instance)
{
    spdlog::get(LOGGER_NAME)->debug("Initializing processor COUNTER_INT for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    EntityAttributeInstancePtrOpt o_attr_counter_int_millis = entity_instance->get_attribute_instance(CounterIntEntityTypeProvider::COUNTER_INT_MILLIS);
    EntityAttributeInstancePtrOpt o_attr_counter_int_step = entity_instance->get_attribute_instance(CounterIntEntityTypeProvider::COUNTER_INT_STEP);
    EntityAttributeInstancePtrOpt o_attr_counter_int_reset = entity_instance->get_attribute_instance(CounterIntEntityTypeProvider::COUNTER_INT_RESET);
    EntityAttributeInstancePtrOpt o_attr_counter_int_count = entity_instance->get_attribute_instance(CounterIntEntityTypeProvider::COUNTER_INT_COUNT);

    if (o_attr_counter_int_millis.has_value() && o_attr_counter_int_step.has_value() && o_attr_counter_int_reset.has_value() && o_attr_counter_int_count.has_value())
    {
        xg::Guid guid = entity_instance->get_GUID();
        EntityAttributeInstancePtr attr_counter_int_millis = o_attr_counter_int_millis.value();
        EntityAttributeInstancePtr attr_counter_int_step = o_attr_counter_int_step.value();
        EntityAttributeInstancePtr attr_counter_int_reset = o_attr_counter_int_reset.value();
        EntityAttributeInstancePtr attr_counter_int_count = o_attr_counter_int_count.value();

        std::thread start_thread([this, guid, attr_counter_int_millis, attr_counter_int_step, attr_counter_int_reset, attr_counter_int_count]() {
            // Create event source
            event_sources[guid] = MakeEventSource<entity_system::D, int>();

            // Hold last signal value
            ticks[guid] = Hold(event_sources[guid], 0);

            // Create the signal
            signals[guid] = MakeSignal(With(ticks[guid]), [attr_counter_int_count, attr_counter_int_step, attr_counter_int_reset](int tick) {
                bool reset = std::get<DataType::BOOL>(attr_counter_int_reset->value.Value());
                if (!reset)
                {
                    // Increase counter_int_count by counter_int_step
                    return DataValue(std::get<DataType::INT>(attr_counter_int_count->value.Value()) + std::get<DataType::INT>(attr_counter_int_step->value.Value()));
                } else
                {
                    return DataValue(0);
                }
            });

            // Attach the signal to the signal_wrapper
            // o_attr_counter_int_count.value()->value = signals[guid];
            attr_counter_int_count->signal_wrapper <<= signals[guid];

            // Initialize the tick
            int tick = 0;

            // Loop while
            // TODO: exit loop on application shutdown or entity deletion
            while (true)
            {
                // Wait for counter_int_millis milliseconds
                int millis = std::get<DataType::INT>(attr_counter_int_millis->value.Value());
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
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes {} {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    CounterIntEntityTypeProvider::COUNTER_INT_COUNT, CounterIntEntityTypeProvider::COUNTER_INT_MILLIS, CounterIntEntityTypeProvider::COUNTER_INT_RESET, CounterIntEntityTypeProvider::COUNTER_INT_STEP);
    }
}

} // namespace inexor::visual_scripting
