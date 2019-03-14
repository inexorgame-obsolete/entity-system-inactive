#include "StdErrProcessor.hpp"

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

	StdErrProcessor::StdErrProcessor(
		StdErrEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager)
	{
	}

	StdErrProcessor::~StdErrProcessor()
	{
	}

	void StdErrProcessor::init()
	{
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void StdErrProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
	{
		make_signals(entity_instance);
	}

	void StdErrProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void StdErrProcessor::make_signals(const EntityInstancePtr& entity_instance)
	{
		std::cout << "Initializing processor CONSOLE_STDERR for newly created entity instance " << entity_instance->get_GUID().str() << " of type " << entity_instance->get_entity_type()->get_type_name() << std::endl;
		auto o_console_stderr = entity_instance->get_attribute_instance(StdErrEntityTypeProvider::CONSOLE_STDERR);
		if (o_console_stderr.has_value())
		{
			observers[entity_instance->get_GUID()] = Observe(o_console_stderr.value()->value, [] (DataValue console_stderr) {
				std::cout << std::get<DataType::STRING>(console_stderr) << std::endl;
			});
		} else {
			std::cout << "Failed to initialize processor signals for entity instance " << entity_instance->get_GUID().str() << " of type " << entity_instance->get_entity_type()->get_type_name() << ": Missing attribute" << StdErrEntityTypeProvider::CONSOLE_STDERR << std::endl;
		}
	}

}
}
