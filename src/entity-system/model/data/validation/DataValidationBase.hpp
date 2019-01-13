// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include "DataValidationResults.hpp"


namespace inexor {
namespace entity_system {


    /// A base class for data validation in entity system classes.
	class DataValidationBase
    {

        public:

			/// Constructor.
			DataValidationBase();

			/// Destructor.
			~DataValidationBase();

			/// This data validation method must be implemented
			/// by every class which inherits from this base class!
            virtual ENTSYS_DATA_VALIDATION_RESULT validate() = 0;

    };


};
};
