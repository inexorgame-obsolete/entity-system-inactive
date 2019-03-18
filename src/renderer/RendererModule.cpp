#include "RendererModule.hpp"

namespace inexor {
namespace renderer {

	RendererModule::RendererModule(
		RendererManagerPtr renderer_manager
	)
	{
		this->renderer_manager = renderer_manager;
	}

	RendererModule::~RendererModule()
	{
	}

	void RendererModule::init()
	{
		renderer_manager->init();
	}

}
}
