#pragma once

#include "ConfigurationManager.hpp"

#include <string>

//#define BETTER_ENUMS_DEFAULT_CONSTRUCTOR(Enum) \
//  public:                                      \
//    Enum() = default;

#include <better-enums/enum.h>

namespace inexor {
namespace configuration {

	/// The environment variables to import
	BETTER_ENUM(EnvironmentVariables, int, DISPLAY = 0, SHELL, PATH, USERNAME, DESKTOP_SESSION, GDK_BACKEND, USER, PWD, HOME, LANGUAGE, LANG)

	using ConfigurationManagerPtr = std::shared_ptr<ConfigurationManager>;

	/// Initializes the environment variables as configuration items.
	class EnvVarConfigurationInitializer
	{

		public:

			EnvVarConfigurationInitializer(
				ConfigurationManagerPtr configuration_manager
			);

			~EnvVarConfigurationInitializer();

			/// Initialization
			void init();

			/// Creates a configuration item for the environment variable
			void set_by_env_var(std::string env_name);

		private:

			/// The configuration manager
			ConfigurationManagerPtr configuration_manager;

			/// Returns the value of the environment variable if exists or nullopt
			std::optional<std::string> get_env_var(std::string const& env_name);

//			/// The name of the output attribute int_constant_value
//			static constexpr char ENVIRONMENT_VARIABLES[11][] = {
//				"DISPLAY",
//				"LC_TIME",
//				"SHELL",
//				"PATH",
//				"USERNAME",
//				"DESKTOP_SESSION",
//				"GDK_BACKEND",
//				"USER",
//				"PWD",
//				"HOME",
//				"LANGUAGE",
//				"LANG"
//			};

	};

}
}
