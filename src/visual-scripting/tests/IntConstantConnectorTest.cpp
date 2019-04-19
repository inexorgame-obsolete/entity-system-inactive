#include "IntConstantConnectorTest.hpp"

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "visual-scripting/model/Connector.hpp"

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Observer.h"

#include "spdlog/spdlog.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <random>

namespace inexor {
namespace visual_scripting {

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;
	using ConnectorPtr = std::shared_ptr<Connector>;
	using ConnectorPtrOpt = std::optional<ConnectorPtr>;

	using DataType = entity_system::DataType;
	using DataValue = entity_system::DataValue;

	using IntConstantEntityTypeProvider = entity_system::type_system::IntConstantEntityTypeProvider;
	using AddIntEntityTypeProvider = entity_system::type_system::AddIntEntityTypeProvider;

	int IntConstantConnectorTest::SOURCE_INITIAL_VALUE = 100;
	int IntConstantConnectorTest::TARGET_1_INITIAL_VALUE = 200;
	int IntConstantConnectorTest::TARGET_2_INITIAL_VALUE = 300;
	int IntConstantConnectorTest::TARGET_3_INITIAL_VALUE = 400;

	IntConstantConnectorTest::IntConstantConnectorTest(
		ConnectorManagerPtr connector_manager,
		IntConstantFactoryPtr int_constant_factory,
		AddIntFactoryPtr add_int_factory,
		LogManagerPtr log_manager
	)
	{
		this->running = false;
        this->connector_manager = connector_manager;
        this->int_constant_factory = int_constant_factory;
        this->add_int_factory = add_int_factory;
        this->log_manager = log_manager;
	}
	
	IntConstantConnectorTest::~IntConstantConnectorTest()
	{
	}

	void IntConstantConnectorTest::init()
	{
		o_logger = log_manager->register_logger(LOGGER_NAME);
		create_instances();
	}

	void IntConstantConnectorTest::shutdown()
	{
		// TODO: shutdown this test
	}

	void IntConstantConnectorTest::start_test()
	{
		if(!running && o_source.has_value() && o_target_1.has_value() && o_target_2.has_value() && o_target_3.has_value())
		{
			std::thread t(&inexor::visual_scripting::IntConstantConnectorTest::run_test, this);
			t.detach();
		}
	}

	void IntConstantConnectorTest::stop_test()
	{
		if(running)
		{
			connector_manager->delete_connector(connector_1);
			connector_manager->delete_connector(connector_2);
			connector_manager->delete_connector(connector_3);
			connector_manager->delete_connector(connector_4);
			connector_manager->delete_connector(connector_5);
			observer.Detach();
			running = false;
		}
	}

	void IntConstantConnectorTest::run_test()
	{
		EntityInstancePtr source = o_source.value();
		EntityInstancePtr target_1 = o_target_1.value();
		EntityInstancePtr target_2 = o_target_2.value();
		EntityInstancePtr target_3 = o_target_3.value();
		EntityInstancePtr add_int = o_add_int.value();

		EntityAttributeInstancePtrOpt o_source_attr_value = source->get_attribute_instance(IntConstantEntityTypeProvider::INT_CONSTANT_VALUE);
		EntityAttributeInstancePtrOpt o_target_1_attr_value = target_1->get_attribute_instance(IntConstantEntityTypeProvider::INT_CONSTANT_VALUE);
		EntityAttributeInstancePtrOpt o_target_2_attr_value = target_2->get_attribute_instance(IntConstantEntityTypeProvider::INT_CONSTANT_VALUE);
		EntityAttributeInstancePtrOpt o_target_3_attr_value = target_3->get_attribute_instance(IntConstantEntityTypeProvider::INT_CONSTANT_VALUE);
		EntityAttributeInstancePtrOpt o_add_int_attr_augend = add_int->get_attribute_instance(AddIntEntityTypeProvider::ADD_INT_AUGEND);
		EntityAttributeInstancePtrOpt o_add_int_attr_addend = add_int->get_attribute_instance(AddIntEntityTypeProvider::ADD_INT_ADDEND);
		EntityAttributeInstancePtrOpt o_add_int_attr_sum = add_int->get_attribute_instance(AddIntEntityTypeProvider::ADD_INT_SUM);

		if(o_source_attr_value.has_value() && o_target_1_attr_value.has_value() && o_target_2_attr_value.has_value() && o_target_3_attr_value.has_value() && o_add_int_attr_augend.has_value() && o_add_int_attr_addend.has_value() && o_add_int_attr_sum.has_value())
		{
			source_attr_value = o_source_attr_value.value();
			target_1_attr_value = o_target_1_attr_value.value();
			target_2_attr_value = o_target_2_attr_value.value();
			target_3_attr_value = o_target_3_attr_value.value();
			add_int_attr_augend = o_add_int_attr_augend.value();
			add_int_attr_addend = o_add_int_attr_addend.value();
			add_int_attr_sum = o_add_int_attr_sum.value();

			log_attrs("The initial values BEFORE connectors are created:");
			create_connectors();

			create_observer();
			log_attrs("The initial values AFTER connectors are created:");

			// Random
			std::random_device rdev;
			std::mt19937 rgen(rdev());
			std::uniform_int_distribution<int> idist(0, 1000);

			running = true;
			int i = 0;
			while(running)
			{
				// Generate new random value every 2 seconds
				std::this_thread::sleep_for(std::chrono::seconds(2));
				i = idist(rgen);

				//spdlog::get(LOGGER_NAME)->info("Setting {}.{} to value {}. The value should be propagated.", SOURCE_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE, i);
				source_attr_value->own_value.Set(i);

				log_attrs("The propagated values:");
			}

		}
	}

