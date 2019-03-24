#include "LogicTest.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "visual-scripting/model/Connector.hpp"

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Observer.h"

#include <chrono>
#include <iostream>
#include <thread>

namespace inexor {
namespace visual_scripting {

	LogicTest::LogicTest(
		ConnectorManagerPtr connector_manager,
		StdInEntityTypeProviderPtr stdin_entity_type_provider,
		EqualsStringFactoryPtr equals_string_factory,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
	)
	{
		this->running = false;
        this->connector_manager = connector_manager;
        this->stdin_entity_type_provider = stdin_entity_type_provider;
        this->equals_string_factory = equals_string_factory;
        this->entity_instance_builder_factory = entity_instance_builder_factory;
	}

	
	LogicTest::~LogicTest()
	{
	}

	void LogicTest::init()
	{
	}

	void LogicTest::start_test()
	{
		if(!running)
		{
			std::thread t(&inexor::visual_scripting::LogicTest::run_test, this);
			t.detach();
		}
	}

	void LogicTest::stop_test()
	{
		if(running)
		{
			running = false;
		}
	}

	void LogicTest::run_test()
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
		running = true;
/*
		auto system = system();
		using ref = system->ref;
		auto b = builder(system)
			.stdin()
				.output(ref("stdin"))
				.done()
			.equals_str()
				.input1(ref("stdin"))
				.input2("")
				.output(ref("cmd1"))
				.done()
			.equals_str()
				.done()
			.and(ref("cmd1"), )
				.input()
				.output(ref("cmd1"))
				.done();
			.done();
*/
	}

}
}
