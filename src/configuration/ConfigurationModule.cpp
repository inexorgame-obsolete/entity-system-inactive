#include "ConfigurationModule.hpp"

namespace inexor {
namespace configuration {

	ConfigurationModule::ConfigurationModule(
		ConfigurationManangerPtr configuration_manager,
		CommandLineArgumentsConfigurationInitializerPtr command_line_arguments_configuration_initializer,
		EnvVarConfigurationInitializerPtr env_var_configuration_initializer,
		SystemConfigurationInitializerPtr system_configuration_initializer
	)
	{
		this->configuration_manager = configuration_manager;
		this->command_line_arguments_configuration_initializer = command_line_arguments_configuration_initializer;
		this->env_var_configuration_initializer = env_var_configuration_initializer;
		this->system_configuration_initializer = system_configuration_initializer;
	}

	ConfigurationModule::~ConfigurationModule()
	{
	}

	void ConfigurationModule::init(int argc, char* argv[])
	{
		configuration_manager->init();
		command_line_arguments_configuration_initializer->init(argc, argv);
		env_var_configuration_initializer->init();
		system_configuration_initializer->init();
		configuration_manager->list();
	}

}
}
