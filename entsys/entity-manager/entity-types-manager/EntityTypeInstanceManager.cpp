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


    ENTSYS_RETURN_CODE EntityTypeInstanceManager::set_attribute_data(const EntityTypeInstance& ent_inst, const EntityAttributeType& attr_type, const std::string& attr_val)
    {
        // TODO: Set attribute data here!
        return ENTSYS_RETURN_ERROR;
    }


};
};
