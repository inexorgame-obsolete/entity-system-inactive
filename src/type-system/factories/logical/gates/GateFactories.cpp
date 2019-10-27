#include "GateFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

GateFactories::GateFactories(NotFactoryPtr not_factory, OrFactoryPtr or_factory, AndFactoryPtr and_factory, XorFactoryPtr xor_factory, NorFactoryPtr nor_factory, NandFactoryPtr nand_factory)
{
    this->not_factory = std::move(not_factory);
    this->or_factory = std::move(or_factory);
    this->and_factory = std::move(and_factory);
    this->xor_factory = std::move(xor_factory);
    this->nor_factory = std::move(nor_factory);
    this->nand_factory = std::move(nand_factory);
}

GateFactories::~GateFactories() = default;

void GateFactories::init()
{
    not_factory->init();
    or_factory->init();
    and_factory->init();
    xor_factory->init();
    nor_factory->init();
    nand_factory->init();
}

} // namespace inexor::entity_system::type_system
