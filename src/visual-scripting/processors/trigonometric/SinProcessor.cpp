#include "SinProcessor.hpp"

#include "react/Algorithm.h"
#include "react/Domain.h"
#include "react/Event.h"
#include "react/Observer.h"

using namespace std::chrono;

namespace inexor {
namespace visual_scripting {

	SinProcessor::SinProcessor(
		std::shared_ptr<inexor::entity_system::type_system::SinEntityTypeProvider> entity_type_provider,
		std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager)
	{
	}

	SinProcessor::~SinProcessor()
	{
	}

	void SinProcessor::init()
	{
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void SinProcessor::on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance)
	{
		// Get entity type
		std::shared_ptr<inexor::entity_system::EntityType> entity_type = entity_instance->get_entity_type();
		std::cout << "Entity instance [" << entity_instance->get_GUID().str() << "] of type [" << entity_type->get_type_name() << "] created" << std::endl;
		make_signals(entity_instance);
	}

	void SinProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void SinProcessor::make_signals(const std::shared_ptr<inexor::entity_system::EntityInstance>& entity_instance)
	{
		std::cout << "Init entity instance for processor SIN" << std::endl;
		std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_attr_sin_value = entity_instance->get_attribute_instance(inexor::entity_system::type_system::SinEntityTypeProvider::SIN_VALUE);
		if (o_attr_sin_value.has_value())
		{
			xg::Guid guid = entity_instance->get_GUID();
			std::shared_ptr<inexor::entity_system::EntityAttributeInstance> attr_sin_value = o_attr_sin_value.value();
		    std::thread start_thread([this, guid, attr_sin_value] () {

		    	// Create event source
				event_sources[guid] = MakeEventSource<D, int>();

		    	// Hold last signal value
				current_time_iterators[guid] = Hold(event_sources[guid], 0);

				// Initialize the time iterator
		    	int time_iterator = 0;
				std::cout << "time_iterator = " << time_iterator << std::endl;

				// Initialize the sinus resolution
			    float resolution = 10.0f;

			    // Create the signal
			    signals[guid] = MakeSignal(
					current_time_iterators[guid],
					[resolution] (int time_iterator)
					{
				    	float x_value = time_iterator / resolution;
						float y_value = sin(x_value);
						return DataValue(y_value);
					}
				);

			    // Attach the signal to the signal_wrapper
				// o_attr_sin_value.value()->value = signals[guid];
			    attr_sin_value->signal_wrapper <<= signals[guid];

				// Loop while TODO
				while (true)
				{
					// Wait
					std::this_thread::sleep_for(50ms);

					// Increase time iterator
					time_iterator++;

					// Fire time iterator event
					this->event_sources[guid] << time_iterator;
				}
			});
		    start_thread.detach();
		} else {
			// TODO: warn!
			std::cout << "attributes missing" << std::endl;
		}
	}

};
};
