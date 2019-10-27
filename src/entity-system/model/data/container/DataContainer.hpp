#pragma once

#include "entity-system/model/data/DataTypes.hpp"

#include "react/Domain.h"
#include "react/Observer.h"
#include "react/Signal.h"

#include <cstdint>
#include <glm/glm.hpp>
#include <mutex>
#include <string>
#include <variant>

// TODO: move namespace react into namespace inexor::entity_system
using namespace react;

namespace inexor::entity_system {

/// The definition of the reactive domain, the mode and the engine.
/// https://schlangster.github.io/cpp.react/reference/Domain.h/REACTIVE_DOMAIN.html
REACTIVE_DOMAIN(D, sequential_concurrent)

USING_REACTIVE_DOMAIN(D)

/// A data value can hold any value allowed by enum DataType.
using DataValue = std::variant<bool, int, std::int64_t, double, float, std::string>;

/// @class DataContainer
/// @brief A data container which can hold data of various types.
struct DataContainer
{
    /// The mutex of this data container.
    std::mutex data_container_mutex;

    /// The data type.
    DataType type{};

    /// The own data value.
    VarSignalT<DataValue> own_value;

    /// The outer data value.
    VarSignal<D, SignalT<DataValue>> signal_wrapper;

    /// The flattened (output) value.
    SignalT<DataValue> value;

    // No default constructor because we don't have and cannot detect the data type
    // DataContainer() {};

    /// @brief Constructs a new data container using the given data type and the default value of the data type.
    /// @param type The data type.
    explicit DataContainer(const DataType &type) : type(type)
    {
        // Use lock guard to ensure thread safety during write operations!
        std::lock_guard<std::mutex> lock(data_container_mutex);

        switch (type)
        {
        case DataType::BOOL:
        {
            DataValue bool_value = false;
            this->own_value = MakeVar<D>(bool_value);
            break;
        }
        case DataType::DOUBLE:
        {
            DataValue double_value = 0.0;
            this->own_value = MakeVar<D>(double_value);
            break;
        }
        case DataType::FLOAT:
        {
            DataValue float_value = 0.0f;
            this->own_value = MakeVar<D>(float_value);
            break;
        }
        case DataType::STRING:
        {
            DataValue string_value = std::string("");
            this->own_value = MakeVar<D>(string_value);
            break;
        }
        // TODO: Add other data types!
        default:
        case DataType::INT:
        {
            DataValue int_value = 0;
            this->own_value = MakeVar<D>(int_value);
            break;
        }
        }
        this->signal_wrapper = MakeVar<D>(this->own_value);
        this->value = Flatten(this->signal_wrapper);
    }

    /// @brief Constructs a new data container using the given data type and the default value of the data type.
    /// @param data_value The value of the data container.
    explicit DataContainer(const DataValue &data_value)
    {
        // Use lock guard to ensure thread safety during write operations!
        std::lock_guard<std::mutex> lock(data_container_mutex);

        /// Detect type by std::variant index()
        this->type = DataType::_from_integral(static_cast<int>(data_value.index()));
        this->own_value = MakeVar<D>(data_value);
        this->signal_wrapper = MakeVar<D>(this->own_value);
        this->value = Flatten(this->signal_wrapper);
    };

    /// @brief Constructs a new data container using the given data type and the default value of the data type.
    /// @param type The data type of the data container.
    /// @param data_value The value of the data container.
    DataContainer(const DataType &type, const DataValue &data_value) : type(type)
    {
        // Use lock guard to ensure thread safety during write operations!
        std::lock_guard<std::mutex> lock(data_container_mutex);

        this->own_value = MakeVar<D>(data_value);
        this->signal_wrapper = MakeVar<D>(this->own_value);
        this->value = Flatten(this->signal_wrapper);
    };
};

/// @class DataContainerInitializer
/// @brief A structure for the initialisation of data containers.
struct DataContainerInitializer
{
    DataType type;
    DataValue value;
};

/// @brief Converts the value of the data container to a std::string.
/// @param type The type of the data container.
/// @param value The value of the data container.
static inline std::string data_value_to_string(DataType type, DataValue value)
{
    switch (type)
    {
    case DataType::BOOL:
        return std::get<DataType::BOOL>(value) ? "true" : "false";
    case DataType::INT:
        return std::to_string(std::get<DataType::INT>(value));
    case DataType::BIG_INT:
        return std::to_string(std::get<DataType::BIG_INT>(value));
    case DataType::DOUBLE:
        return std::to_string(std::get<DataType::DOUBLE>(value));
    case DataType::FLOAT:
        return std::to_string(std::get<DataType::FLOAT>(value));
    case DataType::STRING:
        return std::get<DataType::STRING>(value);
    default:
        return "";
    }
}

} // namespace inexor::entity_system
