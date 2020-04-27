#pragma once

namespace inexor::entity_system::type_system {

class CounterInt
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "COUNTER_INT";

    /// The name of the input attribute counter_int_millis.
    inline static const std::string MILLIS = "counter_int_millis";

    /// The name of the input attribute counter_int_step.
    inline static const std::string STEP = "counter_int_step";

    /// The name of the input attribute counter_int_reset.
    inline static const std::string RESET = "counter_int_reset";

    /// The name of the output attribute counter_int_count.
    inline static const std::string COUNT = "counter_int_count";
};

} // namespace inexor::entity_system::type_system
