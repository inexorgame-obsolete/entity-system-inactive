// Inexor visual scripting
// (c)2018-2019 Inexor

#include "VisualScriptingSystem.hpp"


namespace inexor {
namespace visual_scripting {


	VisualScriptingSystem::VisualScriptingSystem(
		std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager,
		std::shared_ptr<inexor::visual_scripting::ActiveComponentManager> active_component_manager
	)
	{
        this->connector_manager = connector_manager;
        this->active_component_manager = active_component_manager;
	}

	
	VisualScriptingSystem::~VisualScriptingSystem()
	{
	}

	void VisualScriptingSystem::init()
	{
		connector_manager->init();
		active_component_manager->init();
	}


};
};
