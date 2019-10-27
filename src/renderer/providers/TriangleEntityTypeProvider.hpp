#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::renderer {

using namespace inexor::entity_system;

/// @class TriangleEntityTypeProvider
/// @brief Provides an entity type 'TRIANGLE'.
class TriangleEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type 'TRIANGLE'.
    /// @note The dependencies of this class will be injected automatically.
    explicit TriangleEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_factory)
        : EntityTypeProvider(std::move(entity_type_builder_factory), TYPE_NAME, {{TRIANGLE_X, {DataType::FLOAT, 1 << Feature::INPUT}}, {TRIANGLE_Y, {DataType::FLOAT, 1 << Feature::INPUT}}}){};

    /// Destructor.
    ~TriangleEntityTypeProvider() override = default;

    /// Defines the name of this entity type
    static constexpr char TYPE_NAME[] = "TRIANGLE";

    /// The name of the triangle x attribute value.
    static constexpr char TRIANGLE_X[] = "triangle_x";

    /// The name of the triangle y attribute value.
    static constexpr char TRIANGLE_Y[] = "triangle_y";
};

} // namespace inexor::renderer
