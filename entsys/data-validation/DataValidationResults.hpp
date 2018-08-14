// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_DATA_VALIDATION_RESULT_CODE_ENUM_HEADER
#define INEXOR_ENTSYS_DATA_VALIDATION_RESULT_CODE_ENUM_HEADER


namespace inexor {
namespace entity_system {


	// Data validation codes for entity system.
	enum ENTSYS_DATA_VALIDATION_RESULT
	{
		// Error codes here:
		ENTSYS_DATA_INVALID_ENTITY_TYPE_NAME_UNDEFINED = -10000,

		// Success codes here:
		ENTSYS_DATA_VALID = 1,
	};

};
};


#endif // INEXOR_ENTSYS_DATA_VALIDATION_RESULT_CODE_ENUM_HEADER
