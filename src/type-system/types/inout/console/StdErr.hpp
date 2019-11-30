#pragma once

#include <string>

namespace inexor::entity_system::type_system {

class StdErr
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "CONSOLE_STDERR";

    /// The name of the output attribute console_stderr.
    inline static const std::string STDERR = "console_stderr";
};

} // namespace inexor::entity_system::type_system
