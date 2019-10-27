#include "TypeSystemFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

TypeSystemFactories::TypeSystemFactories(DataFactoriesPtr data_factories, InOutFactoriesPtr in_out_factories, GeneratorFactoriesPtr generator_factories, LogicalFactoriesPtr logical_factories, MathFactoriesPtr math_factories)
{
    this->data_factories = std::move(data_factories);
    this->in_out_factories = std::move(in_out_factories);
    this->generator_factories = std::move(generator_factories);
    this->logical_factories = std::move(logical_factories);
    this->math_factories = std::move(math_factories);
}

TypeSystemFactories::~TypeSystemFactories() = default;

void TypeSystemFactories::init()
{
    data_factories->init();
    in_out_factories->init();
    generator_factories->init();
    logical_factories->init();
    math_factories->init();
}

InOutFactoriesPtr TypeSystemFactories::get_in_out_factories()
{
    return in_out_factories;
}

} // namespace inexor::entity_system::type_system
