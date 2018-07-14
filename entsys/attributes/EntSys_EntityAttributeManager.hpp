// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_ATTRIBUTE_MANAGER_HEADER
#define INEXOR_ENTSYS_ENTITY_ATTRIBUTE_MANAGER_HEADER

#include "../errorhandling/EntSys_ResultCodes.hpp"

namespace inexor {
namespace entsys {

class CEntityAttributeManager
{
    private:
        void validate_attribute();

    protected:
        ENTSYS_RESULT_CODE add_attribute();
        ENTSYS_RESULT_CODE modify_attribute();
        ENTSYS_RESULT_CODE set_attribute_value();
        ENTSYS_RESULT_CODE remove_attribute();

    public:
        CEntityAttributeManager();
        ~CEntityAttributeManager();


};

};
};

#endif // INEXOR_ENTSYS_ENTITY_ATTRIBUTE_MANAGER_HEADER
