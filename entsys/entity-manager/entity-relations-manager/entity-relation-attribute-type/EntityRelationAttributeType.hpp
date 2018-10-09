// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "../../../return-codes/ReturnCodes.hpp"
#include "../../../data-validation/DataValidation.hpp"
#include "../../../data-container/DataTypes.hpp"
#include "../../../base-classes/TypeBase.hpp"
#include "../../../base-classes/AttributeBase.hpp"


namespace inexor {
namespace entity_system {
    

	// A base class for types of entity attributes.
	// This class MUST implement a data validation method because of inheritance rules!
    class EntityRelationAttributeType : public TypeBase, public AttributeBase
    {
        public:
						
			EntityRelationAttributeType(const std::string&, const ENTSYS_DATA_TYPE&);
			~EntityRelationAttributeType();

			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

	};


};
};
