#include "GreaterThanIntFactory.hpp"

#include <type-system/types/logical/comparison/GreaterThanInt.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

GreaterThanIntFactory::GreaterThanIntFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

GreaterThanIntFactory::~GreaterThanIntFactory() = default;

void GreaterThanIntFactory::init()
{
}

EntityInstancePtrOpt GreaterThanIntFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(GreaterThanInt::TYPE_NAME)
        ->attribute(GreaterThanInt::INPUT_1, 0)
        ->attribute(GreaterThanInt::INPUT_2, 0)
        ->attribute(GreaterThanInt::RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
