#pragma once

#include "visual-scripting/tests/ConsoleTest.hpp"
#include "visual-scripting/tests/IntConstantConnectorTest.hpp"
#include "visual-scripting/tests/SinTest.hpp"
#include "visual-scripting/tests/LogicTest.hpp"

namespace inexor {
namespace visual_scripting {

	using ConsoleTestPtr = std::shared_ptr<ConsoleTest>;
	using IntConstantConnectorTestPtr = std::shared_ptr<IntConstantConnectorTest>;
	using SinTestPtr = std::shared_ptr<SinTest>;
	using LogicTestPtr = std::shared_ptr<LogicTest>;

    /// @class IntegrationTests
    /// @brief The integration tests.
	class IntegrationTests
	{
		public:

			/// @brief Constructs the integration tests
            /// @note The dependencies of this class will be injected automatically.
            /// @param console_test The test case for CONSOLE_STDIN and CONSOLE_STDOUT.
            /// @param int_constant_connector_test The test case for connecting INT_CONSTANTs.
            /// @param sin_test The test case for SIN.
            /// @param logic_test The test case for logical operations.
			IntegrationTests(
				ConsoleTestPtr console_test,
				IntConstantConnectorTestPtr int_constant_connector_test,
				SinTestPtr sin_test,
				LogicTestPtr logic_test
			);

            /// Destructor.
			~IntegrationTests();

			/// Initialization of the integration tests.
			void init();

			/// Starts the integration tests.
			void start_tests();

			/// Stops the integration tests.
			void stop_tests();

		private:

			/// The test case for CONSOLE_STDIN and CONSOLE_STDOUT.
			ConsoleTestPtr console_test;

			/// The test case for connecting INT_CONSTANTs.
			IntConstantConnectorTestPtr int_constant_connector_test;

			/// The test case for SIN.
			SinTestPtr sin_test;

			/// The test case for logical operations.
			LogicTestPtr logic_test;

	};

}
}
