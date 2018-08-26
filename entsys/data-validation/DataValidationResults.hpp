// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

namespace inexor {
namespace entity_system {


	// Data validation codes for entity system.
	enum ENTSYS_DATA_VALIDATION_RESULT
	{
		// Error codes here:
		ENTSYS_DATA_INVALID = -10000,
		ENTSYS_DATA_INVALID_ENTITY_TYPE_NAME_UNDEFINED,

		// Success codes here:
		ENTSYS_DATA_VALID = 1,
	};

};
};
