#include "ConsoleTest.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "visual-scripting/model/Connector.hpp"

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Observer.h"

#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

namespace inexor {
namespace visual_scripting {

	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;
	using ConnectorPtr = std::shared_ptr<Connector>;
	using ConnectorPtrOpt = std::optional<ConnectorPtr>;

	using DataType = entity_system::DataType;
	using DataValue = entity_system::DataValue;

	ConsoleTest::ConsoleTest(
		ConnectorManagerPtr connector_manager,
		StdInEntityTypeProviderPtr stdin_entity_type_provider,
		StdOutEntityTypeProviderPtr stdout_entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
        this->connector_manager = connector_manager;
        this->stdin_entity_type_provider = stdin_entity_type_provider;
        this->stdout_entity_type_provider = stdout_entity_type_provider;
        this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	
	ConsoleTest::~ConsoleTest()
	{
	}

	void ConsoleTest::init()
	{
		std::thread t(&inexor::visual_scripting::ConsoleTest::run_connector_tests, this);
		t.detach();
	}

	void ConsoleTest::run_connector_tests()
	{
		std::this_thread::sleep_for(2s);

		// Create single instance for STDIN
		o_stdin = entity_instance_builder_factory->get_builder()
			->type(stdin_entity_type_provider->get_type())
			->attribute(StdInEntityTypeProvider::CONSOLE_STDIN, std::string(""))
			->build();
		EntityAttributeInstancePtrOpt o_stdin_value = o_stdin.value()->get_attribute_instance(StdInEntityTypeProvider::CONSOLE_STDIN);
		EntityAttributeInstancePtr stdin_value = o_stdin_value.value();

		// Create single instance for STDOUT
		o_stdout = entity_instance_builder_factory->get_builder()
			->type(stdout_entity_type_provider->get_type())
			->attribute(StdOutEntityTypeProvider::CONSOLE_STDOUT, std::string(""))
			->build();
		EntityAttributeInstancePtrOpt o_stdout_value = o_stdout.value()->get_attribute_instance(StdOutEntityTypeProvider::CONSOLE_STDOUT);
		EntityAttributeInstancePtr stdout_value = o_stdout_value.value();

		ConnectorPtrOpt stdin_stdout_connector = connector_manager->create_connector(stdin_value, stdout_value);
		stdin_stdout_connector.value()->enable_debug();

	}

}
}
