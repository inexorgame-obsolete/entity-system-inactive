#include "GateFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

GateFactories::GateFactories(NotFactoryPtr not_factory, OrFactoryPtr or_factory, AndFactoryPtr and_factory, XorFactoryPtr xor_factory, NorFactoryPtr nor_factory, NandFactoryPtr nand_factory)
    : LifeCycleComponent(not_factory, or_factory, and_factory, xor_factory, nor_factory, nand_factory)
{
    this->not_factory = std::move(not_factory);
    this->or_factory = std::move(or_factory);
    this->and_factory = std::move(and_factory);
    this->xor_factory = std::move(xor_factory);
    this->nor_factory = std::move(nor_factory);
    this->nand_factory = std::move(nand_factory);
}

GateFactories::~GateFactories() = default;

std::string GateFactories::get_component_name()
{
    return "GateFactories";
}

} // namespace inexor::entity_system::type_system
