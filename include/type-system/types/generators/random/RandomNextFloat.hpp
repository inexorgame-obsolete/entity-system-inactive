#pragma once

namespace inexor::entity_system::type_system {

class RandomNextFloat
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "RANDOM_NEXT_FLOAT";

    /// The name of the input attribute random_next_float_on_activation.
    inline static const std::string ON_ACTIVATION = "random_next_float_on_activation";

    /// The name of the input attribute random_next_float_min.
    inline static const std::string MIN = "random_next_float_min";

    /// The name of the input attribute random_next_float_max.
    inline static const std::string MAX = "random_next_float_max";

    /// The name of the output attribute random_next_float_value.
    inline static const std::string VALUE = "random_next_float_value";
};

} // namespace inexor::entity_system::type_system
