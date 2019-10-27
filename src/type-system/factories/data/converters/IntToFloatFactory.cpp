#include "IntToFloatFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

IntToFloatFactory::IntToFloatFactory(IntToFloatEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

IntToFloatFactory::~IntToFloatFactory() = default;

void IntToFloatFactory::init()
{
}

EntityInstancePtrOpt IntToFloatFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()->type(entity_type_provider->get_type())->attribute(IntToFloatEntityTypeProvider::INT_TO_FLOAT_INPUT, 0)->attribute(IntToFloatEntityTypeProvider::INT_TO_FLOAT_VALUE, 0.0f)->build();
}

EntityInstancePtrOpt IntToFloatFactory::create_instance(const std::string &name, const int &int_value, const float &float_value)
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(IntToFloatEntityTypeProvider::INT_TO_FLOAT_INPUT, int_value)
        ->attribute(IntToFloatEntityTypeProvider::INT_TO_FLOAT_VALUE, float_value)
        ->build();
}

} // namespace inexor::entity_system::type_system
