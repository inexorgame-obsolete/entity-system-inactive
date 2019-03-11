#include "VisualScriptingSystemModule.hpp"

namespace inexor {
namespace visual_scripting {

	VisualScriptingSystemModule::VisualScriptingSystemModule(
		ConnectorManagerPtr connector_manager,
		ProcessorsPtr processors,
		IntegrationTestsPtr integration_tests
	)
	{
        this->connector_manager = connector_manager;
        this->processors = processors;
        this->integration_tests = integration_tests;
	}

	VisualScriptingSystemModule::~VisualScriptingSystemModule()
	{
	}

	void VisualScriptingSystemModule::init()
	{
		connector_manager->init();
		processors->init();
		integration_tests->init();
	}

}
}
