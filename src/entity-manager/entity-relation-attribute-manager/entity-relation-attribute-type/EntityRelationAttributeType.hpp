// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "../../../return-codes/ReturnCodes.hpp"
#include "../../../data-validation/DataValidationBase.hpp"
#include "../../../data-container/DataTypes.hpp"
#include "../../../base-classes/TypeBase.hpp"
#include "../../../base-classes/AttributeBase.hpp"
#include "../../../base-classes/GUID/GUIDBase.hpp"


namespace inexor {
namespace entity_system {
    

	/// A base class for entity relation attribute types.
    class EntityRelationAttributeType : public TypeBase,
		                                public AttributeBase,
		                                public GUIDBase
    {
        public:

			/// Constructor.
			/// @param ent_rel_attr_type_name The name of the new entity relation attribute type.
			/// @param ent_rel_attr_type_data_type The data type of the new entity relation attribute type.
			/// @note the GUID of the new entity relation attribute type will
			/// be created automatically by the inheritance of GUIDBase!
			EntityRelationAttributeType(const std::string&, const ENTSYS_DATA_TYPE&);

			/// Destructor.
			~EntityRelationAttributeType();

			/// Implement a data validation method as
			/// required by class inheritance of DataValidation!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

	};


};
};
