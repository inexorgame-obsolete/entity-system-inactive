// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeManager.hpp"

namespace inexor {
namespace entsys {

    EntityAttributeTypeManager::EntityAttributeTypeManager()
    {
    }

    EntityAttributeTypeManager::~EntityAttributeTypeManager()
    {
    }

    const size_t EntityAttributeTypeManager::get_entity_attribute_type_cound() const
    {
        return entity_attribute_types.size();
    }

    const ENTSYS_RETURN_CODE EntityAttributeTypeManager::create_entity_attribute_type(const EntityAttributeTypeBase&)
    {
        // TODO
        return ENTSYS_RETURN_ERROR;
    }

};
};
