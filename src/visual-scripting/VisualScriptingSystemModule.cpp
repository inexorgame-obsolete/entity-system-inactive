#include "VisualScriptingSystemModule.hpp"

namespace inexor {
namespace visual_scripting {

	VisualScriptingSystemModule::VisualScriptingSystemModule(
		ConnectorManagerPtr connector_manager,
		ProcessorsPtr processors
#ifdef INEXOR_WITH_INTEGRATION_TESTS
		, IntegrationTestsPtr integration_tests
#endif
	)
	{
		this->connector_manager = connector_manager;
		this->processors = processors;
#ifdef INEXOR_WITH_INTEGRATION_TESTS
		this->integration_tests = integration_tests;
#endif
	}

	VisualScriptingSystemModule::~VisualScriptingSystemModule()
	{
	}

	void VisualScriptingSystemModule::init()
	{
		connector_manager->init();
		processors->init();
#ifdef INEXOR_WITH_INTEGRATION_TESTS
		integration_tests->init();
		integration_tests->start_tests();
#endif
	}

	void VisualScriptingSystemModule::shutdown()
	{
#ifdef INEXOR_WITH_INTEGRATION_TESTS
		integration_tests->stop_tests();
		// integration_tests->shutdown();
#endif
		processors->shutdown();
		// connector_manager->shutdown();
	}

}
}
