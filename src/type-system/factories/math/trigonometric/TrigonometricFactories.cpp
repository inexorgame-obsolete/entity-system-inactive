#include "TrigonometricFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

TrigonometricFactories::TrigonometricFactories(SinFactoryPtr sin_factory, CosFactoryPtr cos_factory, TanFactoryPtr tan_factory)
{
    this->sin_factory = std::move(sin_factory);
    this->cos_factory = std::move(cos_factory);
    this->tan_factory = std::move(tan_factory);
}

TrigonometricFactories::~TrigonometricFactories() = default;

void TrigonometricFactories::init()
{
    sin_factory->init();
    cos_factory->init();
    tan_factory->init();
}

} // namespace inexor::entity_system::type_system
