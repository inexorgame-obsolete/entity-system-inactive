#pragma once

#include "base/LifeCycleComponent.hpp"
#include "type-system/factories/logical/gates/AndFactory.hpp"
#include "type-system/factories/logical/gates/NandFactory.hpp"
#include "type-system/factories/logical/gates/NorFactory.hpp"
#include "type-system/factories/logical/gates/NotFactory.hpp"
#include "type-system/factories/logical/gates/OrFactory.hpp"
#include "type-system/factories/logical/gates/XorFactory.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using NotFactoryPtr = std::shared_ptr<NotFactory>;
using OrFactoryPtr = std::shared_ptr<OrFactory>;
using AndFactoryPtr = std::shared_ptr<AndFactory>;
using XorFactoryPtr = std::shared_ptr<XorFactory>;
using NorFactoryPtr = std::shared_ptr<NorFactory>;
using NandFactoryPtr = std::shared_ptr<NandFactory>;

/// @class GateFactories
/// @brief The factories for logical operations.
class GateFactories : public LifeCycleComponent
{
    public:
    /// @brief Constructs the factories for logical operations.
    /// @note The dependencies of this class will be injected automatically.
    /// @param not_factory Factory for creating entity instances of type NOT.
    /// @param or_factory Factory for creating entity instances of type OR.
    /// @param and_factory Factory for creating entity instances of type AND.
    /// @param xor_factory Factory for creating entity instances of type XOR.
    /// @param nor_factory Factory for creating entity instances of type NOR.
    /// @param nand_factory Factory for creating entity instances of type NAND.
    GateFactories(NotFactoryPtr not_factory, OrFactoryPtr or_factory, AndFactoryPtr and_factory, XorFactoryPtr xor_factory, NorFactoryPtr nor_factory, NandFactoryPtr nand_factory);

    /// Destructor.
    ~GateFactories();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Factory for creating entity instances of type NOT.
    NotFactoryPtr not_factory;

    /// Factory for creating entity instances of type OR.
    OrFactoryPtr or_factory;

    /// Factory for creating entity instances of type AND.
    AndFactoryPtr and_factory;

    /// Factory for creating entity instances of type XOR.
    XorFactoryPtr xor_factory;

    /// Factory for creating entity instances of type NOR.
    NorFactoryPtr nor_factory;

    /// Factory for creating entity instances of type NAND.
    NandFactoryPtr nand_factory;
};

} // namespace inexor::entity_system::type_system
