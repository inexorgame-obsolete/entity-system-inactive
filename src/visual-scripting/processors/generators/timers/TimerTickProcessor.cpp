#include "TimerTickProcessor.hpp"

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"

#include "react/Algorithm.h"
#include "react/Domain.h"
#include "react/Observer.h"

#include "spdlog/spdlog.h"

namespace inexor {
namespace visual_scripting {

	using TimerTickEntityTypeProvider = entity_system::type_system::TimerTickEntityTypeProvider;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

	using DataValue = entity_system::DataValue;
	using DataType = entity_system::DataType;

	TimerTickProcessor::TimerTickProcessor(
		TimerTickEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager,
		LogManagerPtr log_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager),
		  log_manager(log_manager)
	{
	}

	TimerTickProcessor::~TimerTickProcessor()
	{
	}

	void TimerTickProcessor::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void TimerTickProcessor::on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance)
	{
		make_signals(entity_instance);
	}

	void TimerTickProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void TimerTickProcessor::make_signals(const std::shared_ptr<inexor::entity_system::EntityInstance>& entity_instance)
	{
		spdlog::get(LOGGER_NAME)->debug("Initializing processor TIMER_TICK for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());
		
        EntityAttributeInstancePtrOpt o_attr_timer_tick_millis = entity_instance->get_attribute_instance(TimerTickEntityTypeProvider::TIMER_TICK_MILLIS);
		EntityAttributeInstancePtrOpt o_attr_timer_tick_value = entity_instance->get_attribute_instance(TimerTickEntityTypeProvider::TIMER_TICK_VALUE);
		
        if(o_attr_timer_tick_millis.has_value() && o_attr_timer_tick_value.has_value())
		{
			xg::Guid guid = entity_instance->get_GUID();
			EntityAttributeInstancePtr attr_timer_tick_millis = o_attr_timer_tick_millis.value();
			EntityAttributeInstancePtr attr_timer_tick_value = o_attr_timer_tick_value.value();

			std::thread start_thread([this, guid, attr_timer_tick_millis, attr_timer_tick_value] () {

		    	// Create event source
				event_sources[guid] = MakeEventSource<entity_system::D, int>();

		    	// Hold last signal value
				ticks[guid] = Hold(event_sources[guid], 0);

			    // Create the signal
			    signals[guid] = MakeSignal(
			    	ticks[guid],
					[ attr_timer_tick_value ] (int tick)
					{
						// Toggle timer tick value
						return DataValue(!std::get<DataType::BOOL>(attr_timer_tick_value->value.Value()));
					}
				);

			    // Attach the signal to the signal_wrapper
				// o_attr_timer_tick_count.value()->value = signals[guid];
			    attr_timer_tick_value->signal_wrapper <<= signals[guid];

				// Initialize the tick
		    	int tick = 0;

				// Loop while TODO
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

		}
        else
        {
			spdlog::get(LOGGER_NAME)->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(), TimerTickEntityTypeProvider::TIMER_TICK_VALUE, TimerTickEntityTypeProvider::TIMER_TICK_MILLIS);
		}
	}

}
}
