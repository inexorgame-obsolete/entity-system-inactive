#pragma once

namespace inexor::entity_system::type_system {

class FloatStore
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "FLOAT_STORE";

    /// The name of the output attribute float_store_name.
    inline static const std::string NAME = "float_store_name";

    /// The name of the output attribute float_store_input_value.
    inline static const std::string INPUT_VALUE = "float_store_input_value";

    /// The name of the output attribute float_store_default_value.
    inline static const std::string DEFAULT_VALUE = "float_store_default_value";

    /// The name of the output attribute float_store_output_value.
    inline static const std::string OUTPUT_VALUE = "float_store_output_value";
};

} // namespace inexor::entity_system::type_system
