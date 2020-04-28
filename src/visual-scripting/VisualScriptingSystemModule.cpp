#include <visual-scripting/VisualScriptingSystemModule.hpp>

#include <utility>

namespace inexor::visual_scripting {

VisualScriptingSystemModule::VisualScriptingSystemModule(ConnectorManagerPtr connector_manager, ProcessorsPtr processors)
    : LifeCycleComponent(connector_manager, processors)
{
    this->connector_manager = std::move(connector_manager);
    this->processors = std::move(processors);
}

VisualScriptingSystemModule::~VisualScriptingSystemModule() = default;

std::string VisualScriptingSystemModule::get_component_name()
{
    return "VisualScriptingSystemModule";
}

} // namespace inexor::visual_scripting
