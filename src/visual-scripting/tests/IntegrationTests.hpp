#pragma once

#include "visual-scripting/tests/ConsoleTest.hpp"
#include "visual-scripting/tests/IntConstantConnectorTest.hpp"
#include "visual-scripting/tests/SinTest.hpp"

namespace inexor {
namespace visual_scripting {

	using ConsoleTestPtr = std::shared_ptr<ConsoleTest>;
	using IntConstantConnectorTestPtr = std::shared_ptr<IntConstantConnectorTest>;
	using SinTestPtr = std::shared_ptr<SinTest>;

    /// The integration tests.
	class IntegrationTests
	{
		public:

			/// Constructs the integration tests
			IntegrationTests(
				ConsoleTestPtr console_test,
				IntConstantConnectorTestPtr int_constant_connector_test,
				SinTestPtr sin_test
			);

			~IntegrationTests();

			/// Initialization of the integration tests.
			void init();

		private:

			/// The test case for CONSOLE_STDIN and CONSOLE_STDOUT.
			ConsoleTestPtr console_test;

			/// The test case for connecting INT_CONSTANTs.
			IntConstantConnectorTestPtr int_constant_connector_test;

			/// The test case for SIN.
			SinTestPtr sin_test;

	};

}
}
