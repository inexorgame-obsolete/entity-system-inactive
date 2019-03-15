#include "RandomNextIntProcessor.hpp"

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"

#include "react/Algorithm.h"
#include "react/Domain.h"
#include "react/Observer.h"

#include "spdlog/spdlog.h"

namespace inexor {
namespace visual_scripting {

	using RandomNextIntEntityTypeProvider = entity_system::type_system::RandomNextIntEntityTypeProvider;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

	using DataValue = entity_system::DataValue;
	using DataType = entity_system::DataType;

	RandomNextIntProcessor::RandomNextIntProcessor(
		RandomNextIntEntityTypeProviderPtr entity_type_provider,
		EntityInstanceManagerPtr entity_instance_manager,
		LogManagerPtr log_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager),
		  log_manager(log_manager)
	{
	}

	RandomNextIntProcessor::~RandomNextIntProcessor()
	{
	}

	void RandomNextIntProcessor::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void RandomNextIntProcessor::on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance)
	{
		make_signals(entity_instance);
	}

	void RandomNextIntProcessor::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void RandomNextIntProcessor::make_signals(const std::shared_ptr<inexor::entity_system::EntityInstance>& entity_instance)
	{
		spdlog::get(LOGGER_NAME)->debug("Initializing processor RANDOM_NEXT_INT for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());
		EntityAttributeInstancePtrOpt o_attr_random_next_int_on_activation = entity_instance->get_attribute_instance(RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_ON_ACTIVATION);
		EntityAttributeInstancePtrOpt o_attr_random_next_int_min = entity_instance->get_attribute_instance(RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_MIN);
		EntityAttributeInstancePtrOpt o_attr_random_next_int_max = entity_instance->get_attribute_instance(RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_MAX);
		EntityAttributeInstancePtrOpt o_attr_random_next_int_value = entity_instance->get_attribute_instance(RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_VALUE);
		if (o_attr_random_next_int_on_activation.has_value() && o_attr_random_next_int_min.has_value() && o_attr_random_next_int_max.has_value() && o_attr_random_next_int_value.has_value())
		{
			xg::Guid guid = entity_instance->get_GUID();


		    // Create the signal
		    signals[guid] = MakeSignal(
		    	With(
		    		o_attr_random_next_int_on_activation.value()->value,
					o_attr_random_next_int_min.value()->value,
					o_attr_random_next_int_max.value()->value
		    	),
				[this] (DataValue on_activation, DataValue min, DataValue max)
				{
					std::mt19937 random_generator(random_device());
					std::uniform_int_distribution<int> dist(std::get<DataType::INT>(min), std::get<DataType::INT>(max));
					return DataValue(dist(random_generator));
				}
			);

		    // Attach the signal to the signal_wrapper
			// o_attr_random_next_int_value.value()->value = signals[guid];
		    o_attr_random_next_int_value.value()->signal_wrapper <<= signals[guid];

		} else {
			spdlog::get(LOGGER_NAME)->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes {} {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(), RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_ON_ACTIVATION, RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_MIN, RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_MAX, RandomNextIntEntityTypeProvider::RANDOM_NEXT_INT_VALUE);
		}
	}

}
}
