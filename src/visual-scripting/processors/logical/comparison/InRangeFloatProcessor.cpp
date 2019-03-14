#include "InRangeFloatProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using namespace inexor::entity_system;
	using namespace inexor::entity_system::type_system;
	using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

	InRangeFloatProcessor::InRangeFloatProcessor(
		InRangeFloatEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager,
		LogManagerPtr log_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager),
		  log_manager(log_manager)
	{
	}

	InRangeFloatProcessor::~InRangeFloatProcessor()
	{
	}

	void InRangeFloatProcessor::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void InRangeFloatProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
	{
		make_signals(entity_instance);
	}

	void InRangeFloatProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void InRangeFloatProcessor::make_signals(const EntityInstancePtr& entity_instance)
	{
		spdlog::get(LOGGER_NAME)->debug("Initializing processor IN_RANGE_FLOAT for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());
		auto o_in_range_float_input = entity_instance->get_attribute_instance(InRangeFloatEntityTypeProvider::IN_RANGE_FLOAT_INPUT);
		auto o_in_range_float_min = entity_instance->get_attribute_instance(InRangeFloatEntityTypeProvider::IN_RANGE_FLOAT_MIN);
		auto o_in_range_float_max = entity_instance->get_attribute_instance(InRangeFloatEntityTypeProvider::IN_RANGE_FLOAT_MAX);
		auto o_in_range_float_result = entity_instance->get_attribute_instance(InRangeFloatEntityTypeProvider::IN_RANGE_FLOAT_RESULT);
		if (o_in_range_float_input.has_value() && o_in_range_float_min.has_value() && o_in_range_float_max.has_value() && o_in_range_float_result.has_value())
		{
			signals[entity_instance->get_GUID()] = MakeSignal(
				With(
					o_in_range_float_input.value()->value,
					o_in_range_float_min.value()->value,
					o_in_range_float_max.value()->value
				),
				[] (DataValue in_range_float_input, DataValue in_range_float_min, DataValue in_range_float_max)
				{
					int input = std::get<DataType::FLOAT>(in_range_float_input);
					int min = std::get<DataType::FLOAT>(in_range_float_min);
					int max = std::get<DataType::FLOAT>(in_range_float_max);
					return DataValue(input > min && input < max);
				}
			);
			o_in_range_float_result.value()->value = signals[entity_instance->get_GUID()];
		} else {
			spdlog::get(LOGGER_NAME)->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(), InRangeFloatEntityTypeProvider::IN_RANGE_FLOAT_INPUT, InRangeFloatEntityTypeProvider::IN_RANGE_FLOAT_MIN, InRangeFloatEntityTypeProvider::IN_RANGE_FLOAT_MAX, InRangeFloatEntityTypeProvider::IN_RANGE_FLOAT_RESULT);
		}
	}

}
}
