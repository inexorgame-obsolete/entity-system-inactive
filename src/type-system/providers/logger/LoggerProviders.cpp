#include "LoggerProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	LoggerProviders::LoggerProviders(
		LoggerEntityTypeProviderPtr logger_entity_type_provider
	)
	{
		this->logger_entity_type_provider = logger_entity_type_provider;
	}

	LoggerProviders::~LoggerProviders()
	{
	}

	void LoggerProviders::init()
	{
	}

}
}
}
