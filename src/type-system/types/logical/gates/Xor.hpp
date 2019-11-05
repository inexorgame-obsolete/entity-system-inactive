#pragma once

#include <string>

namespace inexor::entity_system::type_system {

class Xor
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "XOR";

    /// The name of the input attribute xor_input_1.
    inline static const std::string INPUT_1 = "xor_input_1";

    /// The name of the input attribute xor_input_2.
    inline static const std::string INPUT_2 = "xor_input_2";

    /// The name of the output attribute xor_result.
    inline static const std::string RESULT = "xor_result";
};

} // namespace inexor::entity_system::type_system
