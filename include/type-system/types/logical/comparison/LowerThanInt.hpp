#pragma once

namespace inexor::entity_system::type_system {

class LowerThanInt
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "LOWER_THAN_INT";

    /// The name of the input attribute lower_than_int_input_1.
    inline static const std::string INPUT_1 = "lower_than_int_input_1";

    /// The name of the input attribute lower_than_int_input_2.
    inline static const std::string INPUT_2 = "lower_than_int_input_2";

    /// The name of the output attribute lower_than_int_result.
    inline static const std::string RESULT = "lower_than_int_result";
};

} // namespace inexor::entity_system::type_system
