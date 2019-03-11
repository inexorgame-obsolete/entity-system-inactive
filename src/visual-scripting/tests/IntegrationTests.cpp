#include "IntegrationTests.hpp"

namespace inexor {
namespace visual_scripting {

	IntegrationTests::IntegrationTests(
		ConsoleTestPtr console_test,
		IntConstantConnectorTestPtr int_constant_connector_test,
		SinTestPtr sin_test
	)
	{
		this->console_test = console_test;
		this->int_constant_connector_test = int_constant_connector_test;
		this->sin_test = sin_test;
	}

	IntegrationTests::~IntegrationTests()
	{
	}

	void IntegrationTests::init()
	{
		this->console_test->init();
		this->int_constant_connector_test->init();
		this->sin_test->init();
	}

}
}
