#include <type-system/factories/logical/gates/NotFactory.hpp>

#include <type-system/types/logical/gates/Not.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

NotFactory::NotFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

NotFactory::~NotFactory() = default;

std::string NotFactory::get_component_name()
{
    return "NotFactory";
}

EntityInstancePtrOpt NotFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(Not::TYPE_NAME)->attribute(Not::INPUT, false)->attribute(Not::RESULT, true)->build();
}

} // namespace inexor::entity_system::type_system
