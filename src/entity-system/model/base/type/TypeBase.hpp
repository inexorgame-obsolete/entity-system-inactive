#pragma once

#include "entity-system/model/base/guid/GUIDBase.hpp"

#include <string>

namespace inexor::entity_system {

/// @class TypeBase
/// @brief A base class for types.
class TypeBase
{
    private:
    /// The unique name of this type.
    std::string type_title;

    /// The mutex of this class.
    std::mutex type_base_mutex;

    protected:
    /// @brief Constructor.
    /// @param type_name The unique name of this type.
    explicit TypeBase(const std::string &type_name);

    /// @brief Destructor.
    ~TypeBase();

    public:
    /// @brief Returns the name of this type.
    /// @return The name of this type.
    [[nodiscard]] std::string get_type_name() const;
};

} // namespace inexor::entity_system
