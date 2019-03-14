#include "InOutFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	InOutFactories::InOutFactories(
		LoggerFactoriesPtr logger_factories
	)
	{
		this->logger_factories = logger_factories;
	}

	InOutFactories::~InOutFactories()
	{
	}

	void InOutFactories::init()
	{
		logger_factories->init();
	}

}
}
}
