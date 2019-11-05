#include "XorFactory.hpp"

#include <type-system/types/logical/gates/Xor.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

XorFactory::XorFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

XorFactory::~XorFactory() = default;

void XorFactory::init()
{
}

EntityInstancePtrOpt XorFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(Xor::TYPE_NAME)
        ->attribute(Xor::INPUT_1, false)
        ->attribute(Xor::INPUT_2, false)
        ->attribute(Xor::RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
