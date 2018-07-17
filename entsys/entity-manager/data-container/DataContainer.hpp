// Inexor entity system prototype
// (c)2018 Inexor

// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_DATA_AND_DATA_TYPE_CONTAINER_HEADER
#define INEXOR_ENTSYS_DATA_AND_DATA_TYPE_CONTAINER_HEADER

#include <string>
#include <cstdint>
#include "DataTypes.hpp"

namespace inexor {
namespace entsys {

    /// 
    struct MultipleDataTypeContainer
    {
        MultipleDataTypeContainer();

        // characters and string
        std::string string_data;

        // numbers
        std::int64_t int_data;

        // TODO: add double and long double if neccesary
        // TODO: add vec3, vec2...
        // TODO: add (function) pointers
    };
        
    /// A flexible, multiple purpose data container.
    class DataContainer
    {
        private:
            INEXOR_ENTSYS_DATA_TYPE container_data_type;
            MultipleDataTypeContainer container_data;
        
        public:
            DataContainer();
            ~DataContainer();

    };

};
};

#endif // INEXOR_ENTSYS_DATA_AND_DATA_TYPE_CONTAINER_HEADER
