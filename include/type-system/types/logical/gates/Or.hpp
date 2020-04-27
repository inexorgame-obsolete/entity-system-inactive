#pragma once

namespace inexor::entity_system::type_system {

class Or
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "OR";

    /// The name of the input attribute or_input_1.
    inline static const std::string INPUT_1 = "or_input_1";

    /// The name of the input attribute or_input_2.
    inline static const std::string INPUT_2 = "or_input_2";

    /// The name of the output attribute or_result.
    inline static const std::string RESULT = "or_result";
};

} // namespace inexor::entity_system::type_system
