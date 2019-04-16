#include "SinTest.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "visual-scripting/model/Connector.hpp"

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Observer.h"

#include <iostream>
#include <chrono>
#include <thread>
#include <random>

using namespace std::chrono_literals;

namespace inexor {
namespace visual_scripting {

	using DataType = entity_system::DataType;
	using DataValue = entity_system::DataValue;

	using CounterFloatEntityTypeProvider = entity_system::type_system::CounterFloatEntityTypeProvider;
	using SinEntityTypeProvider = entity_system::type_system::SinEntityTypeProvider;
	using FloatConstantEntityTypeProvider = entity_system::type_system::FloatConstantEntityTypeProvider;

	float SinTest::TARGET_INITIAL_VALUE = 100.0f;

	SinTest::SinTest(
		ConnectorManagerPtr connector_manager,
		FloatConstantFactoryPtr float_constant_factory,
		CounterFloatFactoryPtr counter_float_factory,
		SinFactoryPtr sin_factory,
		AddFloatFactoryPtr add_float_factory,
		LogManagerPtr log_manager
	)
	{
		this->running = false;
        this->connector_manager = connector_manager;
        this->float_constant_factory = float_constant_factory;
        this->counter_float_factory = counter_float_factory;
        this->sin_factory = sin_factory;
        this->add_float_factory = add_float_factory;
        this->log_manager = log_manager;
	}

	
	SinTest::~SinTest()
	{
	}

	void SinTest::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		create_instances();
	}

	void SinTest::start_test()
	{
		if(!running && o_counter.has_value() && o_sin.has_value() && o_target.has_value())
		{
			std::thread t(&inexor::visual_scripting::SinTest::run_test, this);
			t.detach();
		}
        else
        {
			std::cout << "1" << std::endl;
		}
	}

	void SinTest::stop_test()
	{
		if(running)
		{
			connector_manager->delete_connector(connector_1);
			connector_manager->delete_connector(connector_2);
			observer.Detach();
			running = false;
		}
        else
        {
			std::cout << "2" << std::endl;
		}
	}

	void SinTest::run_test()
	{
		EntityInstancePtr counter = o_counter.value();
		EntityInstancePtr sin = o_sin.value();
		EntityInstancePtr target = o_target.value();

		EntityAttributeInstancePtrOpt o_counter_attr_count = counter->get_attribute_instance(CounterFloatEntityTypeProvider::COUNTER_FLOAT_COUNT);
		EntityAttributeInstancePtrOpt o_sin_attr_input = sin->get_attribute_instance(SinEntityTypeProvider::SIN_INPUT);
		EntityAttributeInstancePtrOpt o_sin_attr_value = sin->get_attribute_instance(SinEntityTypeProvider::SIN_VALUE);
		EntityAttributeInstancePtrOpt o_target_attr_value = target->get_attribute_instance(FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE);

		if(o_counter_attr_count.has_value() && o_sin_attr_input.has_value() && o_sin_attr_value.has_value() && o_target_attr_value.has_value())
		{
			counter_attr_count = o_counter_attr_count.value();
			sin_attr_input = o_sin_attr_input.value();
			sin_attr_value = o_sin_attr_value.value();
			target_attr_value = o_target_attr_value.value();

			log_attrs("The initial values BEFORE connectors are created:");
			create_connectors();

			log_attrs("The initial values AFTER connectors are created:");
			create_observer();

			running = true;
			while(running)
			{
				// Just keep the thread alive
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
		}
        else
        {
			std::cout << "3" << std::endl;
		}
	}

	void SinTest::create_instances()
	{
		// Counter increases by 0.1 every 50 ms
		log_create_entity_instance(COUNTER_NAME, 0.0f);
		o_counter = counter_float_factory->create_instance(50, 0.1f);

		log_create_entity_instance(SIN_NAME, 0.0f);
		o_sin = sin_factory->create_instance();

		log_create_entity_instance(TARGET_NAME, TARGET_INITIAL_VALUE);
		o_target = float_constant_factory->create_instance(TARGET_NAME, TARGET_INITIAL_VALUE);
	}

	void SinTest::create_connectors()
	{
		log_create_connector(COUNTER_NAME, CounterFloatEntityTypeProvider::COUNTER_FLOAT_COUNT, SIN_NAME, SinEntityTypeProvider::SIN_INPUT);
		connector_1 = connector_manager->create_connector(counter_attr_count, sin_attr_input);
		// connector_manager->enable_debug(connector_1);

		log_create_connector(SIN_NAME, SinEntityTypeProvider::SIN_VALUE, TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE);
		connector_2 = connector_manager->create_connector(sin_attr_value, target_attr_value);
		// connector_manager->enable_debug(connector_2);
	}

	void SinTest::create_observer()
	{
		//spdlog::get(LOGGER_NAME)->info("Create observer for {}.{} which logs to {}", TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, LOGGER_NAME);
		observer = Observe(target_attr_value->value, [this] (DataValue target_value) {
			this->log_data_value("FLOAT_OBSERVER", TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, target_value);
		});
	}

	void SinTest::log_create_entity_instance(std::string entity_instance_name, float initial_value)
	{
		//spdlog::get(LOGGER_NAME)->info("Creating entity instance {} with initial value {}", entity_instance_name, initial_value);
	}

	void SinTest::log_create_connector(std::string output_entity_instance_name, std::string output_entity_attr_name, std::string input_entity_instance_name, std::string input_entity_attr_name)
	{
		//spdlog::get(LOGGER_NAME)->info("Create connector {}.{} ---> {}.{}", output_entity_instance_name, output_entity_attr_name, input_entity_instance_name, input_entity_attr_name);
	}

	void SinTest::log_attrs(std::string message)
	{
		//spdlog::get(LOGGER_NAME)->info(message);
		log_attr(COUNTER_NAME, CounterFloatEntityTypeProvider::COUNTER_FLOAT_COUNT, counter_attr_count);
		log_attr(SIN_NAME, SinEntityTypeProvider::SIN_INPUT, sin_attr_input);
		log_attr(SIN_NAME, SinEntityTypeProvider::SIN_VALUE, sin_attr_value);
		log_attr(TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, target_attr_value);
	}

	void SinTest::log_attr(std::string entity_instance_name, std::string entity_attr_name, EntityAttributeInstancePtr entity_attribute_instance)
	{
		//spdlog::get(LOGGER_NAME)->info("{}.{} = {}", entity_instance_name, entity_attr_name, std::get<DataType::FLOAT>(entity_attribute_instance->value.Value()));
	}

	void SinTest::log_data_value(std::string prefix, std::string entity_instance_name, std::string entity_attr_name, DataValue data_value)
	{
		//spdlog::get(LOGGER_NAME)->info("{} {}.{} = {}", prefix, entity_instance_name, entity_attr_name, std::get<DataType::FLOAT>(data_value));
	}

}
}
