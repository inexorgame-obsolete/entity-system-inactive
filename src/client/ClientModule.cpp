#include "ClientModule.hpp"

#include <utility>

namespace inexor::client {

ClientModule::ClientModule(ClientLifecyclePtr client_lifecycle, InputModulePtr input_module, UserInterfaceModulePtr user_interface_module, RendererModulePtr renderer_module)
    : LifeCycleComponent(client_lifecycle, audio_module, input_module, user_interface_module, renderer_module)
{
    this->client_lifecycle = std::move(client_lifecycle);
    this->input_module = std::move(input_module);
    this->user_interface_module = std::move(user_interface_module);
    this->renderer_module = std::move(renderer_module);
}

ClientModule::~ClientModule() = default;

void ClientModule::update()
{
    user_interface_module->update();
    renderer_module->update();
    input_module->update();
}

bool ClientModule::is_shutdown_requested()
{
    return client_lifecycle->is_shutdown_requested();
}

bool ClientModule::is_restart_requested()
{
    return client_lifecycle->is_restart_requested();
}

std::string ClientModule::get_component_name()
{
    return "ClientModule";
}

} // namespace inexor::client
