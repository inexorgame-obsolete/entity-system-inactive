#include "FloatStoreFactory.hpp"

#include <type-system/types/data/store/FloatStore.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

FloatStoreFactory::FloatStoreFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

FloatStoreFactory::~FloatStoreFactory() = default;

std::string FloatStoreFactory::get_component_name()
{
    return "FloatStoreFactory";
}

EntityInstancePtrOpt FloatStoreFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(FloatStore::TYPE_NAME)
        ->attribute(FloatStore::NAME, "")
        ->attribute(FloatStore::INPUT_VALUE, 0.0f)
        ->attribute(FloatStore::DEFAULT_VALUE, 0.0f)
        ->attribute(FloatStore::OUTPUT_VALUE, 0.0f)
        ->build();
}

EntityInstancePtrOpt FloatStoreFactory::create_instance(const std::string &name, const float &input_value, const float &default_value, const float &output_value)
{
    return entity_instance_builder_factory->get_builder(FloatStore::TYPE_NAME)
        ->attribute(FloatStore::NAME, name)
        ->attribute(FloatStore::INPUT_VALUE, input_value)
        ->attribute(FloatStore::DEFAULT_VALUE, default_value)
        ->attribute(FloatStore::OUTPUT_VALUE, output_value)
        ->build();
}

} // namespace inexor::entity_system::type_system
