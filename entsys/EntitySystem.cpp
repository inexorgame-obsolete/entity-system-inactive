// Inexor entity system prototype
// (c)2018 Inexor

#include "EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	EntitySystem& EntitySystem::Instance()
	{
		std::call_once(EntitySystem::onceFlag,[] (){
			instance.reset(new EntitySystem); 
		});

		return *(instance.get());
	}


};
};
