#include "NandFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

NandFactory::NandFactory(NandEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

NandFactory::~NandFactory() = default;

void NandFactory::init()
{
}

EntityInstancePtrOpt NandFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(NandEntityTypeProvider::NAND_INPUT_1, false)
        ->attribute(NandEntityTypeProvider::NAND_INPUT_2, false)
        ->attribute(NandEntityTypeProvider::NAND_RESULT, true)
        ->build();
}

} // namespace inexor::entity_system::type_system
