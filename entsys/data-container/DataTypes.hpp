// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_DATA_TYPE_ENUMERATION_HEADER
#define INEXOR_ENTSYS_DATA_TYPE_ENUMERATION_HEADER

namespace inexor {
namespace entsys {

    /// 
    enum ENTSYS_DATA_TYPE 
    {
        ENTSYS_DATA_TYPE_UNSPECIFIED,
        ENTSYS_DATA_TYPE_INT,
        ENTSYS_DATA_TYPE_BIG_INT,
        ENTSYS_DATA_TYPE_FLOAT,
        //ENTSYS_DATA_TYPE_CHARACTER,
        ENTSYS_DATA_TYPE_STRING,
        ENTSYS_DATA_TYPE_DOUBLE,
        ENTSYS_DATA_TYPE_BOOL,
        // TODO: vec3, vec2...
    };

};
};

#endif // INEXOR_ENTSYS_DATA_TYPE_ENUMERATION_HEADER
