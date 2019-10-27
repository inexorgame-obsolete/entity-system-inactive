#pragma once

#include "type-system/providers/inout/console/StdErrEntityTypeProvider.hpp"
#include "type-system/providers/inout/console/StdInEntityTypeProvider.hpp"
#include "type-system/providers/inout/console/StdOutEntityTypeProvider.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using StdInEntityTypeProviderPtr = std::shared_ptr<StdInEntityTypeProvider>;
using StdOutEntityTypeProviderPtr = std::shared_ptr<StdOutEntityTypeProvider>;
using StdErrEntityTypeProviderPtr = std::shared_ptr<StdErrEntityTypeProvider>;

/// @class ConsoleProviders
/// @brief The console entity type providers.
class ConsoleProviders
{
    public:
    /// @brief Constructs the entity type providers for the console handling.
    /// @note The dependencies of this class will be injected automatically.
    /// @param std_in_entity_type_provider Provides the entity type CONSOLE_STDIN.
    /// @param std_out_entity_type_provider Provides the entity type CONSOLE_STDOUT.
    /// @param std_err_entity_type_provider Provides the entity type CONSOLE_STDERR.
    ConsoleProviders(StdInEntityTypeProviderPtr std_in_entity_type_provider, StdOutEntityTypeProviderPtr std_out_entity_type_provider, StdErrEntityTypeProviderPtr std_err_entity_type_provider);

    /// Destructor.
    ~ConsoleProviders();

    /// Initializes the console entity type providers for the console handling.
    void init();

    private:
    /// Provides the entity type CONSOLE_STDIN.
    StdInEntityTypeProviderPtr std_in_entity_type_provider;

    /// Provides the entity type CONSOLE_STDOUT.
    StdOutEntityTypeProviderPtr std_out_entity_type_provider;

    /// Provides the entity type CONSOLE_STDERR.
    StdErrEntityTypeProviderPtr std_err_entity_type_provider;
};

} // namespace inexor::entity_system::type_system
