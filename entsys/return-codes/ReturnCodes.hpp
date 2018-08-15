// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_RESULT_CODE_ENUM_HEADER
#define INEXOR_ENTSYS_RESULT_CODE_ENUM_HEADER


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

#endif // INEXOR_ENTSYS_RESULT_CODE_ENUM_HEADER
