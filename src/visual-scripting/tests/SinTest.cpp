#include "SinTest.hpp"
#include "visual-scripting/model/Connector.hpp"

#include "react/Observer.h"

#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <utility>

using namespace std::chrono_literals;

namespace inexor::visual_scripting {

using DataType = entity_system::DataType;
using DataValue = entity_system::DataValue;

using CounterFloatEntityTypeProvider = entity_system::type_system::CounterFloatEntityTypeProvider;
using FloatConstantEntityTypeProvider = entity_system::type_system::FloatConstantEntityTypeProvider;

float SinTest::TARGET_INITIAL_VALUE = 100.0f;

SinTest::SinTest(ConnectorManagerPtr connector_manager, FloatConstantFactoryPtr float_constant_factory, CounterFloatFactoryPtr counter_float_factory, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory,
                 AddFloatFactoryPtr add_float_factory, LogManagerPtr log_manager)
{
    this->running = false;
    this->connector_manager = std::move(connector_manager);
    this->float_constant_factory = std::move(float_constant_factory);
    this->counter_float_factory = std::move(counter_float_factory);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
    this->add_float_factory = std::move(add_float_factory);
    this->log_manager = std::move(log_manager);
}

SinTest::~SinTest() = default;

void SinTest::init()
{
    log_manager->register_logger(LOGGER_NAME);
    create_instances();
}

void SinTest::shutdown()
{
    // TODO: shutdown this test
}

void SinTest::start_test()
{
    if (!running && o_counter.has_value() && o_sin.has_value() && o_target.has_value())
    {
        std::thread t(&inexor::visual_scripting::SinTest::run_test, this);
        t.detach();
    }
}

void SinTest::stop_test()
{
    if (running)
    {
        connector_manager->delete_connector(connector_1);
        connector_manager->delete_connector(connector_2);
        observer.Detach();
        running = false;
    }
}

void SinTest::run_test()
{
    EntityInstancePtr counter = o_counter.value();
    EntityInstancePtr sin = o_sin.value();
    EntityInstancePtr target = o_target.value();

    EntityAttributeInstancePtrOpt o_counter_attr_count = counter->get_attribute_instance(CounterFloatEntityTypeProvider::COUNTER_FLOAT_COUNT);
    EntityAttributeInstancePtrOpt o_sin_attr_input = sin->get_attribute_instance(SIN_INPUT);
    EntityAttributeInstancePtrOpt o_sin_attr_value = sin->get_attribute_instance(SIN_VALUE);
    EntityAttributeInstancePtrOpt o_target_attr_value = target->get_attribute_instance(FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE);

    if (o_counter_attr_count.has_value() && o_sin_attr_input.has_value() && o_sin_attr_value.has_value() && o_target_attr_value.has_value())
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
        while (running)
        {
            // Just keep the thread alive
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
}

void SinTest::create_instances()
{
    // Counter increases by 0.1 every 50 ms
    log_create_entity_instance(COUNTER_NAME, 0.0f);
    o_counter = counter_float_factory->create_instance(50, 0.1f);

    log_create_entity_instance(SIN_NAME, 0.0f);
    o_sin = entity_instance_builder_factory->get_builder(TYPE_SIN)->attribute(SIN_INPUT, 0.0f)->attribute(SIN_VALUE, 0.0f)->build();

    log_create_entity_instance(TARGET_NAME, TARGET_INITIAL_VALUE);
    o_target = float_constant_factory->create_instance(TARGET_NAME, TARGET_INITIAL_VALUE);
}

void SinTest::create_connectors()
{
    log_create_connector(COUNTER_NAME, CounterFloatEntityTypeProvider::COUNTER_FLOAT_COUNT, SIN_NAME, SIN_INPUT);
    connector_1 = connector_manager->create_connector(counter_attr_count, sin_attr_input);
    // connector_manager->enable_debug(connector_1);

    log_create_connector(SIN_NAME, SIN_VALUE, TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE);
    connector_2 = connector_manager->create_connector(sin_attr_value, target_attr_value);
    // connector_manager->enable_debug(connector_2);
}

void SinTest::create_observer()
{
    // spdlog::get(LOGGER_NAME)->info("Create observer for {}.{} which logs to {}", TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, LOGGER_NAME);
    observer = Observe(target_attr_value->value, [this](DataValue target_value) { this->log_data_value("FLOAT_OBSERVER", TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, target_value); });
}

void SinTest::log_create_entity_instance(const std::string& entity_instance_name, float initial_value)
{
    // spdlog::get(LOGGER_NAME)->info("Creating entity instance {} with initial value {}", entity_instance_name, initial_value);
}

void SinTest::log_create_connector(const std::string& output_entity_instance_name, const std::string& output_entity_attr_name, const std::string& input_entity_instance_name, const std::string& input_entity_attr_name)
{
    // spdlog::get(LOGGER_NAME)->info("Create connector {}.{} ---> {}.{}", output_entity_instance_name, output_entity_attr_name, input_entity_instance_name, input_entity_attr_name);
}

void SinTest::log_attrs(const std::string& message)
{
    // spdlog::get(LOGGER_NAME)->info(message);
    log_attr(COUNTER_NAME, CounterFloatEntityTypeProvider::COUNTER_FLOAT_COUNT, counter_attr_count);
    log_attr(SIN_NAME, SIN_INPUT, sin_attr_input);
    log_attr(SIN_NAME, SIN_VALUE, sin_attr_value);
    log_attr(TARGET_NAME, FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, target_attr_value);
}

void SinTest::log_attr(const std::string& entity_instance_name, const std::string& entity_attr_name, const EntityAttributeInstancePtr& entity_attribute_instance)
{
    // spdlog::get(LOGGER_NAME)->info("{}.{} = {}", entity_instance_name, entity_attr_name, std::get<DataType::FLOAT>(entity_attribute_instance->value.Value()));
}

void SinTest::log_data_value(const std::string& prefix, const std::string& entity_instance_name, const std::string& entity_attr_name, const DataValue& data_value)
{
    // spdlog::get(LOGGER_NAME)->info("{} {}.{} = {}", prefix, entity_instance_name, entity_attr_name, std::get<DataType::FLOAT>(data_value));
}

} // namespace inexor::visual_scripting
