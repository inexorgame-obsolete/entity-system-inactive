#pragma once

#include "configuration/managers/ConfigurationManager.hpp"
#include "configuration/managers/CommandLineArgumentsConfigurationInitializer.hpp"
#include "configuration/managers/EnvVarConfigurationInitializer.hpp"
#include "configuration/managers/SystemConfigurationInitializer.hpp"

namespace inexor {
namespace configuration {

    /// @class ConfigurationModule
    /// @brief Module Configuration.
	class ConfigurationModule
	{
		using ConfigurationManangerPtr = std::shared_ptr<ConfigurationManager>;
		using CommandLineArgumentsConfigurationInitializerPtr = std::shared_ptr<CommandLineArgumentsConfigurationInitializer>;
		using EnvVarConfigurationInitializerPtr = std::shared_ptr<EnvVarConfigurationInitializer>;
		using SystemConfigurationInitializerPtr = std::shared_ptr<SystemConfigurationInitializer>;

		public:

            /// @brief Constructor.
            /// @note The dependencies of this class will be injected automatically.
            /// @param configuration_manager The configuration manager.
            /// @param command_line_arguments_configuration_initializer The initializer for the command line arguments.
            /// @param env_var_configuration_initializer The initializer for environment variables.
            /// @param system_configuration_initializer The initializer for system information.
			ConfigurationModule(
				ConfigurationManangerPtr configuration_manager,
				CommandLineArgumentsConfigurationInitializerPtr command_line_arguments_configuration_initializer,
				EnvVarConfigurationInitializerPtr env_var_configuration_initializer,
				SystemConfigurationInitializerPtr system_configuration_initializer
			);

            /// Destructor.
			~ConfigurationModule();

			/// Initialization of the configuration module
            /// @param argc The total number of parameters given to the application.
            /// @param argv An array of parameters given to the application.
			void init(int argc, char* argv[]);

		private:

			/// The configuration manager.
			ConfigurationManangerPtr configuration_manager;

			/// The initializer for the command line arguments.
			CommandLineArgumentsConfigurationInitializerPtr command_line_arguments_configuration_initializer;

			/// The initializer for environment variables.
			EnvVarConfigurationInitializerPtr env_var_configuration_initializer;

			/// The initializer for system information.
			SystemConfigurationInitializerPtr system_configuration_initializer;

	};

}
}
