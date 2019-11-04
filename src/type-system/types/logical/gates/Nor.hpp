#pragma once

namespace inexor::entity_system::type_system {

class Nor
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "NOR";

    /// The name of the input attribute nor_input_1.
    inline static const std::string INPUT_1 = "nor_input_1";

    /// The name of the input attribute nor_input_2.
    inline static const std::string INPUT_2 = "nor_input_2";

    /// The name of the output attribute nor_result.
    inline static const std::string RESULT = "nor_result";
};

} // namespace inexor::entity_system::type_system
