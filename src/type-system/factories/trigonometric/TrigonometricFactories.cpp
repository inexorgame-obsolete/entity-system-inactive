#include "TrigonometricFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	TrigonometricFactories::TrigonometricFactories(
		CosFactoryPtr cos_factory,
		SinFactoryPtr sin_factory
	)
	{
		this->cos_factory = cos_factory;
		this->sin_factory = sin_factory;
	}

	TrigonometricFactories::~TrigonometricFactories()
	{
	}

	void TrigonometricFactories::init()
	{
		cos_factory->init();
		sin_factory->init();
	}

}
}
}
