#include "TrigonometricFactories.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

TrigonometricFactories::TrigonometricFactories(SinFactoryPtr sin_factory, CosFactoryPtr cos_factory, TanFactoryPtr tan_factory)
    : LifeCycleComponent(sin_factory, cos_factory, tan_factory)
{
    this->sin_factory = std::move(sin_factory);
    this->cos_factory = std::move(cos_factory);
    this->tan_factory = std::move(tan_factory);
}

TrigonometricFactories::~TrigonometricFactories() = default;

std::string TrigonometricFactories::get_component_name()
{
    return "TrigonometricFactories";
}

} // namespace inexor::entity_system::type_system
