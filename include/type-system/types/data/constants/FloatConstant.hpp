#pragma once

namespace inexor::entity_system::type_system {

class FloatConstant
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "FLOAT_CONSTANT";

    /// The name of the output attribute float_constant_name.
    inline static const std::string NAME = "float_constant_name";

    /// The name of the output attribute float_constant_value.
    inline static const std::string VALUE = "float_constant_value";
};

} // namespace inexor::entity_system::type_system
