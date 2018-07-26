// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_RESULT_CODE_ENUM_HEADER
#define INEXOR_ENTSYS_RESULT_CODE_ENUM_HEADER


namespace inexor {
namespace entity_system {


    // Entity system error codes.
    enum ENTSYS_RETURN_CODE
    {
        // ERROR codes here
        ENTSYS_RETURN_ERROR = -1000,
        ENTSYS_RETURN_ENTITY_TYPE_ALREADY_EXISTS,
        ENTSYS_RETURN_ERROR_ENTITY_TYPE_UNAVAILABLE,
        ENTSYS_RETURN_NAME_INVALID,

        // SUCCESS codes here
        ENTSYS_RETURN_SUCCESS = 1,
        ENTSYS_RETURN_NEW_ENTITY_TYPE_VALID,

        // TODO: DISCUSS: Should positive return codes 
        // be implemented or is ENTSYS_RETURN_SUCCESS enough ?
    };


};
};

#endif // INEXOR_ENTSYS_RESULT_CODE_ENUM_HEADER
