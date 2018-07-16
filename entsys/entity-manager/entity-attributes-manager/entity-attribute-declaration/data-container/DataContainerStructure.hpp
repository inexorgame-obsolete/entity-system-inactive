// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_DATA_CONTAINER_HEADER
#define INEXOR_ENTSYS_DATA_CONTAINER_HEADER

#include <string>

#include "../errorhandling/EntSys_ResultCodeEnum.hpp"
#include "../data-container/EntSys_DataAndDataTypeContainerStructure.hpp"

namespace inexor {
namespace entsys {

    class CDataContainer {

        private:

            SDataAndDataTypeContainer container_data;

        public:

            CDataContainer();
            ~CDataContainer();

            // TODO: set and get methods

    };

};
};

#endif // INEXOR_ENTSYS_DATA_CONTAINER_HEADER
