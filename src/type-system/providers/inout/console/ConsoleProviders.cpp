#include "ConsoleProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

ConsoleProviders::ConsoleProviders(StdInEntityTypeProviderPtr std_in_entity_type_provider, StdOutEntityTypeProviderPtr std_out_entity_type_provider, StdErrEntityTypeProviderPtr std_err_entity_type_provider)
{
    this->std_in_entity_type_provider = std::move(std_in_entity_type_provider);
    this->std_out_entity_type_provider = std::move(std_out_entity_type_provider);
    this->std_err_entity_type_provider = std::move(std_err_entity_type_provider);
}

ConsoleProviders::~ConsoleProviders() = default;

void ConsoleProviders::init()
{
}

} // namespace inexor::entity_system::type_system
