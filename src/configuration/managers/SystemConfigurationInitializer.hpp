#pragma once

#include "ConfigurationManager.hpp"

#include <memory>

namespace inexor {
namespace configuration {

	using ConfigurationManagerPtr = std::shared_ptr<ConfigurationManager>;

    /// @class SystemConfigurationInitializer
	/// @brief Initializes the environment variables as configuration items.
	class SystemConfigurationInitializer
	{

		public:

            /// @brief Constructor.
            /// @note The dependencies of this class will be injected automatically.
            /// @param configuration_manager The configuration manager.
			SystemConfigurationInitializer(
				ConfigurationManagerPtr configuration_manager
			);

            /// Destructor.
			~SystemConfigurationInitializer();

			/// Initialization.
			void init();

		private:

			/// The configuration manager.
			ConfigurationManagerPtr configuration_manager;

	};

}
}
