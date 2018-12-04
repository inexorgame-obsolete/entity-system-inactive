// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../data-validation/DataValidationResults.hpp"


namespace inexor {
namespace entity_system {


    /// A base class for data validation in entity system classes.
	class DataValidation
    {

        public:

			/// Constructor.
			DataValidation();

			/// Destructor.
			~DataValidation();

			/// 
            virtual ENTSYS_DATA_VALIDATION_RESULT validate() = 0;

    };


};
};
