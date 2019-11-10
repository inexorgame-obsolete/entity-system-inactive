#include "AddFloatFactory.hpp"

#include <utility>

#include "type-system/types/math/arithmetic/AddFloat.hpp"

namespace inexor::entity_system::type_system {

AddFloatFactory::AddFloatFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

AddFloatFactory::~AddFloatFactory() = default;

std::string AddFloatFactory::get_component_name()
{
    return "AddFloatFactory";
}

EntityInstancePtrOpt AddFloatFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(AddFloat::TYPE_NAME)
        ->attribute(AddFloat::AUGEND, 0)
        ->attribute(AddFloat::ADDEND, 0)
        ->attribute(AddFloat::SUM, 0)
        ->build();
}

} // namespace inexor::entity_system::type_system
