#include "ConsoleTest.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "visual-scripting/model/Connector.hpp"

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Observer.h"

#include <iostream>
#include <thread>

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
		StdErrEntityTypeProviderPtr stderr_entity_type_provider,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->running = false;
        this->connector_manager = connector_manager;
        this->stdin_entity_type_provider = stdin_entity_type_provider;
        this->stdout_entity_type_provider = stdout_entity_type_provider;
        this->stderr_entity_type_provider = stderr_entity_type_provider;
        this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	
	ConsoleTest::~ConsoleTest()
	{
	}

	void ConsoleTest::init()
	{
		// Create single instance for STDIN
		o_stdin = entity_instance_builder_factory->get_builder()
			->type(stdin_entity_type_provider->get_type())
			->attribute(StdInEntityTypeProvider::CONSOLE_STDIN, std::string(""))
			->build();

		// Create single instance for STDOUT
		o_stdout = entity_instance_builder_factory->get_builder()
			->type(stdout_entity_type_provider->get_type())
			->attribute(StdOutEntityTypeProvider::CONSOLE_STDOUT, std::string(""))
			->build();

		// Create single instance for STDERR
		o_stderr = entity_instance_builder_factory->get_builder()
			->type(stderr_entity_type_provider->get_type())
			->attribute(StdErrEntityTypeProvider::CONSOLE_STDERR, std::string(""))
			->build();

	}

	void ConsoleTest::start_test()
	{
		if (!running && o_stdin.has_value() && o_stdout.has_value() && o_stderr.has_value())
		{
			EntityAttributeInstancePtr stdin_value = o_stdin.value()->get_attribute_instance(StdInEntityTypeProvider::CONSOLE_STDIN).value();

			ConnectorPtrOpt o_stdin_stdout_connector = connector_manager->create_connector(
				stdin_value,
				o_stdout.value()->get_attribute_instance(StdOutEntityTypeProvider::CONSOLE_STDOUT).value()
			);

			ConnectorPtrOpt o_stdin_stderr_connector = connector_manager->create_connector(
				stdin_value,
				o_stderr.value()->get_attribute_instance(StdErrEntityTypeProvider::CONSOLE_STDERR).value()
			);

			if (o_stdin_stdout_connector.has_value() && o_stdin_stderr_connector.has_value())
			{
				stdin_stdout_connector = o_stdin_stdout_connector.value();
				stdin_stdout_connector->enable_debug();

				stdin_stderr_connector = o_stdin_stderr_connector.value();
				stdin_stderr_connector->enable_debug();

				running = true;
			}
		}
	}

	void ConsoleTest::stop_test()
	{
		if (running)
		{
			connector_manager->delete_connector(stdin_stderr_connector);
			connector_manager->delete_connector(stdin_stdout_connector);
			running = false;
		}
	}

}
}
