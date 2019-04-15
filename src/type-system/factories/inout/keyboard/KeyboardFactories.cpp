#include "KeyboardFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	KeyboardFactories::KeyboardFactories(
		GlobalKeyFactoryPtr global_key_factory
	)
	{
		this->global_key_factory = global_key_factory;
	}

	KeyboardFactories::~KeyboardFactories()
	{
	}

	void KeyboardFactories::init()
	{
		global_key_factory->init();
	}

	GlobalKeyFactoryPtr KeyboardFactories::get_global_key_factory()
	{
		return global_key_factory;
	}

}
}
}
