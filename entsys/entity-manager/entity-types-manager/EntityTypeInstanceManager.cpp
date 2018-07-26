// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {
    

    EntityTypeInstanceManager::EntityTypeInstanceManager()
    {
    }


    EntityTypeInstanceManager::~EntityTypeInstanceManager()
    {
    }


    EntityTypeInstance EntityTypeInstanceManager::create_entity_type_instance(const std::string& type_name)
    {
        EntityTypeInstance new_inst(type_name);
        entity_type_instances.push_back(new_inst);
        return new_inst;
    }


    EntityTypeInstance EntityTypeInstanceManager::create_entity_type_instance(const EntityType& type)
    {
        EntityTypeInstance new_inst(type.get_entity_type_name());
        entity_type_instances.push_back(new_inst);
        return new_inst;
    }


};
};
