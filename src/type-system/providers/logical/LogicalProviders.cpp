#include "LogicalProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	LogicalProviders::LogicalProviders(
		ComparisonProvidersPtr comparison_providers,
		GateProvidersPtr gate_providers
	)
	{
		this->comparison_providers = comparison_providers;
		this->gate_providers = gate_providers;
	}

	LogicalProviders::~LogicalProviders()
	{
	}

	void LogicalProviders::init()
	{
		comparison_providers->init();
		gate_providers->init();
	}

}
}
}
