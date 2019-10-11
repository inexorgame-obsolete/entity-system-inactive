#pragma once

#define BETTER_ENUMS_DEFAULT_CONSTRUCTOR(Enum) \
	public:                                    \
	Enum() = default;

#include <bitset>
#include <better-enums/enum.h>

template <typename Enum>
constexpr Enum max_loop(Enum accumulator, size_t index)
{
	return
		index >= Enum::_size() ? accumulator :
		Enum::_values()[index] > accumulator ?
		max_loop<Enum>(Enum::_values()[index], index + 1) :
		max_loop<Enum>(accumulator, index + 1);
}

template <typename Enum>
constexpr Enum max()
{
	return max_loop<Enum>(Enum::_values()[0], 1);
}

/// Declaration of bit set (bitmask) template.
template <typename Enum>
using EnumSet = std::bitset<7>;

namespace inexor {
namespace entity_system {

	/// @class ENTSYS_DATA_TYPE
	/// @brief Data container memory type.
	/// TODO: Think about how to handle binary data
	/// TODO: Add VEC3, VEC4...
	BETTER_ENUM(DataType, int, BOOL = 0, INT, BIG_INT, DOUBLE, FLOAT, STRING /*, VEC3, VEC4 */)

	/// @class Features
	/// @brief The features on a attribute.
	BETTER_ENUM(Feature, int, ENGINE_INPUT = 0, INPUT, OUTPUT, SYNC_SERVER, SYNC_BROADCAST_CLIENTS, SERVER_CONFIG, CLIENT_CONFIG)

}
}
