#pragma once

#include "ConfigurationManager.hpp"

#include <memory>

namespace inexor {
namespace configuration {

	using ConfigurationManagerPtr = std::shared_ptr<ConfigurationManager>;

	/// @class CommandLineArgumentsConfigurationInitializer
	/// @brief Initializes the environment variables as configuration items.
	class CommandLineArgumentsConfigurationInitializer

		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param configuration_manager The configuration manager.
			CommandLineArgumentsConfigurationInitializer(
			ConfigurationManagerPtr configuration_manager
			);

			/// Destructor.
			~CommandLineArgumentsConfigurationInitializer();

			/// Initialization.
			/// @param argc The total number of parameters given to the application.
			/// @param argv An array of parameters given to the application.
			void init(int argc, char* argv[]);

		private:

			/// The configuration manager.
			ConfigurationManagerPtr configuration_manager;

	};

}
}
