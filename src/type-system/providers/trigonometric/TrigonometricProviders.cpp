#include "TrigonometricProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	TrigonometricProviders::TrigonometricProviders(
		CosEntityTypeProviderPtr cos_entity_type_provider,
		SinEntityTypeProviderPtr sin_entity_type_provider
	)
	{
		this->cos_entity_type_provider = cos_entity_type_provider;
		this->sin_entity_type_provider = sin_entity_type_provider;
	}

	TrigonometricProviders::~TrigonometricProviders()
	{
	}

	void TrigonometricProviders::init()
	{
	}

}
}
}
