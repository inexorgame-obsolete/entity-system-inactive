#pragma once

#include "visual-scripting/managers/ConnectorManager.hpp"
#include "visual-scripting/processors/Processors.hpp"

namespace inexor::visual_scripting {

using ConnectorManagerPtr = std::shared_ptr<ConnectorManager>;
using ProcessorsPtr = std::shared_ptr<Processors>;

/// @class VisualScriptingSystemModule
/// @brief This module provides the visual scripting system.
class VisualScriptingSystemModule : public LifeCycleComponent
{
    public:
    /// @brief Constructs the visual scripting system.
    /// @note The dependencies of this class will be injected automatically.
    /// @param connector_manager Manages the connections between attribute instances.
    /// @param processors The processors.
    VisualScriptingSystemModule(ConnectorManagerPtr connector_manager, ProcessorsPtr processors);

    /// Destructor.
    ~VisualScriptingSystemModule();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Manages the connections between attribute instances.
    ConnectorManagerPtr connector_manager;

    /// The processors.
    ProcessorsPtr processors;
};

} // namespace inexor::visual_scripting
