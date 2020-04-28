#include <type-system/factories/TypeSystemFactories.hpp>

#include <utility>

namespace inexor::entity_system::type_system {

TypeSystemFactories::TypeSystemFactories(DataFactoriesPtr data_factories, InOutFactoriesPtr in_out_factories, GeneratorFactoriesPtr generator_factories, LogicalFactoriesPtr logical_factories, MathFactoriesPtr math_factories)
    : LifeCycleComponent(data_factories, in_out_factories, generator_factories, logical_factories, math_factories)
{
    this->data_factories = std::move(data_factories);
    this->in_out_factories = std::move(in_out_factories);
    this->generator_factories = std::move(generator_factories);
    this->logical_factories = std::move(logical_factories);
    this->math_factories = std::move(math_factories);
}

TypeSystemFactories::~TypeSystemFactories() = default;

std::string TypeSystemFactories::get_component_name()
{
    return "TypeSystemFactories";
}

InOutFactoriesPtr TypeSystemFactories::get_in_out_factories()
{
    return in_out_factories;
}

} // namespace inexor::entity_system::type_system
