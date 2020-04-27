#pragma once

namespace inexor::entity_system::type_system {

class And
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "AND";

    /// The name of the input attribute and_input_1.
    inline static const std::string INPUT_1 = "and_input_1";

    /// The name of the input attribute and_input_2.
    inline static const std::string INPUT_2 = "and_input_2";

    /// The name of the output attribute and_result.
    inline static const std::string RESULT = "and_result";
};

} // namespace inexor::entity_system::type_system
