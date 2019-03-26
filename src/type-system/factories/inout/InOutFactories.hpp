#pragma once

#include "type-system/factories/inout/logger/LoggerFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using LoggerFactoriesPtr = std::shared_ptr<LoggerFactories>;

    /// @class InOutFactories
	/// @brief The factories for input and output.
	class InOutFactories
	{
		public:

			/// @brief Constructs the factories for input and output.
            /// @note The dependencies of this class will be injected automatically.
            /// @param logger_factories The factories for loggers.
			InOutFactories(
				LoggerFactoriesPtr logger_factories
			);

            /// Destructor.
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
