#include "TrigonometricFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

TrigonometricFactories::TrigonometricFactories(SinFactoryPtr sin_factory, CosFactoryPtr cos_factory)
{
    this->sin_factory = std::move(sin_factory);
    this->cos_factory = std::move(cos_factory);
}

TrigonometricFactories::~TrigonometricFactories() = default;

void TrigonometricFactories::init()
{
    sin_factory->init();
    cos_factory->init();
}

} // namespace inexor::entity_system::type_system
