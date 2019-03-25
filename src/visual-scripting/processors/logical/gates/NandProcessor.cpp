#include "NandProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using namespace inexor::entity_system;
	using namespace inexor::entity_system::type_system;
	using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

	NandProcessor::NandProcessor(
		NandEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager,
		LogManagerPtr log_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager),
		  log_manager(log_manager)
	{
	}

	NandProcessor::~NandProcessor()
	{
	}

	void NandProcessor::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void NandProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
	{
		make_signals(entity_instance);
	}

	void NandProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void NandProcessor::make_signals(const EntityInstancePtr& entity_instance)
	{
		spdlog::get(LOGGER_NAME)->debug("Initializing processor NAND for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());
		
        auto o_nand_input_1 = entity_instance->get_attribute_instance(NandEntityTypeProvider::NAND_INPUT_1);
		auto o_nand_input_2 = entity_instance->get_attribute_instance(NandEntityTypeProvider::NAND_INPUT_2);
		auto o_nand_result = entity_instance->get_attribute_instance(NandEntityTypeProvider::NAND_RESULT);
		
        if(o_nand_input_1.has_value() && o_nand_input_2.has_value() && o_nand_result.has_value())
		{
			signals[entity_instance->get_GUID()] = MakeSignal(
				With(
					o_nand_input_1.value()->value,
					o_nand_input_2.value()->value
				),
				[] (DataValue nand_input_1, DataValue nand_input_2)
				{
					return DataValue(!(std::get<DataType::BOOL>(nand_input_1) && std::get<DataType::BOOL>(nand_input_2)));
				}
			);
			o_nand_result.value()->value = signals[entity_instance->get_GUID()];
		}
        else
        {
			spdlog::get(LOGGER_NAME)->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(), NandEntityTypeProvider::NAND_INPUT_1, NandEntityTypeProvider::NAND_INPUT_2, NandEntityTypeProvider::NAND_RESULT);
		}
	}

}
}
