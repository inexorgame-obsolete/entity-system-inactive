#include "NandFactory.hpp"

#include <type-system/types/logical/gates/Nand.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

NandFactory::NandFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

NandFactory::~NandFactory() = default;

void NandFactory::init()
{
}

EntityInstancePtrOpt NandFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(Nand::TYPE_NAME)
        ->attribute(Nand::INPUT_1, false)
        ->attribute(Nand::INPUT_2, false)
        ->attribute(Nand::RESULT, true)
        ->build();
}

} // namespace inexor::entity_system::type_system
