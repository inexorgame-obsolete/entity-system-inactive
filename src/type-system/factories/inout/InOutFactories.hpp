#pragma once

#include "type-system/factories/inout/logger/LoggerFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using LoggerFactoriesPtr = std::shared_ptr<LoggerFactories>;

	/// The factories for input and output.
	class InOutFactories
	{
		public:

			/// Constructs the factories for input and output.
			InOutFactories(
				LoggerFactoriesPtr logger_factories
			);

			~InOutFactories();

			/// Initializes the factories for input and output.
			void init();

		private:

			/// The factories for loggers.
			LoggerFactoriesPtr logger_factories;

	};

}
}
}
