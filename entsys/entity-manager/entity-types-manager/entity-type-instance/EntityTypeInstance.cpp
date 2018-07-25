// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstance.hpp"
#include "../../../EntitySystem.hpp"

extern inexor::entity_system::EntitySystem* entsys;


namespace inexor {
namespace entity_system {


    EntityTypeInstance::EntityTypeInstance()
    {
    }


    EntityTypeInstance::~EntityTypeInstance()
    {
    }


    EntityTypeInstance::EntityTypeInstance(const std::string& type_name)
    {
        EntityType(entsys->get_entity_type(type_name));
    }


};
};
