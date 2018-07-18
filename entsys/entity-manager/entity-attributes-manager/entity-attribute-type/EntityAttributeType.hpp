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

    /// A base class for types of attributes of entites.
    class EntityAttributeType
    {
        // TODO: May change this to protected?
        private:

            // Once all the data has been set this entity attribute type
            // will be finished using the finish method.
            bool finished = false;
            
            std::string entity_attribute_type_name = std::string("");

            // The data of this attribute type is not specified yet
            // This is why we use the standard constructor here
            // Data type of this container is ENTSYS_DATA_TYPE_UNSPECIFIED.
            DataContainer entity_attribute_data;


        public:
            EntityAttributeType();
            ~EntityAttributeType();

            // TODO: DISCUSS: Do all these methods have to me of const type?

            // Set the name of the entity attribute type.
            const ENTSYS_RETURN_CODE set_attrib_name(const std::string&);

            // Set the data type of the entity attribute type.
            const ENTSYS_RETURN_CODE set_attrib_datatype(const ENTSYS_DATA_TYPE&);

            // Validate the entity attribute type.
            const ENTSYS_RETURN_CODE finish();

            const ENTSYS_DATA_TYPE get_data_type() const;

            // TODO: DISCUSS: Should there be a way to change this data afterwards?
            // This whould mean that every instance of this entity attribute type would 
            // be affected by this! Currently there is no intention to do so.
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_BASE_CLASS_HEADER
