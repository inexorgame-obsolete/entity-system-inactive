#include "LogicTest.hpp"

#include <chrono>
#include <thread>
#include <utility>

namespace inexor::visual_scripting {

LogicTest::LogicTest(ConnectorManagerPtr connector_manager, EqualsStringFactoryPtr equals_string_factory, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->running = false;
    this->connector_manager = std::move(connector_manager);
    this->equals_string_factory = std::move(equals_string_factory);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

LogicTest::~LogicTest() = default;

void LogicTest::init()
{
}

void LogicTest::shutdown()
{
}

void LogicTest::start_test()
{
    if (!running)
    {
        std::thread t(&inexor::visual_scripting::LogicTest::run_test, this);
        t.detach();
    }
}

void LogicTest::stop_test()
{
    if (running)
    {
        running = false;
    }
}

void LogicTest::run_test()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    running = true;
}

} // namespace inexor::visual_scripting
