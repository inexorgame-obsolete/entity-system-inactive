// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_DATA_CONTAINER_HEADER
#define INEXOR_ENTSYS_DATA_CONTAINER_HEADER

#include <string>
#include "../../../../return-codes/ReturnCodeEnum.hpp"
#include "../data-container/DataAndDataTypeContainerStructure.hpp"

namespace inexor {
namespace entsys {

    class DataContainer
    {
        private:
            DataAndDataTypeContainer container_data;

        public:
            DataContainer();
            ~DataContainer();

    };

};
};

#endif // INEXOR_ENTSYS_DATA_CONTAINER_HEADER
