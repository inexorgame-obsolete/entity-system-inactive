#include "TypeSystemProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

TypeSystemProviders::TypeSystemProviders(EntityTypeBuilderFactoryPtr entity_type_builder_factory, GeneratorProvidersPtr generator_providers, InOutProvidersPtr in_out_providers,
                                         LogicalProvidersPtr logical_providers)
{
    this->entity_type_builder_factory = std::move(entity_type_builder_factory);
    this->generator_providers = std::move(generator_providers);
    this->in_out_providers = std::move(in_out_providers);
    this->logical_providers = std::move(logical_providers);
}

TypeSystemProviders::~TypeSystemProviders() = default;

void TypeSystemProviders::init()
{
    entity_type_builder_factory->init();
//    generator_providers->init();
    in_out_providers->init();
//    logical_providers->init();
}

} // namespace inexor::entity_system::type_system
