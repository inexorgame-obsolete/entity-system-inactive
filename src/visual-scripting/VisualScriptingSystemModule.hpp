#pragma once

#include "visual-scripting/managers/ConnectorManager.hpp"
#include "visual-scripting/processors/Processors.hpp"
#ifdef INEXOR_WITH_INTEGRATION_TESTS
#include "visual-scripting/tests/IntegrationTests.hpp"
#endif

namespace inexor {
namespace visual_scripting {

	using ConnectorManagerPtr = std::shared_ptr<ConnectorManager>;
#ifdef INEXOR_WITH_INTEGRATION_TESTS
	using IntegrationTestsPtr = std::shared_ptr<IntegrationTests>;
#endif
	using ProcessorsPtr = std::shared_ptr<Processors>;

	/// @class VisualScriptingSystemModule
	/// @brief This module provides the visual scripting system.
	class VisualScriptingSystemModule
	{
		public:

			/// @brief Constructs the visual scripting system.
			/// @param connector_manager Manages the connections between attribute instances.
			/// @param processors The processors.
			/// @param integration_tests The integration tests.
			VisualScriptingSystemModule(
				ConnectorManagerPtr connector_manager,
				ProcessorsPtr processors
#ifdef INEXOR_WITH_INTEGRATION_TESTS
				, IntegrationTestsPtr integration_tests
#endif
			);

			/// Destructor.
			~VisualScriptingSystemModule();

			/// Initializes the visual scripting system.
			void init();

			/// Shut down the visual scripting system.
			void shutdown();

		private:

			/// Manages the connections between attribute instances.
			ConnectorManagerPtr connector_manager;

			/// The processors.
			ProcessorsPtr processors;

			/// The integration tests.
#ifdef INEXOR_WITH_INTEGRATION_TESTS
			IntegrationTestsPtr integration_tests;
#endif

	};

}
}
