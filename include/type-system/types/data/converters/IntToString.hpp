#pragma once

#include <string>

namespace inexor::entity_system::type_system {

class IntToString
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "INT_TO_STRING";

    /// The name of the output attribute int_to_string_input.
    inline static const std::string INPUT = "int_to_string_input";

    /// The name of the output attribute int_to_string_value.
    inline static const std::string VALUE = "int_to_string_value";
};

} // namespace inexor::entity_system::type_system
