#include "IntegrationTests.hpp"

namespace inexor {
namespace visual_scripting {

	IntegrationTests::IntegrationTests(
		IntConstantConnectorTestPtr int_constant_connector_test,
		SinTestPtr sin_test
	)
	{
		this->int_constant_connector_test = int_constant_connector_test;
		this->sin_test = sin_test;
	}

	IntegrationTests::~IntegrationTests()
	{
	}

	void IntegrationTests::init()
	{
		this->int_constant_connector_test->init();
		this->sin_test->init();
	}

}
}
