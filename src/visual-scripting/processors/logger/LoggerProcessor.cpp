#include "LoggerProcessor.hpp"

#include "react/Algorithm.h"
#include "react/Domain.h"
#include "react/Event.h"
#include "react/Observer.h"

namespace inexor {
namespace visual_scripting {

	using namespace inexor::entity_system;
	using namespace inexor::entity_system::type_system;
	using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

	LoggerProcessor::LoggerProcessor(
		LoggerEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager,
		LogManagerPtr logger_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager),
		  log_manager(log_manager)
	{
	}

	LoggerProcessor::~LoggerProcessor()
	{
	}

	void LoggerProcessor::init()
	{
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void LoggerProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
	{
		std::shared_ptr<inexor::entity_system::EntityType> entity_type = entity_instance->get_entity_type();
		std::cout << "Entity instance [" << entity_instance->get_GUID().str() << "] of type [" << entity_type->get_type_name() << "] created" << std::endl;
		make_signals(entity_instance);
	}

	void LoggerProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void LoggerProcessor::make_signals(const EntityInstancePtr& entity_instance)
	{
		std::cout << "Init entity instance for processor LOGGER" << std::endl;
		auto o_logger_name = entity_instance->get_attribute_instance(LoggerEntityTypeProvider::LOGGER_NAME);
		auto o_log_message = entity_instance->get_attribute_instance(LoggerEntityTypeProvider::LOG_MESSAGE);
		if (o_logger_name.has_value() && o_log_message.has_value())
		{
			std::string logger_name = std::get<DataType::STRING>(o_logger_name.value()->value.Value());
			observers[entity_instance->get_GUID()] = Observe(o_log_message.value()->value, [logger_name] (DataValue log_message) {
				spdlog::get(logger_name)->info(std::get<DataType::STRING>(log_message));
			});
		} else {
			// TODO: warn!
			std::cout << "attributes missing" << std::endl;
		}
	}

}
}
