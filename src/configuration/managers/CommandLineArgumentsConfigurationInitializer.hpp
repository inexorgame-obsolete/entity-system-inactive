#pragma once

#include "ConfigurationManager.hpp"

#include <memory>

namespace inexor {
namespace configuration {

	using ConfigurationManagerPtr = std::shared_ptr<ConfigurationManager>;

	/// Initializes the environment variables as configuration items.
	class CommandLineArgumentsConfigurationInitializer
	{

		public:

			CommandLineArgumentsConfigurationInitializer(
				ConfigurationManagerPtr configuration_manager
			);

			~CommandLineArgumentsConfigurationInitializer();

			/// Initialization
			void init(int argc, char* argv[]);

		private:

			/// The configuration manager
			ConfigurationManagerPtr configuration_manager;

	};

}
}
