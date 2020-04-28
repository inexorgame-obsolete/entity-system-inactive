#include <configuration/ConfigurationModule.hpp>

#include <utility>

namespace inexor::configuration {

ConfigurationModule::ConfigurationModule(ConfigurationManangerPtr configuration_manager, CommandLineArgumentsConfigurationInitializerPtr command_line_arguments_configuration_initializer,
                                         EnvVarConfigurationInitializerPtr env_var_configuration_initializer, SystemConfigurationInitializerPtr system_configuration_initializer)
{
    this->configuration_manager = std::move(configuration_manager);
    this->command_line_arguments_configuration_initializer = std::move(command_line_arguments_configuration_initializer);
    this->env_var_configuration_initializer = std::move(env_var_configuration_initializer);
    this->system_configuration_initializer = std::move(system_configuration_initializer);
}

ConfigurationModule::~ConfigurationModule() = default;

void ConfigurationModule::init(int argc, char *argv[])
{
    configuration_manager->init();
    command_line_arguments_configuration_initializer->init(argc, argv);
    env_var_configuration_initializer->init();
    system_configuration_initializer->init();
    configuration_manager->list();
}

} // namespace inexor::configuration
