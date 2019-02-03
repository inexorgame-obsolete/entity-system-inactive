// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#define BETTER_ENUMS_DEFAULT_CONSTRUCTOR(Enum) \
  public:                                      \
    Enum() = default;

#include <better-enums/enum.h>


namespace inexor {
namespace entity_system {

	/// @class ENTSYS_DATA_TYPE
	/// @brief Data container memory type.
	BETTER_ENUM(DataType, int, BOOL = 0, INT, BIG_INT, DOUBLE, FLOAT, STRING, VEC3, VEC4)

	// TODO: Think about how to handle binary data

};
};
