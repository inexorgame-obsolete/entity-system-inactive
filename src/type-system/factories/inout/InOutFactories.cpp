#include "InOutFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	InOutFactories::InOutFactories(
		KeyboardFactoriesPtr keyboard_factories,
		MouseFactoriesPtr mouse_factories,
		LoggerFactoriesPtr logger_factories
	)
	{
		this->keyboard_factories = keyboard_factories;
		this->mouse_factories = mouse_factories;
		this->logger_factories = logger_factories;
	}

	InOutFactories::~InOutFactories()
	{
	}

	void InOutFactories::init()
	{
		keyboard_factories->init();
		mouse_factories->init();
		logger_factories->init();
	}

	KeyboardFactoriesPtr InOutFactories::get_keyboard_factories()
	{
		return keyboard_factories;
	}

	MouseFactoriesPtr InOutFactories::get_mouse_factories()
	{
		return mouse_factories;
	}

}
}
}
