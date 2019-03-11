#include "StdInProcessor.hpp"

#include "react/Algorithm.h"
#include "react/Domain.h"
#include "react/Event.h"
#include "react/Observer.h"

#include <iostream>

namespace inexor {
namespace visual_scripting {

	using namespace inexor::entity_system;
	using namespace inexor::entity_system::type_system;
	using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

	using EntityTypePtr = std::shared_ptr<entity_system::EntityType>;

	StdInProcessor::StdInProcessor(
		StdInEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager)
	{
	}

	StdInProcessor::~StdInProcessor()
	{
	}

	void StdInProcessor::init()
	{
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void StdInProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
	{
		make_signals(entity_instance);
	}

	void StdInProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void StdInProcessor::make_signals(const EntityInstancePtr& entity_instance)
	{
		std::cout << "Initializing processor LOGGER for newly created entity instance " << entity_instance->get_GUID().str() << " of type " << entity_instance->get_entity_type()->get_type_name() << std::endl;
		auto o_console_stdin = entity_instance->get_attribute_instance(StdInEntityTypeProvider::CONSOLE_STDIN);
		if (o_console_stdin.has_value())
		{
			xg::Guid guid = entity_instance->get_GUID();
			std::shared_ptr<inexor::entity_system::EntityAttributeInstance> attr_console_stdin = o_console_stdin.value();

		    std::thread start_thread([this, guid, attr_console_stdin] () {

		    	// Create event source
				event_sources[guid] = MakeEventSource<entity_system::D, std::string>();

		    	// Hold last signal value
				last_event_signals[guid] = Hold(event_sources[guid], "");

			    // Create the signal
			    signals[guid] = MakeSignal(
			    	last_event_signals[guid],
					[] (std::string stdin_line)
					{
						return entity_system::DataValue(stdin_line);
					}
				);

			    // Attach the signal to the signal_wrapper
			    attr_console_stdin->signal_wrapper <<= signals[guid];

				// Loop endless
				while (true)
				{
				    for (std::string line; std::getline(std::cin, line);) {
				    	this->event_sources[guid] << line;
					}
				}
			});
		    start_thread.detach();
		} else {
			std::cout << "Failed to initialize processor signals for entity instance " << entity_instance->get_GUID().str() << " of type " << entity_instance->get_entity_type()->get_type_name() << ": Missing attribute" << StdInEntityTypeProvider::CONSOLE_STDIN << std::endl;
		}
	}

}
}
