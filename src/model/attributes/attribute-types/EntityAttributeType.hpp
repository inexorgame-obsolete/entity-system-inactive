// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "../../../util/error-handling/ReturnCodes.hpp"
#include "../../../model/base/type/TypeBase.hpp"
#include "../../../model/base/attribute/AttributeBase.hpp"
#include "../../../util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {
    

	/// A base class for entity attribute types.
    class EntityAttributeType : public TypeBase, public AttributeBase, public GUIDBase
    {
        public:
				
			/// Constructor.
			/// @param ent_attr_type_name The name of the new entity attribute type.
			/// @param ent_attr_data_type The data type of the new entity attribute type.
			/// @note the GUID of the new entity attribute type will
			/// be created automatically by the inheritance of GUIDBase!
			EntityAttributeType(const std::string&, const ENTSYS_DATA_TYPE&);

			/// Destructor.
			~EntityAttributeType();

			/// Implement a data validation method as
			/// required by class inheritance of DataValidation!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

	};


};
};
