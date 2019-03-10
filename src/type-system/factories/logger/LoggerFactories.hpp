#pragma once

#include "type-system/factories/logger/LoggerFactory.hpp"

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
				LoggerFactoryPtr int_to_float_factory
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
