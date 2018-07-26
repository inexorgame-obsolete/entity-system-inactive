// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_CLASS_HEADER

#include <string>
#include <unordered_map>
#include "../../../return-codes/ReturnCodes.hpp"
#include "../../entity-attributes-manager/entity-attribute-type/EntityAttributeType.hpp"


namespace inexor {
namespace entity_system {


    // Make later definitions shorter by using type definitions.
    typedef std::unordered_map<std::string, EntityAttributeType> ENTSYS_ENTITY_ATTRIBUTE_TYPE_MAP;


    // 
    class EntityType
    {
        protected:
                        
            // Every entity has at least the following attributes.
            std::string entity_type_name = std::string("INVALID!");

            // TODO: DISCUSS: This this a good design pattern?
            // or should we let the entity attribute type instance manager
            // decide which instances of entity attribute types exist?
            ENTSYS_ENTITY_ATTRIBUTE_TYPE_MAP map_of_entity_attribute_types;
            

        public:

            EntityType();
            EntityType(const std::string&);
            ~EntityType();

            ENTSYS_RETURN_CODE set_entity_type_name(const std::string&);
            std::string get_entity_type_name() const;

            // TODO: DISCUSS: This this a good design pattern?
            // or should we let the entity attribute type instance manager
            // decide which instances of entity attribute types exist?
            ENTSYS_RETURN_CODE link_entity_attribute_type(const EntityAttributeType&);

            ENTSYS_RETURN_CODE set_attribute_data(const EntityAttributeType&, const std::string&);
            // TODO: Overload method for setting other data types!

            std::string read_attribute_data(const EntityAttributeType&);

    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_CLASS_HEADER
