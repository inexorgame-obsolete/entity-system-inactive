#include "InOutFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	InOutFactories::InOutFactories(
		KeyboardFactoriesPtr keyboard_factories,
		LoggerFactoriesPtr logger_factories
	)
	{
		this->keyboard_factories = keyboard_factories;
		this->logger_factories = logger_factories;
	}

	InOutFactories::~InOutFactories()
	{
	}

	void InOutFactories::init()
	{
		keyboard_factories->init();
		logger_factories->init();
	}

	KeyboardFactoriesPtr InOutFactories::get_keyboard_factories()
	{
		return keyboard_factories;
	}

}
}
}
