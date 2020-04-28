#include <type-system/factories/inout/keyboard/GlobalKeyFactory.hpp>

#include <type-system/types/inout/keyboard/GlobalKey.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

GlobalKeyFactory::GlobalKeyFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

GlobalKeyFactory::~GlobalKeyFactory() = default;

std::string GlobalKeyFactory::get_component_name()
{
    return "GlobalKeyFactory";
}

EntityInstancePtrOpt GlobalKeyFactory::create_instance(const int &key)
{
    return entity_instance_builder_factory->get_builder(GlobalKey::TYPE_NAME)
        ->attribute(GlobalKey::KEYCODE, key)
        ->attribute(GlobalKey::ACTION, 0)
        ->attribute(GlobalKey::MODS, 0)
        ->build();
}

} // namespace inexor::entity_system::type_system