	void IntConstantConnectorTest::create_instances()
	{
		log_create_entity_instance(SOURCE_NAME, SOURCE_INITIAL_VALUE);
		o_source = int_constant_factory->create_instance(SOURCE_NAME, SOURCE_INITIAL_VALUE);

		log_create_entity_instance(TARGET_1_NAME, TARGET_1_INITIAL_VALUE);
		o_target_1 = int_constant_factory->create_instance(TARGET_1_NAME, TARGET_1_INITIAL_VALUE);

		log_create_entity_instance(TARGET_2_NAME, TARGET_1_INITIAL_VALUE);
		o_target_2 = int_constant_factory->create_instance(TARGET_2_NAME, TARGET_2_INITIAL_VALUE);

		log_create_entity_instance(TARGET_3_NAME, TARGET_1_INITIAL_VALUE);
		o_target_3 = int_constant_factory->create_instance(TARGET_3_NAME, TARGET_3_INITIAL_VALUE);

		//spdlog::get(LOGGER_NAME)->info("Creating entity instance {} without initial values", ADD_INT_NAME);
		o_add_int = add_int_factory->create_instance();
	}

	void IntConstantConnectorTest::create_connectors()
	{
		// source --> target_1
		log_create_connector(SOURCE_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE, TARGET_1_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE);
		connector_1 = connector_manager->create_connector(source_attr_value, target_1_attr_value);
		// connector_manager->enable_debug(connector_1);

		// source --> target_2
		log_create_connector(SOURCE_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE, TARGET_2_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE);
		connector_2 = connector_manager->create_connector(source_attr_value, target_2_attr_value);
		// connector_manager->enable_debug(connector_2);

		// target_1 --> target_3
		log_create_connector(TARGET_1_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE, TARGET_3_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE);
		connector_3 = connector_manager->create_connector(target_1_attr_value, target_3_attr_value);
		// connector_manager->enable_debug(connector_3);

		// target_2 --> add_int_augend
		log_create_connector(TARGET_2_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE, ADD_INT_NAME, AddIntEntityTypeProvider::ADD_INT_AUGEND);
		connector_4 = connector_manager->create_connector(target_2_attr_value, add_int_attr_augend);
		// connector_manager->enable_debug(connector_4);

		// target_3 --> add_int_addend
		log_create_connector(TARGET_3_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE, ADD_INT_NAME, AddIntEntityTypeProvider::ADD_INT_ADDEND);
		connector_5 = connector_manager->create_connector(target_3_attr_value, add_int_attr_addend);
		// connector_manager->enable_debug(connector_5);
	}

	void IntConstantConnectorTest::create_observer()
	{
		if(o_logger.has_value())
		{
			//spdlog::get(LOGGER_NAME)->info("Create observer for {}.{} which logs to {}", ADD_INT_NAME, AddIntEntityTypeProvider::ADD_INT_ADDEND, LOGGER_NAME);
			observer = Observe(add_int_attr_sum->value, [this] (DataValue add_int_sum) {
				this->log_data_value("SUM_OBSERVER", ADD_INT_NAME, AddIntEntityTypeProvider::ADD_INT_SUM, add_int_sum);
			});
		}
	}

	void IntConstantConnectorTest::log_create_entity_instance(std::string entity_instance_name, int initial_value)
	{
		//spdlog::get(LOGGER_NAME)->info("Creating entity instance {} with initial value {}", entity_instance_name, initial_value);
	}

	void IntConstantConnectorTest::log_create_connector(std::string output_entity_instance_name, std::string output_entity_attr_name, std::string input_entity_instance_name, std::string input_entity_attr_name)
	{
		//spdlog::get(LOGGER_NAME)->info("Create connector {}.{} ---> {}.{}", output_entity_instance_name, output_entity_attr_name, input_entity_instance_name, input_entity_attr_name);
	}

	void IntConstantConnectorTest::log_attrs(std::string message)
	{
		//spdlog::get(LOGGER_NAME)->info(message);
		log_attr(SOURCE_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE, source_attr_value);
		log_attr(TARGET_1_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE, target_1_attr_value);
		log_attr(TARGET_2_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE, target_2_attr_value);
		log_attr(TARGET_3_NAME, IntConstantEntityTypeProvider::INT_CONSTANT_VALUE, target_3_attr_value);
		log_attr(ADD_INT_NAME, AddIntEntityTypeProvider::ADD_INT_AUGEND, add_int_attr_augend);
		log_attr(ADD_INT_NAME, AddIntEntityTypeProvider::ADD_INT_ADDEND, add_int_attr_addend);
		log_attr(ADD_INT_NAME, AddIntEntityTypeProvider::ADD_INT_SUM, add_int_attr_sum);
	}

	void IntConstantConnectorTest::log_attr(std::string entity_instance_name, std::string entity_attr_name, EntityAttributeInstancePtr entity_attribute_instance)
	{
		//spdlog::get(LOGGER_NAME)->info("{}.{} = {}", entity_instance_name, entity_attr_name, std::get<DataType::INT>(entity_attribute_instance->value.Value()));
	}

	void IntConstantConnectorTest::log_data_value(std::string prefix, std::string entity_instance_name, std::string entity_attr_name, DataValue data_value)
	{
		//spdlog::get(LOGGER_NAME)->info("{} {}.{} = {}", prefix, entity_instance_name, entity_attr_name, std::get<DataType::INT>(data_value));
	}

}
}
