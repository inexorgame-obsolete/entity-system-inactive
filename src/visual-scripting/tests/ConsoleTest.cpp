#include "ConsoleTest.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "visual-scripting/model/Connector.hpp"

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Observer.h"

#include <iostream>
#include <thread>
#include <type-system/types/inout/console/StdErr.hpp>
#include <type-system/types/inout/console/StdIn.hpp>
#include <type-system/types/inout/console/StdOut.hpp>
#include <utility>

namespace inexor::visual_scripting {

using StdErr = entity_system::type_system::StdErr;
    using StdIn = entity_system::type_system::StdIn;
    using StdOut = entity_system::type_system::StdOut;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;
	using ConnectorPtr = std::shared_ptr<Connector>;
	using ConnectorPtrOpt = std::optional<ConnectorPtr>;

	using DataType = entity_system::DataType;
	using DataValue = entity_system::DataValue;

	ConsoleTest::ConsoleTest(
		ConnectorManagerPtr connector_manager,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->running = false;
        this->connector_manager = std::move(connector_manager);
        this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
	}

	
	ConsoleTest::~ConsoleTest() = default;

	void ConsoleTest::init()
	{
		// Create single instance for STDIN
		o_stdin = entity_instance_builder_factory->get_builder(StdIn::TYPE_NAME)
			->attribute(StdIn::STDIN, std::string(""))
			->build();

		// Create single instance for STDOUT
		o_stdout = entity_instance_builder_factory->get_builder(StdOut::TYPE_NAME)
			->attribute(StdOut::STDOUT, std::string(""))
			->build();

		// Create single instance for STDERR
		o_stderr = entity_instance_builder_factory->get_builder(StdErr::TYPE_NAME)
			->attribute(StdErr::STDERR, std::string(""))
			->build();

	}

	void ConsoleTest::shutdown()
	{
		// TODO: shutdown this test
	}

	void ConsoleTest::start_test()
	{
		if(!running && o_stdin.has_value() && o_stdout.has_value() && o_stderr.has_value())
		{
			EntityAttributeInstancePtr stdin_value = o_stdin.value()->get_attribute_instance(StdIn::STDIN).value();

			ConnectorPtrOpt o_stdin_stdout_connector = connector_manager->create_connector(
				stdin_value,
				o_stdout.value()->get_attribute_instance(StdOut::STDOUT).value()
			);

			ConnectorPtrOpt o_stdin_stderr_connector = connector_manager->create_connector(
				stdin_value,
				o_stderr.value()->get_attribute_instance(StdErr::STDERR).value()
			);

			if(o_stdin_stdout_connector.has_value() && o_stdin_stderr_connector.has_value())
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
		if(running)
		{
			connector_manager->delete_connector(stdin_stderr_connector);
			connector_manager->delete_connector(stdin_stdout_connector);
			running = false;
		}
	}

}
