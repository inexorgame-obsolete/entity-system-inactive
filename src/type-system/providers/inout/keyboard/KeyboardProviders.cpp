#include "KeyboardProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	KeyboardProviders::KeyboardProviders(
		GlobalKeyEntityTypeProviderPtr global_key_entity_type_provider
	)
	{
		this->global_key_entity_type_provider = global_key_entity_type_provider;
	}

	KeyboardProviders::~KeyboardProviders()
	{
	}

	void KeyboardProviders::init()
	{
	}

}
}
}
