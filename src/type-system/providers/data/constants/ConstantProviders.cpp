#include "ConstantProviders.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

ConstantProviders::ConstantProviders(BoolConstantEntityTypeProviderPtr bool_constant_entity_type_provider
                                     //		FloatConstantEntityTypeProvider float_constant_entity_type_provider,
                                     //		IntConstantEntityTypeProvider int_constant_entity_type_provider,
                                     //		StringConstantEntityTypeProvider string_constant_entity_type_provider
)
{
    this->bool_constant_entity_type_provider = std::move(bool_constant_entity_type_provider);
    //		this->float_constant_entity_type_provider = float_constant_entity_type_provider;
    //		this->int_constant_entity_type_provider = int_constant_entity_type_provider;
    //		this->string_constant_entity_type_provider = string_constant_entity_type_provider;
}

ConstantProviders::~ConstantProviders() = default;

void ConstantProviders::init()
{
}

} // namespace inexor::entity_system::type_system
