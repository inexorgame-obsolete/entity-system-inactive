// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_TYPE_VALIDATION_HEADER
#define INEXOR_ENTSYS_TYPE_VALIDATION_HEADER

#include "../return-codes/ReturnCodes.hpp"


namespace inexor {
namespace entsys {

    // This server as a base class for data validation in classes.
    class DataValidation
    {
        private:
            
            // If the data is valid according to
            // the validation method this will bet set to true.
            bool data_is_valid = false;

        protected:
            
            DataValidation();

            ~DataValidation();

        public:

            // Is the data of this class valid?
            bool isvalid();

            // Every class which inherits from DataValidation needs
            // to have an implementation of this method!
            virtual ENTSYS_RETURN_CODE validate() = 0;

    };

};
};

#endif // INEXOR_ENTSYS_TYPE_VALIDATION_HEADER
