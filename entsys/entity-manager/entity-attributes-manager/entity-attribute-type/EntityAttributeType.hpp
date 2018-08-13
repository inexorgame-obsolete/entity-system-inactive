// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_CLASS_HEADER

#include <string>
#include <vector>
#include <unordered_map>

#include "../../../tests/EntitySystemDebugging.hpp"
#include "../../../data-container/DataContainer.hpp"
#include "../../../return-codes/ReturnCodes.hpp"


namespace inexor {
namespace entity_system {
    

    class EntityAttributeType
    {
        protected:

            // The name of the type of attribute of the entity.
            std::string entity_attribute_type_name = std::string("UNDEFINED!");

            // The data type of the data container.
            DataContainer entity_attribute_data = ENTSYS_DATA_TYPE_STRING;

            // TODO: Should an entity attribute type be limited to only on data container?
            // Currently yes, because every entity attribute type acts as the key for the key/value pair.

        public:

            EntityAttributeType();
            EntityAttributeType(const std::string&);
            EntityAttributeType(const ENTSYS_DATA_TYPE&);
            EntityAttributeType(const std::string&, const ENTSYS_DATA_TYPE&);

            ~EntityAttributeType();
            
            ENTSYS_RETURN_CODE validate();

            ENTSYS_RETURN_CODE set_entity_attribute_data_type(const ENTSYS_DATA_TYPE&);
            ENTSYS_DATA_TYPE get_entity_attribute_data_type() const;

            ENTSYS_RETURN_CODE set_entity_attribute_data(const std::string&);
            void get_entity_attribute_data(std::string&) const;

            ENTSYS_RETURN_CODE set_entity_attribute_type_name(const std::string&);
            std::string get_entity_attribute_type_name() const;

            // TODO: DISCUSS: Should there be a way to change this data afterwards?
            // This whould mean that every instance of this entity attribute type would 
            // be affected by this! Currently there is no intention to do so.
    };
    

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_CLASS_HEADER
