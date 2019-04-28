#include "ClientModule.hpp"

namespace inexor {
namespace client {

	ClientModule::ClientModule(
		ClientLifecyclePtr client_lifecycle,
		AudioModulePtr audio_module,
		InputModulePtr input_module,
		RendererModulePtr renderer_module
	)
	{
		this->client_lifecycle = client_lifecycle;
		this->audio_module = audio_module;
		this->input_module = input_module;
		this->renderer_module = renderer_module;
	}

	ClientModule::~ClientModule()
	{
	}

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
		audio_module->update();
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

}
}
