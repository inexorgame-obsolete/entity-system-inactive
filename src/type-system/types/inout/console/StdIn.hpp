#pragma once

namespace inexor::entity_system::type_system {

class StdIn
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "CONSOLE_STDIN";

    /// The name of the output attribute console_stdin.
    inline static const std::string MILLIS = "console_stdin";
};

} // namespace inexor::entity_system::type_system
