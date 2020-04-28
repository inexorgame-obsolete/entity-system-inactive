#include <type-system/factories/logical/comparison/EqualsStringFactory.hpp>

#include <type-system/types/logical/comparison/EqualsString.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

EqualsStringFactory::EqualsStringFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

EqualsStringFactory::~EqualsStringFactory() = default;

std::string EqualsStringFactory::get_component_name()
{
    return "EqualsStringFactory";
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
