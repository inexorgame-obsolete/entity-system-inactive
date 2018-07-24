// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstance.hpp"
#include "../../../EntitySystem.hpp"

extern inexor::entsys::EntitySystem* entity_system;


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
        // TODO: Does this constructor call of an inherited class even work?
        EntityType(entity_system->get_entity_type(type_name));
    }


    ENTSYS_RETURN_CODE EntityTypeInstance::set_attribute_data(const EntityAttributeType& ent_attr_type, const std::string& data)
    {
        // TOOD: Debug!
        //map_of_entity_attribute_types[ent_attr_type.get_name()].set_data(data);
        // TODO: Resolve!
        return ENTSYS_RETURN_ERROR;
    }


};
};
