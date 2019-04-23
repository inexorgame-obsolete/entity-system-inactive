#include "MouseFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	MouseFactories::MouseFactories(
		GlobalMouseButtonFactoryPtr global_mouse_button_factory
	)
	{
		this->global_mouse_button_factory = global_mouse_button_factory;
	}

	MouseFactories::~MouseFactories()
	{
	}

	void MouseFactories::init()
	{
		global_mouse_button_factory->init();
	}

	GlobalMouseButtonFactoryPtr MouseFactories::get_global_mouse_button_factory()
	{
		return global_mouse_button_factory;
	}

}
}
}
