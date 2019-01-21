// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <string>
#include <variant>
#include <cstdint>
#include <glm/glm.hpp>

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/return-codes/ReturnCodes.hpp"


namespace inexor {
namespace entity_system {

    /// A data value can hold any value allowed by ENTSYS_DATA_TYPE
    using DataValue = std::variant<bool, int, std::int64_t, double, float, std::string, glm::vec3, glm::vec4>;

    /// A data container which can hold data of various types.
    struct DataContainer {
        ENTSYS_DATA_TYPE type;
        DataValue value;
    };

};
};
