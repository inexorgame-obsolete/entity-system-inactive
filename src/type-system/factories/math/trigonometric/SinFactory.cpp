#include "SinFactory.hpp"

#include <utility>

#include "type-system/types/math/trigonometric/Sin.hpp"

namespace inexor::entity_system::type_system {

SinFactory::SinFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

SinFactory::~SinFactory() = default;

std::string SinFactory::get_component_name()
{
    return "SinFactory";
}

EntityInstancePtrOpt SinFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(Sin::TYPE_NAME)->attribute(Sin::INPUT, 0.0f)->attribute(Sin::VALUE, 0.0f)->build();
}

EntityInstancePtrOpt SinFactory::create_instance(float input_value)
{
    return entity_instance_builder_factory->get_builder(Sin::TYPE_NAME)->attribute(Sin::INPUT, input_value)->attribute(Sin::VALUE, sinf(input_value))->build();
}

} // namespace inexor::entity_system::type_system
