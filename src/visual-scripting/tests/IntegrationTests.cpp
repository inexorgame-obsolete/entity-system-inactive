#include "IntegrationTests.hpp"

namespace inexor {
namespace visual_scripting {

	IntegrationTests::IntegrationTests(
		ConsoleTestPtr console_test,
		IntConstantConnectorTestPtr int_constant_connector_test,
		SinTestPtr sin_test,
		LogicTestPtr logic_test
	)
	{
		this->console_test = console_test;
		this->int_constant_connector_test = int_constant_connector_test;
		this->sin_test = sin_test;
		this->logic_test = logic_test;
	}

	IntegrationTests::~IntegrationTests()
	{
	}

	void IntegrationTests::init()
	{
		this->console_test->init();
		this->int_constant_connector_test->init();
		this->sin_test->init();
		this->logic_test->init();
	}

	void IntegrationTests::shutdown()
	{
		this->logic_test->shutdown();
		this->sin_test->shutdown();
		this->int_constant_connector_test->shutdown();
		this->console_test->shutdown();
	}

	void IntegrationTests::start_tests()
	{
		this->console_test->start_test();
		this->int_constant_connector_test->start_test();
		this->sin_test->start_test();
		this->logic_test->start_test();
	}

	void IntegrationTests::stop_tests()
	{
		this->logic_test->stop_test();
		this->sin_test->stop_test();
		this->int_constant_connector_test->stop_test();
		this->console_test->stop_test();
	}

}
}
