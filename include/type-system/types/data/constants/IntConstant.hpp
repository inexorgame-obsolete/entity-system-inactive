#pragma once

namespace inexor::entity_system::type_system {

class IntConstant
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "INT_CONSTANT";

    /// The name of the output attribute int_constant_name.
    inline static const std::string NAME = "int_constant_name";

    /// The name of the output attribute int_constant_value.
    inline static const std::string VALUE = "int_constant_value";
};

} // namespace inexor::entity_system::type_system
