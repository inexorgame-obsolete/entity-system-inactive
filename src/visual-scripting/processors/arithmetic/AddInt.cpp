// Inexor entity system
// (c)2018-2019 Inexor

#include "AddInt.hpp"

#include "react/Algorithm.h"
#include "react/Domain.h"
#include "react/Event.h"
#include "react/Observer.h"

namespace inexor {
namespace visual_scripting {

	AddInt::AddInt(
		std::shared_ptr<inexor::entity_system::type_system::AddIntEntityTypeProvider> entity_type_provider,
		std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager
	)
		: Processor(entity_type_provider->get_type()),
		  entity_type_provider(entity_type_provider),
		  entity_instance_manager(entity_instance_manager)
	{
	}

	AddInt::~AddInt()
	{
	}

	void AddInt::init()
	{
		entity_instance_manager->register_on_created(entity_type_provider->get_type()->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type_provider->get_type()->get_GUID(), shared_from_this());
	}

	void AddInt::on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance)
	{
		// Get entity type
		std::shared_ptr<inexor::entity_system::EntityType> entity_type = entity_instance->get_entity_type();
		std::cout << "Entity instance [" << entity_instance->get_GUID().str() << "] of type [" << entity_type->get_type_name() << "] created" << std::endl;
		connect(entity_instance);
	}

	void AddInt::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		// Disconnect observers with execution method
		// Delete observer for each input atttribute of the entity instance
		// TODO: remove / clear signal
		// signals[inst_GUID].clear
	}

	void AddInt::connect(const std::shared_ptr<inexor::entity_system::EntityInstance>& entity_instance)
	{
		std::cout << "Init entity instance for processor ADD_INT" << std::endl;
		std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_augend = entity_instance->get_attribute_instance("add_int_augend");
		std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_addend = entity_instance->get_attribute_instance("add_int_addend");
		std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_sum = entity_instance->get_attribute_instance("add_int_sum");
		if (o_augend.has_value() && o_addend.has_value() && o_sum.has_value())
		{
			signals[entity_instance->get_GUID()] = MakeSignal(
				With(
					o_augend.value()->value,
					o_addend.value()->value
				),
				[] (inexor::entity_system::DataValue augend, inexor::entity_system::DataValue addend)
				{
					int result = std::get<DataType::INT>(augend) + std::get<DataType::INT>(addend);
					std::cout << "ADD_INT: " << std::get<DataType::INT>(augend) << " + " << std::get<DataType::INT>(addend) << " = " << result << std::endl;
					return DataValue(result);
				}
			);
			o_sum.value()->value = signals[entity_instance->get_GUID()];
		} else {
			// TODO: warn!
			std::cout << "attributes missing" << std::endl;
		}
	}

};
};
