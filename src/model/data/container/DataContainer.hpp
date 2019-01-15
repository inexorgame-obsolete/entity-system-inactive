// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include <string>
#include <variant>
#include <cstdint>

#include "../../../model/data/DataTypes.hpp"
#include "../../../util/error-handling/ReturnCodes.hpp"


namespace inexor {
namespace entity_system {

    /// A data value can hold any value allowed by ENTSYS_DATA_TYPE
    using DataValue = std::variant<int, std::int64_t, float, std::string, double, bool>;

    /// A data container which can hold data of various types.
    struct DataContainer {
        ENTSYS_DATA_TYPE type;
        DataValue value;
    };
};
};
