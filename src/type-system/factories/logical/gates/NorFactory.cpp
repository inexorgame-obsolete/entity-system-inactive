#include "NorFactory.hpp"

#include <type-system/types/logical/gates/Nor.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

NorFactory::NorFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

NorFactory::~NorFactory() = default;

std::string NorFactory::get_component_name()
{
    return "NorFactory";
}

EntityInstancePtrOpt NorFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(Nor::TYPE_NAME)
        ->attribute(Nor::INPUT_1, false)
        ->attribute(Nor::INPUT_2, false)
        ->attribute(Nor::RESULT, true)
        ->build();
}

} // namespace inexor::entity_system::type_system
