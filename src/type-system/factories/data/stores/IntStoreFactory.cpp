#include "IntStoreFactory.hpp"

#include <type-system/types/data/store/IntStore.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

IntStoreFactory::IntStoreFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

IntStoreFactory::~IntStoreFactory() = default;

void IntStoreFactory::init()
{
}

EntityInstancePtrOpt IntStoreFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(IntStore::TYPE_NAME)
        ->attribute(IntStore::NAME, "")
        ->attribute(IntStore::INPUT_VALUE, 0)
        ->attribute(IntStore::DEFAULT_VALUE, 0)
        ->attribute(IntStore::OUTPUT_VALUE, 0)
        ->build();
}

EntityInstancePtrOpt IntStoreFactory::create_instance(const std::string &name, const int &input_value, const int &default_value, const int &output_value)
{
    return entity_instance_builder_factory->get_builder(IntStore::TYPE_NAME)
        ->attribute(IntStore::NAME, name)
        ->attribute(IntStore::INPUT_VALUE, input_value)
        ->attribute(IntStore::DEFAULT_VALUE, default_value)
        ->attribute(IntStore::OUTPUT_VALUE, output_value)
        ->build();
}

} // namespace inexor::entity_system::type_system
