#include "InRangeIntFactory.hpp"

#include <type-system/types/logical/comparison/InRangeInt.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

InRangeIntFactory::InRangeIntFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

InRangeIntFactory::~InRangeIntFactory() = default;

void InRangeIntFactory::init()
{
}

EntityInstancePtrOpt InRangeIntFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(InRangeInt::TYPE_NAME)
        ->attribute(InRangeInt::INPUT, 0)
        ->attribute(InRangeInt::MIN, 0)
        ->attribute(InRangeInt::MAX, 0)
        ->attribute(InRangeInt::RESULT, true)
        ->build();
}

} // namespace inexor::entity_system::type_system
