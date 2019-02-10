// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <iostream>

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
				std::shared_ptr<inexor::visual_scripting::ActiveComponentManager> active_component_manager
			);

			/// @brief Destructor.
			~VisualScriptingSystem();

			/// Initialization.
			void init();

		private:

			/// The connector manager.
			std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager;

			/// The active component manager.
			std::shared_ptr<inexor::visual_scripting::ActiveComponentManager> active_component_manager;

	};


};
};
