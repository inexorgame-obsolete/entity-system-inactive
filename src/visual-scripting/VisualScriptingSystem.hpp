// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <iostream>

#include "type-system/factories/constants/IntConstantFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"
#include "visual-scripting/managers/ActiveComponentManager.hpp"


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
				std::shared_ptr<inexor::visual_scripting::ActiveComponentManager> active_component_manager,
				shared_ptr<inexor::entity_system::type_system::IntConstantFactory> int_constant_factory
			);

			/// @brief Destructor.
			~VisualScriptingSystem();

			/// Initialization.
			void init();

			/// Tests for the connectors
			void init_connector_tests();
			void run_connector_tests();

		private:

			/// The connector manager.
			std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager;

			/// The active component manager.
			std::shared_ptr<inexor::visual_scripting::ActiveComponentManager> active_component_manager;

			shared_ptr<inexor::entity_system::type_system::IntConstantFactory> int_constant_factory;
	};


};
};
