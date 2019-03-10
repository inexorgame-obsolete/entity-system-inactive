#pragma once

#include "configuration/managers/ConfigurationManager.hpp"
#include "configuration/managers/CommandLineArgumentsConfigurationInitializer.hpp"
#include "configuration/managers/EnvVarConfigurationInitializer.hpp"
#include "configuration/managers/SystemConfigurationInitializer.hpp"

namespace inexor {
namespace configuration {

    /// Module Configuration
	class ConfigurationModule
	{
		using ConfigurationManangerPtr = std::shared_ptr<ConfigurationManager>;
		using CommandLineArgumentsConfigurationInitializerPtr = std::shared_ptr<CommandLineArgumentsConfigurationInitializer>;
		using EnvVarConfigurationInitializerPtr = std::shared_ptr<EnvVarConfigurationInitializer>;
		using SystemConfigurationInitializerPtr = std::shared_ptr<SystemConfigurationInitializer>;

		public:

			ConfigurationModule(
				ConfigurationManangerPtr configuration_manager,
				CommandLineArgumentsConfigurationInitializerPtr command_line_arguments_configuration_initializer,
				EnvVarConfigurationInitializerPtr env_var_configuration_initializer,
				SystemConfigurationInitializerPtr system_configuration_initializer
			);

			~ConfigurationModule();

			/// Initialization of the configuration module
			void init(int argc, char* argv[]);

		private:

			/// The configuration manager
			ConfigurationManangerPtr configuration_manager;

			/// The initializer for the command line arguments
			CommandLineArgumentsConfigurationInitializerPtr command_line_arguments_configuration_initializer;

			/// The initializer for environment variables
			EnvVarConfigurationInitializerPtr env_var_configuration_initializer;

			/// The initializer for system information
			SystemConfigurationInitializerPtr system_configuration_initializer;

	};

}
}
