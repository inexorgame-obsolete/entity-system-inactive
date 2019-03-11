#include "TrigonometricFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	TrigonometricFactories::TrigonometricFactories(
		SinFactoryPtr sin_factory,
		CosFactoryPtr cos_factory,
		TanFactoryPtr tan_factory
	)
	{
		this->sin_factory = sin_factory;
		this->cos_factory = cos_factory;
		this->tan_factory = tan_factory;
	}

	TrigonometricFactories::~TrigonometricFactories()
	{
	}

	void TrigonometricFactories::init()
	{
		sin_factory->init();
		cos_factory->init();
		tan_factory->init();
	}

}
}
}
