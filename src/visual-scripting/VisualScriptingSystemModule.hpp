#pragma once

#include "visual-scripting/managers/ConnectorManager.hpp"
#include "visual-scripting/processors/Processors.hpp"
#include "visual-scripting/tests/IntConstantConnectorTest.hpp"
#include "visual-scripting/tests/SinTest.hpp"

namespace inexor {
namespace visual_scripting {

	using ConnectorManagerPtr = std::shared_ptr<ConnectorManager>;
	using ProcessorsPtr = std::shared_ptr<Processors>;
	using IntConstantConnectorTestPtr = std::shared_ptr<IntConstantConnectorTest>;
	using SinTestPtr = std::shared_ptr<SinTest>;

    /// This module provides the visual scripting system.
	class VisualScriptingSystemModule
	{
		public:

			/// Constructs the visual scripting system.
			VisualScriptingSystemModule(
				ConnectorManagerPtr connector_manager,
				ProcessorsPtr processors,
				IntConstantConnectorTestPtr int_constant_connector_test,
				SinTestPtr sin_test
			);

			~VisualScriptingSystemModule();

			/// Initializes the visual scripting system.
			void init();

		private:

			/// Manages the connections between attribute instances.
			ConnectorManagerPtr connector_manager;

			/// The processors.
			ProcessorsPtr processors;

			/// The test case for connecting INT_CONSTANTs.
			IntConstantConnectorTestPtr int_constant_connector_test;

			/// The test case for SIN.
			SinTestPtr sin_test;
	};

}
}
