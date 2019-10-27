#include "StringStoreFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

StringStoreFactory::StringStoreFactory(StringStoreEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

StringStoreFactory::~StringStoreFactory() = default;

void StringStoreFactory::init()
{
}

EntityInstancePtrOpt StringStoreFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(StringStoreEntityTypeProvider::STRING_STORE_NAME, "")
        ->attribute(StringStoreEntityTypeProvider::STRING_STORE_INPUT_VALUE, "")
        ->attribute(StringStoreEntityTypeProvider::STRING_STORE_DEFAULT_VALUE, "")
        ->attribute(StringStoreEntityTypeProvider::STRING_STORE_OUTPUT_VALUE, "")
        ->build();
}

EntityInstancePtrOpt StringStoreFactory::create_instance(const std::string &name, const std::string &input_value, const std::string &default_value, const std::string &output_value)
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(StringStoreEntityTypeProvider::STRING_STORE_NAME, name)
        ->attribute(StringStoreEntityTypeProvider::STRING_STORE_INPUT_VALUE, input_value)
        ->attribute(StringStoreEntityTypeProvider::STRING_STORE_DEFAULT_VALUE, default_value)
        ->attribute(StringStoreEntityTypeProvider::STRING_STORE_OUTPUT_VALUE, output_value)
        ->build();
}

} // namespace inexor::entity_system::type_system
