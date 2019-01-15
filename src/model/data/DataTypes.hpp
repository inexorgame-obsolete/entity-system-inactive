// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once


namespace inexor {
namespace entity_system {


	// TODO: Should this be defined as a class in Doxygen ?

    /// @class ENTSYS_DATA_TYPE
    /// @brief Data container memory type.
    enum ENTSYS_DATA_TYPE 
    {
        ENTSYS_DATA_TYPE_UNDEFINED = -1, // TODO: Find a satisfying solution for this
        ENTSYS_DATA_TYPE_INT = 0,
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
