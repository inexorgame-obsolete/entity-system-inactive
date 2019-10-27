#include "AddFloatFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

AddFloatFactory::AddFloatFactory(AddFloatEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

AddFloatFactory::~AddFloatFactory() = default;

void AddFloatFactory::init()
{
}

EntityInstancePtrOpt AddFloatFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(AddFloatEntityTypeProvider::ADD_FLOAT_AUGEND, 0)
        ->attribute(AddFloatEntityTypeProvider::ADD_FLOAT_ADDEND, 0)
        ->attribute(AddFloatEntityTypeProvider::ADD_FLOAT_SUM, 0)
        ->build();
}

} // namespace inexor::entity_system::type_system
