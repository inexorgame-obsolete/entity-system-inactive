#pragma once

#include "type-system/providers/inout/logger/LoggerEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using LoggerEntityTypeProviderPtr = std::shared_ptr<LoggerEntityTypeProvider>;

    /// @class LoggerProviders
	/// @brief The logger entity type providers.
	class LoggerProviders
	{
		public:

			/// @brief Constructs the logger entity type providers.
            /// @note The dependencies of this class will be injected automatically.
            /// @param logger_entity_type_provider The entity type LOGGER.
			LoggerProviders(
				LoggerEntityTypeProviderPtr logger_entity_type_provider
			);

            /// Destructor.
			~LoggerProviders();

			/// Initializes the logger entity type providers.
			void init();

		private:

			/// Provides the entity type LOGGER.
			LoggerEntityTypeProviderPtr logger_entity_type_provider;

	};

}
}
}
