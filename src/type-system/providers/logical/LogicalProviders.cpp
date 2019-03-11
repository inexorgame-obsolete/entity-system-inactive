#include "LogicalProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	LogicalProviders::LogicalProviders(
		NotEntityTypeProviderPtr not_entity_type_provider
	)
	{
		this->not_entity_type_provider = not_entity_type_provider;
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
