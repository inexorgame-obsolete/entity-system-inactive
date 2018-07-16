// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_DATA_AND_DATA_TYPE_CONTAINER_HEADER
#define INEXOR_ENTSYS_DATA_AND_DATA_TYPE_CONTAINER_HEADER

#include <string>
#include <cstdint>
#include "../data-container/DataTypeStructure.hpp"

namespace inexor {
namespace entsys {

    // The minimum/maximum memory value depends
    // on the operating system and 64/32 bit architecture
    // Inexor uses 64bit exclusively!

    // we are a bit wasteful with memory here
    // but keep in mind that this has many advantages
    // over std::any (C++17) or union classes since
    // we store both data and data type safely.
    struct MultipleDataTypeContainer
    {
        // characters and string
        std::string string_data;

        // numbers
        std::int64_t int_data;

        // TODO: add double and long double if neccesary
        // TODO: add vec3, vec2..
        // TODO: add (function) pointers
    };

    struct DataAndDataTypeContainer
    {
        MultipleDataTypeContainer data;
        INEXOR_ENTSYS_DATA_TYPE type;
    };

};
};

#endif // INEXOR_ENTSYS_DATA_AND_DATA_TYPE_CONTAINER_HEADER
