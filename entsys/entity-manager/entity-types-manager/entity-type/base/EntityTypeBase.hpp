// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_BASE_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_BASE_CLASS_HEADER

#include <string>

namespace inexor {
namespace entsys {

    /// \class EntityTypeBase
    /// \brief A base class for entity types.
    class EntityTypeBase
    {
        protected:
            // Every entity has at least the following attributes.
            std::string entity_type_name;

        public:
            EntityTypeBase();
            EntityTypeBase(std::string);
            ~EntityTypeBase();

            const std::string& get_entity_type_name() const;

    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_BASE_CLASS_HEADER
