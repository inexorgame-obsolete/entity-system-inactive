#pragma once

namespace inexor::entity_system::type_system {

class TimerTick
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "TIMER_TICK";

    /// The name of the input attribute timer_tick_millis.
    inline static const std::string MILLIS = "timer_tick_millis";

    /// The name of the output attribute timer_tick_value.
    inline static const std::string VALUE = "timer_tick_value";
};

} // namespace inexor::entity_system::type_system
