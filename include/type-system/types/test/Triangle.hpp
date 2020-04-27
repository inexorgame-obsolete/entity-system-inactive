#pragma once

namespace inexor::entity_system::type_system {

class Triangle
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "TRIANGLE";

    /// The name of the output attribute window_id.
    inline static const std::string X = "triangle_x";

    /// The name of the inout attribute window_title.
    inline static const std::string Y = "triangle_y";
};

} // namespace inexor::entity_system::type_system
