#include "ClientModule.hpp"

#include <utility>

namespace inexor::client {

ClientModule::ClientModule(ClientLifecyclePtr client_lifecycle, AudioModulePtr audio_module, InputModulePtr input_module, RendererModulePtr renderer_module)
{
    this->client_lifecycle = std::move(client_lifecycle);
    this->audio_module = std::move(audio_module);
    this->input_module = std::move(input_module);
    this->renderer_module = std::move(renderer_module);
}

ClientModule::~ClientModule() = default;

void ClientModule::init()
{
    client_lifecycle->init();
    audio_module->init();
    input_module->init();
    renderer_module->init();
}

void ClientModule::shutdown()
{
    renderer_module->shutdown();
    input_module->shutdown();
    audio_module->shutdown();
    client_lifecycle->shutdown();
}

void ClientModule::update()
{
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

} // namespace inexor::client
