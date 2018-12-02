// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../data-validation/DataValidationResults.hpp"


namespace inexor {
namespace entity_system {


    /// @brief A base class for data validation in entity system classes.
	class DataValidation
    {

        public:

			/// Constructor.
			DataValidation();

			/// Destructor.
			~DataValidation();

            /// Every class which inherits from DataValidation must have an implementation of this pure virtual validation method!
            virtual ENTSYS_DATA_VALIDATION_RESULT validate() = 0;

    };


};
};
