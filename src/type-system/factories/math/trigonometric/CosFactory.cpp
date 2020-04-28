#include <type-system/factories/math/trigonometric/CosFactory.hpp>

#include <utility>

#include "type-system/types/math/trigonometric/Cos.hpp"

namespace inexor::entity_system::type_system {

CosFactory::CosFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

CosFactory::~CosFactory() = default;

std::string CosFactory::get_component_name()
{
    return "CosFactory";
}

EntityInstancePtrOpt CosFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(Cos::TYPE_NAME)->attribute(Cos::INPUT, 0.0f)->attribute(Cos::VALUE, 1.0f)->build();
}

EntityInstancePtrOpt CosFactory::create_instance(float input_value)
{
    return entity_instance_builder_factory->get_builder(Cos::TYPE_NAME)->attribute(Cos::INPUT, input_value)->attribute(Cos::VALUE, cosf(input_value))->build();
}

} // namespace inexor::entity_system::type_system
