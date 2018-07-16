// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_RESULT_CODES_HEADER
#define INEXOR_ENTSYS_RESULT_CODES_HEADER

namespace inexor {
namespace entsys {

    // entity system error codes
    enum ENTSYS_RETURN_CODE
    {
        ENTSYS_RETURN_ERROR = -1,
        ENTSYS_RETURN_SUCCESS = 1,
        ENTSYS_RETURN_NEW_ENTITY_TYPE_VALID,
        ENTSYS_RETURN_ENTITY_TYPE_ALREADY_EXISTS,
    };

};
};

#endif // INEXOR_ENTSYS_RESULT_CODES_HEADER
