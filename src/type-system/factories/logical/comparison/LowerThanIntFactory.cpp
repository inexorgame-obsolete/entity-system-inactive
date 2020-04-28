#include <type-system/factories/logical/comparison/LowerThanIntFactory.hpp>

#include <type-system/types/logical/comparison/LowerThanInt.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

LowerThanIntFactory::LowerThanIntFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

LowerThanIntFactory::~LowerThanIntFactory() = default;

std::string LowerThanIntFactory::get_component_name()
{
    return "LowerThanIntFactory";
}

EntityInstancePtrOpt LowerThanIntFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(LowerThanInt::TYPE_NAME)
        ->attribute(LowerThanInt::INPUT_1, 0)
        ->attribute(LowerThanInt::INPUT_2, 0)
        ->attribute(LowerThanInt::RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
