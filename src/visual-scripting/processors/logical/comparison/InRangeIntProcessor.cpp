#include "InRangeIntProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using namespace inexor::entity_system;
	using namespace inexor::entity_system::type_system;
	using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

	InRangeIntProcessor::InRangeIntProcessor(
		InRangeIntEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager,
		LogManagerPtr log_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager),
		  log_manager(log_manager)
	{
	}

	InRangeIntProcessor::~InRangeIntProcessor()
	{
	}

	void InRangeIntProcessor::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void InRangeIntProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
	{
		make_signals(entity_instance);
	}

	void InRangeIntProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void InRangeIntProcessor::make_signals(const EntityInstancePtr& entity_instance)
	{
		spdlog::get(LOGGER_NAME)->debug("Initializing processor IN_RANGE_INT for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());
		
        auto o_in_range_int_input = entity_instance->get_attribute_instance(InRangeIntEntityTypeProvider::IN_RANGE_INT_INPUT);
		auto o_in_range_int_min = entity_instance->get_attribute_instance(InRangeIntEntityTypeProvider::IN_RANGE_INT_MIN);
		auto o_in_range_int_max = entity_instance->get_attribute_instance(InRangeIntEntityTypeProvider::IN_RANGE_INT_MAX);
		auto o_in_range_int_result = entity_instance->get_attribute_instance(InRangeIntEntityTypeProvider::IN_RANGE_INT_RESULT);
		
        if(o_in_range_int_input.has_value() && o_in_range_int_min.has_value() && o_in_range_int_max.has_value() && o_in_range_int_result.has_value())
		{
			signals[entity_instance->get_GUID()] = MakeSignal(
				With(
					o_in_range_int_input.value()->value,
					o_in_range_int_min.value()->value,
					o_in_range_int_max.value()->value
				),
				[] (DataValue in_range_int_input, DataValue in_range_int_min, DataValue in_range_int_max)
				{
					int input = std::get<DataType::INT>(in_range_int_input);
					int min = std::get<DataType::INT>(in_range_int_min);
					int max = std::get<DataType::INT>(in_range_int_max);
					return DataValue(input > min && input < max);
				}
			);
			o_in_range_int_result.value()->value = signals[entity_instance->get_GUID()];
		}
        else
        {
			spdlog::get(LOGGER_NAME)->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(), InRangeIntEntityTypeProvider::IN_RANGE_INT_INPUT, InRangeIntEntityTypeProvider::IN_RANGE_INT_MIN, InRangeIntEntityTypeProvider::IN_RANGE_INT_MAX, InRangeIntEntityTypeProvider::IN_RANGE_INT_RESULT);
		}
	}

}
}
