#include "LogicalFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	LogicalFactories::LogicalFactories(
		NotFactoryPtr not_factory
	)
	{
		this->not_factory = not_factory;
	}

	LogicalFactories::~LogicalFactories()
	{
	}

	void LogicalFactories::init()
	{
		not_factory->init();
	}

}
}
}
