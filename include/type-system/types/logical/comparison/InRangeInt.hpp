#pragma once

namespace inexor::entity_system::type_system {

class InRangeInt
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "IN_RANGE_INT";

    /// The name of the input attribute in_range_int_input.
    inline static const std::string INPUT = "in_range_int_input";

    /// The name of the input attribute in_range_int_min.
    inline static const std::string MIN = "in_range_int_min";

    /// The name of the input attribute in_range_int_max.
    inline static const std::string MAX = "in_range_int_max";

    /// The name of the output attribute in_range_int_result.
    inline static const std::string RESULT = "in_range_int_result";
};

} // namespace inexor::entity_system::type_system
