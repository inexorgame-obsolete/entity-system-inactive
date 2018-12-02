// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "../../../return-codes/ReturnCodes.hpp"
#include "../../../base-classes/TypeBase.hpp"
#include "../../../base-classes/AttributeBase.hpp"


namespace inexor {
namespace entity_system {
    

	/// A base class for types of entity attributes.
    class EntityAttributeType : public TypeBase, public AttributeBase
    {
        public:
				
			/// Constructor.
			/// @param ? TODO
			/// @param ? TODO
			EntityAttributeType(const std::string&, const ENTSYS_DATA_TYPE&);

			/// Destructor.
			~EntityAttributeType();

			/// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

	};


};
};
