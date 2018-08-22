// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

namespace inexor {
namespace entity_system {


	// Return codes for entity system.
	enum ENTSYS_RESULT
    {
		// Error codes here:
        ENTSYS_ERROR = -10000,
		ENTSYS_ERROR_DATA_INVALID,
		ENTSYS_ERROR_DATA_DUPLICATE,

		// Success codes here:
        ENTSYS_SUCCESS = 1,
    };


};
};
