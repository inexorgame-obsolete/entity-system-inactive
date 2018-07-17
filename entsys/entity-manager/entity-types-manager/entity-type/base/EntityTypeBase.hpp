// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_BASE_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_BASE_CLASS_HEADER

#include <string>

namespace inexor {
namespace entsys {

    class EntityTypeBase
    {
        private:
            // Every entity has at least the following attributes.
            std::string name;

        public:
            // TODO: write copy constructor(s)!
            EntityTypeBase(std::string);
            // TODO: remove this ?
            EntityTypeBase();
            ~EntityTypeBase();

            const std::string& get_entity_type_name() const;

    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_BASE_CLASS_HEADER
