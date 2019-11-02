#pragma once

#include <magic_enum.hpp>

namespace inexor::entity_system {

/// @class ENTSYS_DATA_TYPE
/// @brief Data container memory type.
/// TODO: Think about how to handle binary data
/// TODO: Add VEC3, VEC4...
enum DataType { BOOL = 0, INT, BIG_INT, DOUBLE, FLOAT, STRING /*, VEC3, VEC4 */ };

/// @class Features
/// @brief The features on a attribute.
enum class Features { ENGINE_INPUT = 1 << 0, INPUT = 1 << 1, OUTPUT = 1 << 2, SYNC_SERVER = 1 << 3, SYNC_BROADCAST_CLIENTS = 1 << 4, SERVER_CONFIG = 1 << 5, CLIENT_CONFIG = 1 << 6 };

} // namespace inexor::entity_system
