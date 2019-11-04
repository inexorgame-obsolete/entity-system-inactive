#pragma once

namespace inexor::entity_system::type_system {

class EqualsString
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "EQUALS_STRING";

    /// The name of the input attribute equals_string_input_1.
    inline static const std::string INPUT_1 = "equals_string_input_1";

    /// The name of the input attribute equals_string_input_2.
    inline static const std::string INPUT_2 = "equals_string_input_2";

    /// The name of the output attribute equals_string_result.
    inline static const std::string RESULT = "equals_string_result";
};

} // namespace inexor::entity_system::type_system
