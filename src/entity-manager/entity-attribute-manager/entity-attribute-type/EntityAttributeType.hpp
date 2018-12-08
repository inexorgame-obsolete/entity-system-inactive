// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "../../../return-codes/ReturnCodes.hpp"
#include "../../../base-classes/TypeBase.hpp"
#include "../../../base-classes/AttributeTypeBase.hpp"


namespace inexor {
namespace entity_system {
    

	/// A base class for entity attribute types.
    class EntityAttributeType : public TypeBase, public AttributeTypeBase
    {
        public:
				
			/// Constructor.
			/// @param ent_attr_type_name The name of the new entity attribute type.
			/// @param ent_attr_data_type The data type of the new entity attribute type.
			EntityAttributeType(const std::string&, const ENTSYS_DATA_TYPE&);

			/// Destructor.
			~EntityAttributeType();

			/// Implement a data validation method as
			/// required by class inheritance of DataValidation!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

	};


};
};
