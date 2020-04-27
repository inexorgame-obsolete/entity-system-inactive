#pragma once

namespace inexor::entity_system::type_system {

class Sin
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "SIN";

    /// The name of the input attribute sin_input.
    inline static const std::string INPUT = "sin_input";

    /// The name of the output attribute sin_value.
    inline static const std::string VALUE = "sin_value";
};

} // namespace inexor::entity_system::type_system
