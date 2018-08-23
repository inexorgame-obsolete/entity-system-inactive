// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "../../../tests/EntitySystemDebugging.hpp"
#include "../../../data-container/DataContainer.hpp"
#include "../../../return-codes/ReturnCodes.hpp"
#include "../../../data-validation/DataValidation.hpp"


namespace inexor {
namespace entity_system {
    

	// 
    class EntityAttributeType : public DataValidation
    {
        protected:

			std::string entity_attribute_type_name;

		protected:

			// TODO: add data/methods here!

        public:

			// Remove the default constructor!
			EntityAttributeType() = delete;

            EntityAttributeType(const std::string&);

            ~EntityAttributeType();

			// Returns the name of the entity attribute type.
			std::string get_entity_attribute_type_name() const;

			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

    };
    

};
};
