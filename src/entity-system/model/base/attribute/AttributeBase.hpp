#pragma once

#include "entity-system/model/data/container/DataContainer.hpp"

#include <optional>

namespace inexor::entity_system {

/// @class AttributeBase
/// @brief A base class for attributes.
/// @note We can't directly instantiate this class because it is an abstract class.
/// @note AttributeBase does not have a GUID, because it is an abstract base class.
/// The GUID is created by the classes which inherits from AttributeBase.
class AttributeBase
{
    private:
    /// @brief The data type of the attribute.
    /// @note The data is exclusively managed in the instance, not in this base class.
    DataType attribute_data_type{};

    /// The features of the attribute.
    Features features;

    /// The mutex of this class.
    std::mutex attribute_type_base_mutex;

    protected:
    /// @brief Constructor.
    /// @param attr_data_type The data type of the attribute.
    /// @param features A const EnumSet of the features.
    AttributeBase(const DataType &attr_data_type, const Features &features);

    /// @brief Destructor.
    ~AttributeBase();

    public:
    /// @brief Returns the data type of the attribute.
    /// @return The data type of the attribute.
    [[nodiscard]] DataType get_attribute_data_type() const;

    /// @brief Returns the features of the attribute.
    /// @return The features of the attribute.
    [[nodiscard]] Features get_attribute_features() const;
};

} // namespace inexor::entity_system
