#include "VisualScriptingSystemModule.hpp"

#include <utility>

namespace inexor::visual_scripting {

VisualScriptingSystemModule::VisualScriptingSystemModule(ConnectorManagerPtr connector_manager, ProcessorsPtr processors, IntegrationTestsPtr integration_tests)
{
    this->connector_manager = std::move(connector_manager);
    this->processors = std::move(processors);
    this->integration_tests = std::move(integration_tests);
}

VisualScriptingSystemModule::~VisualScriptingSystemModule() = default;

void VisualScriptingSystemModule::init()
{
    connector_manager->init();
    processors->init();
    integration_tests->init();
    integration_tests->start_tests();
}

void VisualScriptingSystemModule::shutdown()
{
    integration_tests->stop_tests();
    // integration_tests->shutdown();
    processors->shutdown();
    // connector_manager->shutdown();
}

} // namespace inexor::visual_scripting
