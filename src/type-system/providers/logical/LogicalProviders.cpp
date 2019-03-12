#include "LogicalProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	LogicalProviders::LogicalProviders(
		NotEntityTypeProviderPtr not_entity_type_provider,
		OrEntityTypeProviderPtr or_entity_type_provider,
		AndEntityTypeProviderPtr and_entity_type_provider,
		XorEntityTypeProviderPtr xor_entity_type_provider,
		NorEntityTypeProviderPtr nor_entity_type_provider,
		NandEntityTypeProviderPtr nand_entity_type_provider
	)
	{
		this->not_entity_type_provider = not_entity_type_provider;
		this->or_entity_type_provider = or_entity_type_provider;
		this->and_entity_type_provider = and_entity_type_provider;
		this->xor_entity_type_provider = xor_entity_type_provider;
		this->nor_entity_type_provider = nor_entity_type_provider;
		this->nand_entity_type_provider = nand_entity_type_provider;
	}

	LogicalProviders::~LogicalProviders()
	{
	}

	void LogicalProviders::init()
	{
	}

}
}
}
