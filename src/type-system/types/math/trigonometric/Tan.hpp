#pragma once

namespace inexor::entity_system::type_system {

class Tan
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "TAN";

    /// The name of the input attribute tan_input.
    inline static const std::string INPUT = "tan_input";

    /// The name of the output attribute tan_value.
    inline static const std::string VALUE = "tan_value";
};

} // namespace inexor::entity_system::type_system
