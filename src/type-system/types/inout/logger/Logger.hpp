#pragma once

#include <string>

namespace inexor::entity_system::type_system {

class Logger
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "GLOBAL_KEY";

    /// The name of the output attribute logger_name.
    inline static const std::string NAME = "logger_name";

    /// The name of the inout attribute log_level.
    inline static const std::string LEVEL = "log_level";

    /// The name of the input attribute log_message.
    inline static const std::string MESSAGE = "log_message";
};

} // namespace inexor::entity_system::type_system
