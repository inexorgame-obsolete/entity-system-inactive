#include "VisualScriptingSystemModule.hpp"

namespace inexor {
namespace visual_scripting {


	VisualScriptingSystemModule::VisualScriptingSystemModule(
		ConnectorManagerPtr connector_manager,
		ProcessorsPtr processors,
		IntConstantConnectorTestPtr int_constant_connector_test,
		SinTestPtr sin_test
	)
	{
        this->connector_manager = connector_manager;
        this->processors = processors;
        this->int_constant_connector_test = int_constant_connector_test;
        this->sin_test = sin_test;
	}

	
	VisualScriptingSystemModule::~VisualScriptingSystemModule()
	{
	}

	void VisualScriptingSystemModule::init()
	{
		connector_manager->init();
		processors->init();
		int_constant_connector_test->init();
		sin_test->init();
	}

}
}
