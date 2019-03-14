#include "SinProcessor.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace visual_scripting {

	using SinEntityTypeProvider = entity_system::type_system::SinEntityTypeProvider;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

	SinProcessor::SinProcessor(
		SinEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager,
		LogManagerPtr log_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager),
		  log_manager(log_manager)
	{
	}

	SinProcessor::~SinProcessor()
	{
	}

	void SinProcessor::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void SinProcessor::on_entity_instance_created(std::shared_ptr<entity_system::EntityInstance> entity_instance)
	{
		make_signals(entity_instance);
	}

	void SinProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void SinProcessor::make_signals(const std::shared_ptr<entity_system::EntityInstance>& entity_instance)
	{
		spdlog::get(LOGGER_NAME)->debug("Initializing processor SIN for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());
		EntityAttributeInstancePtrOpt o_attr_sin_input = entity_instance->get_attribute_instance(SinEntityTypeProvider::SIN_INPUT);
		EntityAttributeInstancePtrOpt o_attr_sin_value = entity_instance->get_attribute_instance(SinEntityTypeProvider::SIN_VALUE);
		if (o_attr_sin_input.has_value() && o_attr_sin_value.has_value())
		{
		    signals[entity_instance->get_GUID()] = MakeSignal(
	    		o_attr_sin_input.value()->value,
				[] (DataValue sin_input)
				{
					return entity_system::DataValue(sinf(std::get<DataType::FLOAT>(sin_input)));
				}
			);
		    // o_attr_sin_value.value()->signal_wrapper <<= signals[entity_instance->get_GUID()];
		    o_attr_sin_value.value()->value = signals[entity_instance->get_GUID()];
		} else {
			spdlog::get(LOGGER_NAME)->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(), SinEntityTypeProvider::SIN_INPUT, SinEntityTypeProvider::SIN_VALUE);
		}
	}

}
}
