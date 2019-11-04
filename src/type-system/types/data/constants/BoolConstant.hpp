#pragma once

namespace inexor::entity_system::type_system {

class BoolConstant
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "BOOL_CONSTANT";

    /// The name of the output attribute bool_constant_name.
    inline static const std::string NAME = "bool_constant_name";

    /// The name of the output attribute bool_constant_value.
    inline static const std::string VALUE = "bool_constant_value";
};

} // namespace inexor::entity_system::type_system
