// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_TYPE_DEFINITION_HEADER
#define INEXOR_ENTSYS_TYPE_DEFINITION_HEADER

#include <unordered_map>
#include <memory>

#include "../entity-manager/entity-attributes-manager/entity-attribute-type/EntityAttributeType.hpp"

namespace inexor {
namespace entity_system {
	
    // By using these type definitions we can make later definitions shorter.
    typedef std::unordered_map<std::string, EntityAttributeType> ENTSYS_ENTITY_ATTRIBUTE_TYPE_MAP;
    typedef ENTSYS_ENTITY_ATTRIBUTE_TYPE_MAP::const_iterator ENTSYS_ENTITY_ATTRIBUTE_TYPE_LOOKUP;

};
};

#endif // 
