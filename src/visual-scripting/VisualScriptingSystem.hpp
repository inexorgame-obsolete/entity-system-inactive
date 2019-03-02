// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <iostream>

#include "type-system/factories/constants/IntConstantFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"
#include "visual-scripting/managers/ProcessorManager.hpp"
#include "visual-scripting/tests/IntConstantConnectorTest.hpp"
#include "visual-scripting/tests/SinTest.hpp"


namespace inexor {
namespace visual_scripting {


	/// @class VisualScriptingSystem
    /// @brief Visual scripting system main class.
	class VisualScriptingSystem
	{
		public:

			/// @brief Constructor.
			VisualScriptingSystem(
				std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager,
				std::shared_ptr<inexor::visual_scripting::ProcessorManager> processor_manager,
				std::shared_ptr<inexor::visual_scripting::IntConstantConnectorTest> int_constant_connector_test,
				std::shared_ptr<inexor::visual_scripting::SinTest> sin_test
			);

			/// @brief Destructor.
			~VisualScriptingSystem();

			/// Initialization.
			void init();

		private:

			/// The connector manager.
			std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager;

			/// The active component manager.
			std::shared_ptr<inexor::visual_scripting::ProcessorManager> processor_manager;

			/// The test case for connecting INT_CONSTANTs.
			std::shared_ptr<inexor::visual_scripting::IntConstantConnectorTest> int_constant_connector_test;

			/// The test case for SIN.
			std::shared_ptr<inexor::visual_scripting::SinTest> sin_test;
	};


};
};
