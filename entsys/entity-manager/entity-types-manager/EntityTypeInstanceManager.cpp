// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstanceManager.hpp"

namespace inexor {
namespace entsys {
    

    EntityTypeInstanceManager::EntityTypeInstanceManager()
    {
    }


    EntityTypeInstanceManager::~EntityTypeInstanceManager()
    {
    }


    const EntityTypeInstance EntityTypeInstanceManager::create_entity_type_instance(const std::string& type_name)
    {
        EntityTypeInstance new_inst(type_name);
        entity_type_instances.push_back(new_inst);
        return new_inst;
    }


};
};
