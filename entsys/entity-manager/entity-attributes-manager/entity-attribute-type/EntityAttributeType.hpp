// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_BASE_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_BASE_CLASS_HEADER

#include <string>
#include <vector>
#include "../../../data-container/DataContainer.hpp"
#include "../../../return-codes/ReturnCodes.hpp"

namespace inexor {
namespace entsys {

    // A base class for types of attributes of entites.
    class EntityAttributeType
    {
        // TODO: May change this to protected?
        private:

            // Once all the data has been set this entity attribute type
            // will be finished using the finish method.
            bool finished;
            
            // The name of the type of attribute of the entity.
            std::string entity_attribute_type_name;

            // The data of this attribute type is not specified yet
            // This is why we use the standard constructor here
            // Data type of this container is ENTSYS_DATA_TYPE_UNSPECIFIED.
            DataContainer entity_attribute_data;

            // TODO: Should an entity attribute type be limited to only on data container?
            // Currently yes, because every entity attribute type acts as the key for the key/value pair.

        public:

            EntityAttributeType();
            // TODO: Add overloaded constructors.

            ~EntityAttributeType();

            // TODO: DISCUSS: Do all these methods have to me of const type?

            // Set the name of the type of attribute of an entity.
            const ENTSYS_RETURN_CODE set_name(const std::string&);

            // Set the data type of the entity attribute type.
            const ENTSYS_RETURN_CODE set_data_type(const ENTSYS_DATA_TYPE&);

            // Validate the entity attribute type.
            const ENTSYS_RETURN_CODE finish_entity_attribute_type();

            const ENTSYS_DATA_TYPE get_data_type() const;
            const std::string get_name() const;
            const bool is_finished() const;

            // TODO: DISCUSS: Should there be a way to change this data afterwards?
            // This whould mean that every instance of this entity attribute type would 
            // be affected by this! Currently there is no intention to do so.
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_BASE_CLASS_HEADER
