#pragma once

namespace inexor::entity_system::type_system {

class IntStore
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "INT_STORE";

    /// The name of the output attribute int_store_name.
    inline static const std::string NAME = "int_store_name";

    /// The name of the output attribute int_store_input_value.
    inline static const std::string INPUT_VALUE = "int_store_input_value";

    /// The name of the output attribute int_store_default_value.
    inline static const std::string DEFAULT_VALUE = "int_store_default_value";

    /// The name of the output attribute int_store_output_value.
    inline static const std::string OUTPUT_VALUE = "int_store_output_value";
};

} // namespace inexor::entity_system::type_system
