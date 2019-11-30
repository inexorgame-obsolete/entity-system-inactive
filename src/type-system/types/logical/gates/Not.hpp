#pragma once

namespace inexor::entity_system::type_system {

class Not
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "NOT";

    /// The name of the input attribute not_input.
    inline static const std::string INPUT = "not_input";

    /// The name of the output attribute not_result.
    inline static const std::string RESULT = "not_result";
};

} // namespace inexor::entity_system::type_system
