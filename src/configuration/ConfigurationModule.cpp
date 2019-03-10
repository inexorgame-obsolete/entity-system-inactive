#include "ConfigurationModule.hpp"

namespace inexor {
namespace configuration {

	ConfigurationModule::ConfigurationModule(
		ConfigurationManangerPtr configuration_manager,
		EnvVarConfigurationInitializerPtr env_var_configuration_initializer
	)
	{
		this->configuration_manager = configuration_manager;
		this->env_var_configuration_initializer = env_var_configuration_initializer;
	}

	ConfigurationModule::~ConfigurationModule()
	{
	}

	void ConfigurationModule::init()
	{
		configuration_manager->init();
		env_var_configuration_initializer->init();
		configuration_manager->list();
	}

}
}
