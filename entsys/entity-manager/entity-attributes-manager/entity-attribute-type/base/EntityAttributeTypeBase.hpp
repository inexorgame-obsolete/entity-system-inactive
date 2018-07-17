// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_BASE_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_BASE_CLASS_HEADER

#include <string>
#include <vector>
#include "../../../data-container/DataContainer.hpp"

namespace inexor {
namespace entsys {

    /// A base class for types of attributes of entites.
    class EntityAttributeTypeBase
    {
        protected:
            std::string entity_attribute_type_name;
            DataContainer entity_attribute_data;

        public:
            EntityAttributeTypeBase();
            ~EntityAttributeTypeBase();

    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_TYPE_BASE_CLASS_HEADER
