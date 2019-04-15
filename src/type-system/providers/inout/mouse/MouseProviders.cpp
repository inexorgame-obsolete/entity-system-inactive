#include "MouseProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	MouseProviders::MouseProviders(
		GlobalMouseButtonEntityTypeProviderPtr global_mouse_button_entity_type_provider
	)
	{
		this->global_mouse_button_entity_type_provider = global_mouse_button_entity_type_provider;
	}

	MouseProviders::~MouseProviders()
	{
	}

	void MouseProviders::init()
	{
	}

}
}
}
