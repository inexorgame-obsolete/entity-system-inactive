#include "ClientModule.hpp"

namespace inexor {
namespace client {

	ClientModule::ClientModule(
		AudioModulePtr audio_module,
		InputModulePtr input_module,
		RendererModulePtr renderer_module
	)
	{
		this->audio_module = audio_module;
		this->input_module = input_module;
		this->renderer_module = renderer_module;
	}

	ClientModule::~ClientModule()
	{
	}

	void ClientModule::init()
	{
		audio_module->init();
		input_module->init();
		renderer_module->init();
	}

	void ClientModule::shutdown()
	{
		renderer_module->shutdown();
		input_module->shutdown();
		audio_module->shutdown();
	}

	void ClientModule::update()
	{
		renderer_module->update();
	}

	bool ClientModule::shall_shutdown()
	{
		if (renderer_module->get_window_manager()->get_window_count() == 0)
		{
			spdlog::info("Last window closed");
			return true;
		} else {
			return false;
		}
	}

}
}
