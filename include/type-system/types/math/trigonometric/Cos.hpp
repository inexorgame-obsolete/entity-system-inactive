#pragma once

namespace inexor::entity_system::type_system {

class Cos
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "COS";

    /// The name of the input attribute cos_input.
    inline static const std::string INPUT = "cos_input";

    /// The name of the output attribute cos_value.
    inline static const std::string VALUE = "cos_value";
};

} // namespace inexor::entity_system::type_system
