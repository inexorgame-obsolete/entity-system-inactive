#pragma once

#include "configuration/managers/ConfigurationManager.hpp"
#include "configuration/managers/EnvVarConfigurationInitializer.hpp"

namespace inexor {
namespace configuration {

    /// Module Configuration
	class ConfigurationModule
	{
		using ConfigurationManangerPtr = std::shared_ptr<ConfigurationManager>;
		using EnvVarConfigurationInitializerPtr = std::shared_ptr<EnvVarConfigurationInitializer>;

		public:

			ConfigurationModule(
				ConfigurationManangerPtr configuration_manager,
				EnvVarConfigurationInitializerPtr env_var_configuration_initializer
			);

			~ConfigurationModule();

			/// Initialization of the configuration module
			void init();

		private:

			/// The configuration manager
			ConfigurationManangerPtr configuration_manager;

			/// The initializer for environment variables
			EnvVarConfigurationInitializerPtr env_var_configuration_initializer;

	};

}
}
