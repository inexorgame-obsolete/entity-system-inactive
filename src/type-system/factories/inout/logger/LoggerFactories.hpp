#pragma once

#include "type-system/factories/inout/logger/LoggerFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using LoggerFactoryPtr = std::shared_ptr<LoggerFactory>;

	/// The logger factories.
	class LoggerFactories
	{
		public:

			/// Constructs the logger factories.
			LoggerFactories(
				LoggerFactoryPtr logger_factory
			);

			~LoggerFactories();

			/// Initializes the logger factories.
			void init();

		private:

			/// Factory for creating entity instances of type LOGGER.
			LoggerFactoryPtr logger_factory;

	};

}
}
}
