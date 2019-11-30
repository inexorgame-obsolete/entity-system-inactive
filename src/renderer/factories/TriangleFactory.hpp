#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include <entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp>

namespace inexor::renderer {

using EntityInstanceBuilderFactoryPtr = std::shared_ptr<entity_system::EntityInstanceBuilderFactory>;
using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

/// @class RenderFactory
/// @brief Factory of the triangles.
class TriangleFactory
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_builder_factory The entity instance builder factory.
    TriangleFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~TriangleFactory();

    /// Creates a new triangle with the given coordinates.
    /// @param x ?
    /// @param y ?
    EntityInstancePtrOpt create_instance(float x, float y);

    private:
    /// The entity instance builder factory.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::renderer
