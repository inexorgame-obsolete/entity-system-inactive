#pragma once

namespace inexor::entity_system::type_system {

class IntToFloat
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "INT_TO_FLOAT";

    /// The name of the output attribute int_to_float_input.
    inline static const std::string INPUT = "int_to_float_input";

    /// The name of the output attribute int_to_float_value.
    inline static const std::string VALUE = "int_to_float_value";
};

} // namespace inexor::entity_system::type_system
