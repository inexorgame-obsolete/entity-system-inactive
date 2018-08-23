// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_TYPE_VALIDATION_HEADER
#define INEXOR_ENTSYS_TYPE_VALIDATION_HEADER

#include "../data-validation/DataValidationResults.hpp"


namespace inexor {
namespace entity_system {


    // A base class for data validation in entity system classes.
	// Every class which inherits from this is required
	// to implement a data validation method!
    class DataValidation
    {
        protected:

            DataValidation();

            ~DataValidation();

        public:

            // Every class which inherits from DataValidation needs
            // to have an implementation of this method!
            virtual ENTSYS_DATA_VALIDATION_RESULT validate() = 0;

    };

};
};

#endif // INEXOR_ENTSYS_TYPE_VALIDATION_HEADER
