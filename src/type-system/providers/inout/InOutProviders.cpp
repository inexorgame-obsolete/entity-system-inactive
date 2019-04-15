#include "InOutProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	InOutProviders::InOutProviders(
		ConsoleProvidersPtr console_providers,
		KeyboardProvidersPtr keyboard_providers,
		MouseProvidersPtr mouse_providers,
		LoggerProvidersPtr logger_providers
	)
	{
		this->console_providers = console_providers;
		this->keyboard_providers = keyboard_providers;
		this->mouse_providers = mouse_providers;
		this->logger_providers = logger_providers;
	}

	InOutProviders::~InOutProviders()
	{
	}

	void InOutProviders::init()
	{
		console_providers->init();
		keyboard_providers->init();
		mouse_providers->init();
		logger_providers->init();
	}

}
}
}
