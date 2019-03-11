#pragma once

#include "visual-scripting/managers/ConnectorManager.hpp"
#include "visual-scripting/processors/Processors.hpp"
#include "visual-scripting/tests/IntegrationTests.hpp"

namespace inexor {
namespace visual_scripting {

	using ConnectorManagerPtr = std::shared_ptr<ConnectorManager>;
	using ProcessorsPtr = std::shared_ptr<Processors>;
	using IntegrationTestsPtr = std::shared_ptr<IntegrationTests>;

    /// This module provides the visual scripting system.
	class VisualScriptingSystemModule
	{
		public:

			/// Constructs the visual scripting system.
			VisualScriptingSystemModule(
				ConnectorManagerPtr connector_manager,
				ProcessorsPtr processors,
				IntegrationTestsPtr integration_tests
			);

			~VisualScriptingSystemModule();

			/// Initializes the visual scripting system.
			void init();

		private:

			/// Manages the connections between attribute instances.
			ConnectorManagerPtr connector_manager;

			/// The processors.
			ProcessorsPtr processors;

			/// The integration tests.
			IntegrationTestsPtr integration_tests;

	};

}
}
