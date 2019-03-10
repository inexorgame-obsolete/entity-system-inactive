#include "ArithmeticProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	ArithmeticProviders::ArithmeticProviders(
		AddIntEntityTypeProviderPtr add_int_entity_type_provider
	)
	{
		this->add_int_entity_type_provider = add_int_entity_type_provider;
	}

	ArithmeticProviders::~ArithmeticProviders()
	{
	}

	void ArithmeticProviders::init()
	{
	}

}
}
}
