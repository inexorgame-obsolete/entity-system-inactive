// Inexor entity system
// (c)2018-2019 Inexor

#pragma once


namespace inexor {
namespace entity_system {


	// TODO: Should this be defined as a class in Doxygen ?

    /// @class ENTSYS_DATA_TYPE
    /// @brief Data container memory type.
    enum ENTSYS_DATA_TYPE 
    {
        // Primitive types
        ENTSYS_DATA_TYPE_BOOL = 0,
        ENTSYS_DATA_TYPE_INT,
        ENTSYS_DATA_TYPE_BIG_INT,
        ENTSYS_DATA_TYPE_DOUBLE,
        ENTSYS_DATA_TYPE_FLOAT,
        ENTSYS_DATA_TYPE_STRING,

        // Vector types from GLM
        ENTSYS_DATA_TYPE_VEC3,
        ENTSYS_DATA_TYPE_VEC4,

        // Binary data

        // TODO: Add vec3 support by supporting GLM:
        // https://glm.g-truc.net/0.9.9/index.html
    };


};
};
