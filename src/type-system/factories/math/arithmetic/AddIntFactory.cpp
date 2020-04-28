#include <type-system/factories/math/arithmetic/AddIntFactory.hpp>

#include <utility>

#include "type-system/types/math/arithmetic/AddInt.hpp"

namespace inexor::entity_system::type_system {

AddIntFactory::AddIntFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

AddIntFactory::~AddIntFactory() = default;

std::string AddIntFactory::get_component_name()
{
    return "AddIntFactory";
}

EntityInstancePtrOpt AddIntFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(AddInt::TYPE_NAME)
        ->attribute(AddInt::AUGEND, 0)
        ->attribute(AddInt::ADDEND, 0)
        ->attribute(AddInt::SUM, 0)
        ->build();
}

} // namespace inexor::entity_system::type_system
