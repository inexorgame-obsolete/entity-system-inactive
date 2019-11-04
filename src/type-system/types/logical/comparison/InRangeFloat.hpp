#pragma once

namespace inexor::entity_system::type_system {

class InRangeFloat
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "IN_RANGE_FLOAT";

    /// The name of the input attribute in_range_float_input.
    inline static const std::string INPUT = "in_range_float_input";

    /// The name of the input attribute in_range_float_min.
    inline static const std::string MIN = "in_range_float_min";

    /// The name of the input attribute in_range_float_max.
    inline static const std::string MAX = "in_range_float_max";

    /// The name of the output attribute in_range_float_result.
    inline static const std::string RESULT = "in_range_float_result";
};

} // namespace inexor::entity_system::type_system
