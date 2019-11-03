#include "TanFactory.hpp"

#include <utility>

#include "type-system/types/math/trigonometric/Tan.hpp"

namespace inexor::entity_system::type_system {

TanFactory::TanFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

TanFactory::~TanFactory() = default;

void TanFactory::init()
{
}

EntityInstancePtrOpt TanFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(Tan::TYPE_NAME)->attribute(Tan::INPUT, 0.0f)->attribute(Tan::VALUE, 0.0f)->build();
}

EntityInstancePtrOpt TanFactory::create_instance(float input_value)
{
    return entity_instance_builder_factory->get_builder(Tan::TYPE_NAME)->attribute(Tan::INPUT, input_value)->attribute(Tan::VALUE, tanf(input_value))->build();
}

} // namespace inexor::entity_system::type_system
