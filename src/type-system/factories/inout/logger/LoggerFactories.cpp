#include "LoggerFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	LoggerFactories::LoggerFactories(
		LoggerFactoryPtr logger_factory
	)
	{
		this->logger_factory = logger_factory;
	}

	LoggerFactories::~LoggerFactories()
	{
	}

	void LoggerFactories::init()
	{
		logger_factory->init();
	}

}
}
}
