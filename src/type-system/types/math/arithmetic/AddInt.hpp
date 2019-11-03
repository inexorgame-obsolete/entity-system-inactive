#pragma once

namespace inexor::entity_system::type_system {

class AddInt
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "ADD_INT";

    /// The name of the input attribute add_int_augend.
    inline static const std::string AUGEND = "add_int_augend";

    /// The name of the input attribute add_int_addend.
    inline static const std::string ADDEND = "add_int_addend";

    /// The name of the output attribute add_int_sum.
    inline static const std::string SUM = "add_int_sum";
};

} // namespace inexor::entity_system::type_system
