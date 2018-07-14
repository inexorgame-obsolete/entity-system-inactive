// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_RELATION_MANAGER_HEADER
#define INEXOR_ENTSYS_RELATION_MANAGER_HEADER

namespace inexor {
namespace entsys {

class CEntityRelationManager
{
    protected:
        void add_relation();
        void modify_relation();
        void remove_relation();

    public:
        CEntityRelationManager();
        ~CEntityRelationManager();
};

};
};

#endif // INEXOR_ENTSYS_RELATION_MANAGER_HEADER
