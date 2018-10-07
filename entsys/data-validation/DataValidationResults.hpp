// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

namespace inexor {
namespace entity_system {


	// Data validation codes for entity system.
	// TODO: Add new data validation result codes here?
	enum ENTSYS_DATA_VALIDATION_RESULT
	{
		ENTSYS_DATA_INVALID = -1,
		ENTSYS_DATA_INVALID_ENTITY_TYPE_NAME_UNDEFINED = -2,
		ENTSYS_DATA_VALID = 1,
	};


};
};
