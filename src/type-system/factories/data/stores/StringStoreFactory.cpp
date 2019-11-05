#include "StringStoreFactory.hpp"

#include <type-system/types/data/store/StringStore.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

StringStoreFactory::StringStoreFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

StringStoreFactory::~StringStoreFactory() = default;

void StringStoreFactory::init()
{
}

EntityInstancePtrOpt StringStoreFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(StringStore::TYPE_NAME)
        ->attribute(StringStore::NAME, "")
        ->attribute(StringStore::INPUT_VALUE, "")
        ->attribute(StringStore::DEFAULT_VALUE, "")
        ->attribute(StringStore::OUTPUT_VALUE, "")
        ->build();
}

EntityInstancePtrOpt StringStoreFactory::create_instance(const std::string &name, const std::string &input_value, const std::string &default_value, const std::string &output_value)
{
    return entity_instance_builder_factory->get_builder(StringStore::TYPE_NAME)
        ->attribute(StringStore::NAME, name)
        ->attribute(StringStore::INPUT_VALUE, input_value)
        ->attribute(StringStore::DEFAULT_VALUE, default_value)
        ->attribute(StringStore::OUTPUT_VALUE, output_value)
        ->build();
}

} // namespace inexor::entity_system::type_system
