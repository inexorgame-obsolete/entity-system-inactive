#pragma once

#include "type-system/providers/logger/LoggerEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using LoggerEntityTypeProviderPtr = std::shared_ptr<LoggerEntityTypeProvider>;

	/// The logger entity type providers.
	class LoggerProviders
	{
		public:

			/// Constructs the logger entity type providers.
			LoggerProviders(
				LoggerEntityTypeProviderPtr logger_entity_type_provider
			);

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
