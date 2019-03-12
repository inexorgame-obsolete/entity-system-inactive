#include "AndProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using namespace inexor::entity_system;
	using namespace inexor::entity_system::type_system;
	using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

	AndProcessor::AndProcessor(
		AndEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager,
		LogManagerPtr log_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager),
		  log_manager(log_manager)
	{
	}

	AndProcessor::~AndProcessor()
	{
	}

	void AndProcessor::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void AndProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
	{
		make_signals(entity_instance);
	}

	void AndProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void AndProcessor::make_signals(const EntityInstancePtr& entity_instance)
	{
		spdlog::get(LOGGER_NAME)->debug("Initializing processor AND for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());
		auto o_and_input_1 = entity_instance->get_attribute_instance(AndEntityTypeProvider::AND_INPUT_1);
		auto o_and_input_2 = entity_instance->get_attribute_instance(AndEntityTypeProvider::AND_INPUT_2);
		auto o_and_result = entity_instance->get_attribute_instance(AndEntityTypeProvider::AND_RESULT);
		if (o_and_input_1.has_value() && o_and_input_2.has_value() && o_and_result.has_value())
		{
			signals[entity_instance->get_GUID()] = MakeSignal(
				With(
					o_and_input_1.value()->value,
					o_and_input_2.value()->value
				),
				[] (DataValue and_input_1, DataValue and_input_2)
				{
					return DataValue(std::get<DataType::BOOL>(and_input_1) && std::get<DataType::BOOL>(and_input_2));
				}
			);
			o_and_result.value()->value = signals[entity_instance->get_GUID()];
		} else {
			spdlog::get(LOGGER_NAME)->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(), AndEntityTypeProvider::AND_INPUT_1, AndEntityTypeProvider::AND_INPUT_2, AndEntityTypeProvider::AND_RESULT);
		}
	}

}
}
