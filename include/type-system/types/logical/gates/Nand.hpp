#pragma once

namespace inexor::entity_system::type_system {

class Nand
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "NAND";

    /// The name of the input attribute nand_input_1.
    inline static const std::string INPUT_1 = "nand_input_1";

    /// The name of the input attribute nand_input_2.
    inline static const std::string INPUT_2 = "nand_input_2";

    /// The name of the output attribute nand_result.
    inline static const std::string RESULT = "nand_result";
};

} // namespace inexor::entity_system::type_system
