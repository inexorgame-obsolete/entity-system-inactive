#include "TriangleFactory.hpp"

#include <type-system/types/test/Triangle.hpp>
#include <utility>

namespace inexor::renderer {

using Triangle = entity_system::type_system::Triangle;

TriangleFactory::TriangleFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

TriangleFactory::~TriangleFactory() = default;

EntityInstancePtrOpt TriangleFactory::create_instance(float x, float y)
{
    return this->entity_instance_builder_factory
        ->get_builder(Triangle::TYPE_NAME)
        ->attribute(Triangle::X, x)
        ->attribute(Triangle::Y, y)
        ->build();
}

} // namespace inexor::renderer
