#pragma once

#include "base/LifeCycleComponent.hpp"
#include "ClientLifecycle.hpp"
#include "input/InputModule.hpp"
#include "renderer/RendererModule.hpp"
#include "ui/UserInterfaceModule.hpp"

namespace inexor::client {

/// @class ClientModule
/// @brief This module contains all modules for the Inexor Client.
class ClientModule : public LifeCycleComponent
{
    using ClientLifecyclePtr = std::shared_ptr<ClientLifecycle>;
    using InputModulePtr = std::shared_ptr<input::InputModule>;
    using UserInterfaceModulePtr = std::shared_ptr<ui::UserInterfaceModule>;
    using RendererModulePtr = std::shared_ptr<renderer::RendererModule>;

    public:
    /// @brief Constructor.
    /// @param audio_module The audio module.
    /// @param input_module The input module.
    /// @param renderer_module The renderer module.
    ClientModule(ClientLifecyclePtr client_lifecycle, InputModulePtr input_module, UserInterfaceModulePtr user_interface_module, RendererModulePtr renderer_module);

    /// Destructor.
    ~ClientModule();

    /// Update the client module.
    void update();

    /// Returns true, if the application should be shut down.
    bool is_shutdown_requested();

    /// Returns true, if the application should be restarted.
    bool is_restart_requested();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The client lifecycle.
    ClientLifecyclePtr client_lifecycle;

    /// The input module.
    InputModulePtr input_module;

    /// The user interface module.
    UserInterfaceModulePtr user_interface_module;

    /// The renderer module.
    RendererModulePtr renderer_module;
};

} // namespace inexor::client
