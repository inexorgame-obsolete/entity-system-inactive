// Inexor entity system
// (c)2018 Inexor

#include "ActiveComponentRegistry.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace visual_scripting {


	ActiveComponentRegistry::ActiveComponentRegistry()
	{
	}

	ActiveComponentRegistry::~ActiveComponentRegistry()
	{
	}

	void ActiveComponentRegistry::init()
	{
	}

	/// @brief Registers an active component.
	void ActiveComponentRegistry::register_active_component(const shared_ptr<ActiveComponent>& active_component)
	{
		active_components[active_component->get_entity_type()] = active_component;
	}

	/// @brief Returns the active component by entity type.
	optional<shared_ptr<ActiveComponent>> ActiveComponentRegistry::get_active_component_by_entity_type(const ENT_TYPE& entity_type)
	{
		if (!(active_components.end() == active_components.find(entity_type)))
		{
			return optional<shared_ptr<ActiveComponent>> { active_components[entity_type] };
		}
		return nullopt;
	}


}
}
