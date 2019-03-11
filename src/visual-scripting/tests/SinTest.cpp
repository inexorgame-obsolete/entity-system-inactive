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

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;
	using ConnectorPtr = std::shared_ptr<Connector>;
	using ConnectorPtrOpt = std::optional<ConnectorPtr>;

	using DataType = entity_system::DataType;
	using DataValue = entity_system::DataValue;

	using FloatConstantEntityTypeProvider = entity_system::type_system::FloatConstantEntityTypeProvider;
	using SinEntityTypeProvider = entity_system::type_system::SinEntityTypeProvider;

	float SinTest::TARGET_INITIAL_VALUE = 100.0f;

	SinTest::SinTest(
		ConnectorManagerPtr connector_manager,
		FloatConstantFactoryPtr float_constant_factory,
		SinFactoryPtr sin_factory,
		AddFloatFactoryPtr add_float_factory,
		LogManagerPtr log_manager
	)
	{
        this->connector_manager = connector_manager;
        this->float_constant_factory = float_constant_factory;
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
		std::thread t(&inexor::visual_scripting::SinTest::run_connector_tests, this);
		t.detach();
	}

	void SinTest::run_connector_tests()
	{
		std::this_thread::sleep_for(2s);

		log_create_entity_instance(SIN_NAME, 0.0f);
		EntityInstancePtrOpt o_sin = sin_factory->create_instance();

		log_create_entity_instance(TARGET_NAME, TARGET_INITIAL_VALUE);
		EntityInstancePtrOpt o_target = float_constant_factory->create_instance(TARGET_NAME, TARGET_INITIAL_VALUE);


		if (o_sin.has_value() && o_target.has_value())
		{
			EntityInstancePtr sin = o_sin.value();
			EntityInstancePtr target = o_target.value();

			EntityAttributeInstancePtrOpt o_sin_attr_value = sin->get_attribute_instance(SinEntityTypeProvider::SIN_VALUE);
			EntityAttributeInstancePtrOpt o_target_attr_value = target->get_attribute_instance(FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE);

			if (o_sin_attr_value.has_value() && o_target_attr_value.has_value())
			{

				EntityAttributeInstancePtr sin_attr_value = o_sin_attr_value.value();
				EntityAttributeInstancePtr target_attr_value = o_target_attr_value.value();

				spdlog::get(LOGGER_NAME)->info("The initial values BEFORE connectors are created:");
				log_attr(SIN_NAME, SinEntityTypeProvider::SIN_VALUE, sin_attr_value);
				log_attr(TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, target_attr_value);

				log_create_connector(SIN_NAME, SinEntityTypeProvider::SIN_VALUE, TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE);
				ConnectorPtrOpt connector_1 = connector_manager->create_connector(sin_attr_value, target_attr_value);
				enable_connector_debug(connector_1);

				spdlog::get(LOGGER_NAME)->info("The initial values AFTER connectors are created:");
				log_attr(SIN_NAME, SinEntityTypeProvider::SIN_VALUE, sin_attr_value);
				log_attr(TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, target_attr_value);

				spdlog::get(LOGGER_NAME)->info("Create observer for {}.{} which logs to {}", TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, LOGGER_NAME);
				ObserverT observer = Observe(target_attr_value->value, [this] (DataValue target_value) {
					this->log_data_value("FLOAT_OBSERVER", TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, target_value);
				});

				// Random
				std::random_device rdev;
				std::mt19937 rgen(rdev());
				std::uniform_int_distribution<int> idist(0, 1000);
				int i = 0;
				while (i < 998)
				{
					std::this_thread::sleep_for(2s);
					i = idist(rgen);
				}

			}
		}
	}

	void SinTest::log_create_entity_instance(std::string entity_instance_name, float initial_value)
	{
		spdlog::get(LOGGER_NAME)->info("Creating entity instance {} with initial value {}", entity_instance_name, initial_value);
	}

	void SinTest::log_create_connector(std::string output_entity_instance_name, std::string output_entity_attr_name, std::string input_entity_instance_name, std::string input_entity_attr_name)
	{
		spdlog::get(LOGGER_NAME)->info("Create connector {}.{} ---> {}.{}", output_entity_instance_name, output_entity_attr_name, input_entity_instance_name, input_entity_attr_name);
	}

	void SinTest::log_attr(std::string entity_instance_name, std::string entity_attr_name, EntityAttributeInstancePtr entity_attribute_instance)
	{
		spdlog::get(LOGGER_NAME)->info("{}.{} = {}", entity_instance_name, entity_attr_name, std::get<DataType::FLOAT>(entity_attribute_instance->value.Value()));
	}

	void SinTest::log_data_value(std::string prefix, std::string entity_instance_name, std::string entity_attr_name, DataValue data_value)
	{
		spdlog::get(LOGGER_NAME)->info("{} {}.{} = {}", prefix, entity_instance_name, entity_attr_name, std::get<DataType::FLOAT>(data_value));
	}

	void SinTest::enable_connector_debug(ConnectorPtrOpt connector) {
		if (connector.has_value())
		{
			connector.value()->enable_debug();
		} else {
			spdlog::get(LOGGER_NAME)->error("Failed to enable debugging on connector");
		}
	}

}
}
