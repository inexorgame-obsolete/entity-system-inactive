#pragma once

#include <variant>
#include <string>

namespace inexor {
namespace entity_system {

/// The data container structure can hold multiple value types
using DataContainer = std::variant<bool, int, double, float, std::string>;

}
}
