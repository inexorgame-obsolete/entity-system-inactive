#pragma once

namespace inexor::entity_system::type_system {

class StringConstant
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "STRING_CONSTANT";

    /// The name of the output attribute string_constant_name.
    inline static const std::string NAME = "string_constant_name";

    /// The name of the output attribute string_constant_value.
    inline static const std::string VALUE = "string_constant_value";
};

} // namespace inexor::entity_system::type_system
