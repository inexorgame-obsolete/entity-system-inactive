// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_ATTRIBUTE_MANAGER_HEADER
#define INEXOR_ENTSYS_ENTITY_ATTRIBUTE_MANAGER_HEADER

namespace inexor {
namespace entsys {

class CEntityAttributeManager
{
    private:
        void validate_attribute();

    protected:
        void add_attribute();
        void modify_attribute();
        void remove_attribute();

    public:
        CEntityAttributeManager();
        ~CEntityAttributeManager();
};

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_MANAGER_HEADER
