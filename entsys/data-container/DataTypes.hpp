// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_DATA_TYPE_ENUMERATION_HEADER
#define INEXOR_ENTSYS_DATA_TYPE_ENUMERATION_HEADER

namespace inexor {
namespace entsys {

    // Data container memory type enumeration.
    enum ENTSYS_DATA_TYPE 
    {
        ENTSYS_DATA_TYPE_INT,
        ENTSYS_DATA_TYPE_BIG_INT,
        ENTSYS_DATA_TYPE_FLOAT,
        ENTSYS_DATA_TYPE_STRING,
        ENTSYS_DATA_TYPE_DOUBLE,
        ENTSYS_DATA_TYPE_BOOL,

        // TODO: Add vec3 support by supporting GLM:
        // https://glm.g-truc.net/0.9.9/index.html
    };

};
};

#endif // INEXOR_ENTSYS_DATA_TYPE_ENUMERATION_HEADER
