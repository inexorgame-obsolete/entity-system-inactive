#pragma once

namespace inexor::entity_system::type_system {

class StdOut
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "CONSOLE_STDOUT";

    /// The name of the output attribute console_stdout.
    inline static const std::string STDOUT = "console_stdout";
};

} // namespace inexor::entity_system::type_system
