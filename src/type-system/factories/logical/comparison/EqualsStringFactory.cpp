#include "EqualsStringFactory.hpp"

#include <type-system/types/logical/comparison/EqualsString.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

EqualsStringFactory::EqualsStringFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

EqualsStringFactory::~EqualsStringFactory() = default;

void EqualsStringFactory::init()
{
}

EntityInstancePtrOpt EqualsStringFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(EqualsString::TYPE_NAME)
        ->attribute(EqualsString::INPUT_1, "")
        ->attribute(EqualsString::INPUT_2, "")
        ->attribute(EqualsString::RESULT, true)
        ->build();
}

} // namespace inexor::entity_system::type_system
