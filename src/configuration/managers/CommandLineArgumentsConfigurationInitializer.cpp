#include "CommandLineArgumentsConfigurationInitializer.hpp"

#include <fmt/format.h>

namespace inexor {
namespace configuration {

	CommandLineArgumentsConfigurationInitializer::CommandLineArgumentsConfigurationInitializer(
		ConfigurationManagerPtr configuration_manager
	)
	{
		this->configuration_manager = configuration_manager;
	}

	CommandLineArgumentsConfigurationInitializer::~CommandLineArgumentsConfigurationInitializer()
	{
	}

	void CommandLineArgumentsConfigurationInitializer::init(int argc, char* argv[])
	{
		configuration_manager->set("CMD_ARGC", argc);
		for (int i = 0; i < argc; i++)
		{
			std::string config_name = fmt::format("CMD_ARGV_{}", i);
			std::string config_value = std::string(argv[i]);
			configuration_manager->set(config_name, config_value);
		}
	}


}
}

