#pragma once

#include "type-system/factories/inout/keyboard/KeyboardFactories.hpp"
#include "type-system/factories/inout/logger/LoggerFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using KeyboardFactoriesPtr = std::shared_ptr<KeyboardFactories>;
	using LoggerFactoriesPtr = std::shared_ptr<LoggerFactories>;

    /// @class InOutFactories
	/// @brief The factories for input and output.
	class InOutFactories
	{
		public:

			/// @brief Constructs the factories for input and output.
            /// @note The dependencies of this class will be injected automatically.
            /// @param keyboard_factories The factories for keyboard input.
            /// @param logger_factories The factories for loggers.
			InOutFactories(
				KeyboardFactoriesPtr keyboard_factories,
				LoggerFactoriesPtr logger_factories
			);

            /// Destructor.
			~InOutFactories();

			/// Initializes the factories for input and output.
			void init();

			/// Returns the factories for keyboard input.
			KeyboardFactoriesPtr get_keyboard_factories();

		private:

			/// The factories for keyboard input.
			KeyboardFactoriesPtr keyboard_factories;

			/// The factories for loggers.
			LoggerFactoriesPtr logger_factories;

	};

}
}
}
