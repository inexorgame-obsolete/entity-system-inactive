// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstance.hpp"
#include "../../../EntitySystem.hpp"


extern inexor::entsys::EntitySystem * entity_system;

namespace inexor {
namespace entsys {


    EntityTypeInstance::EntityTypeInstance()
    {
    }


    EntityTypeInstance::~EntityTypeInstance()
    {
    }


    EntityTypeInstance::EntityTypeInstance(const std::string& type_name)
    {
        entity_system->get_entity_type_class(type_name, type_of_entity);
    }


};
};
