#pragma once

#include "ClientLifecycle.hpp"
#include "audio/AudioModule.hpp"
#include "input/InputModule.hpp"
#include "renderer/RendererModule.hpp"

namespace inexor::client {

/// @class ClientModule
/// @brief This module contains all modules for the Inexor Client.
class ClientModule
{
    using ClientLifecyclePtr = std::shared_ptr<ClientLifecycle>;
    using AudioModulePtr = std::shared_ptr<audio::AudioModule>;
    using InputModulePtr = std::shared_ptr<input::InputModule>;
    using RendererModulePtr = std::shared_ptr<renderer::RendererModule>;

    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param audio_module The audio module.
    /// @param input_module The input module.
    /// @param renderer_module The renderer module.
    ClientModule(ClientLifecyclePtr client_lifecycle, AudioModulePtr audio_module, InputModulePtr input_module, RendererModulePtr renderer_module);

    /// Destructor.
    ~ClientModule();

    /// Initialization of the client module.
    void init();

    /// Shut down the client module.
    void shutdown();

    /// Update the client module.
    void update();

    /// Returns true, if the application should be shut down.
    bool is_shutdown_requested();

    /// Returns true, if the application should be restarted.
    bool is_restart_requested();

    private:
    /// The client lifecycle.
    ClientLifecyclePtr client_lifecycle;

    /// The audio module.
    AudioModulePtr audio_module;

    /// The input module.
    InputModulePtr input_module;

    /// The renderer module.
    RendererModulePtr renderer_module;
};

} // namespace inexor::client
