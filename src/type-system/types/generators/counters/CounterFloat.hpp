#pragma once

namespace inexor::entity_system::type_system {

class CounterFloat
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "COUNTER_FLOAT";

    /// The name of the input attribute counter_float_millis.
    inline static const std::string MILLIS = "counter_float_millis";

    /// The name of the input attribute counter_float_step.
    inline static const std::string STEP = "counter_float_step";

    /// The name of the input attribute counter_float_reset.
    inline static const std::string RESET = "counter_float_reset";

    /// The name of the output attribute counter_float_count.
    inline static const std::string COUNT = "counter_float_count";
};

} // namespace inexor::entity_system::type_system
