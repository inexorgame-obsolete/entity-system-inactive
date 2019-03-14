#include "LogicalFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	LogicalFactories::LogicalFactories(
		ComparisonFactoriesPtr comparison_factories,
		GateFactoriesPtr gate_factories
	)
	{
		this->comparison_factories = comparison_factories;
		this->gate_factories = gate_factories;
	}

	LogicalFactories::~LogicalFactories()
	{
	}

	void LogicalFactories::init()
	{
		comparison_factories->init();
		gate_factories->init();
	}

}
}
}
