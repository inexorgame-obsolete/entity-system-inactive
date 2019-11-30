#pragma once

namespace inexor::entity_system::type_system {

class AddFloat
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "ADD_FLOAT";

    /// The name of the input attribute add_float_augend.
    inline static const std::string AUGEND = "add_float_augend";

    /// The name of the input attribute add_float_addend.
    inline static const std::string ADDEND = "add_float_addend";

    /// The name of the output attribute add_float_sum.
    inline static const std::string SUM = "add_float_sum";
};

} // namespace inexor::entity_system::type_system
