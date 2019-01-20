// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "entity-system/model/base/attribute/AttributeBase.hpp"
#include "entity-system/model/base/type/TypeBase.hpp"
#include "entity-system/util/return-codes/ReturnCodes.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {
    

    /// @class EntityAttributeType.
	/// @brief A base class for entity attribute types.
    class EntityAttributeType : public TypeBase, public AttributeBase, public GUIDBase
    {
        public:
				
			/// @brief Constructor.
			/// @param ent_attr_type_name The name of the new entity attribute type.
			/// @param ent_attr_type_datatype The data type of the new entity attribute type.
			/// @note the GUID of the new entity attribute type will be created automatically by the inheritance of GUIDBase!
			EntityAttributeType(const std::string&, const ENTSYS_DATA_TYPE&);


            /// @brief Constructor
            /// @param ent_attr_type_GUID The GUID of the new entity attribute type.
			/// @param ent_attr_type_name The name of the new entity attribute type.
			/// @param ent_attr_type_datatype The data type of the new entity attribute type.
			/// @note the GUID of the new entity attribute type will be created automatically by the inheritance of GUIDBase!
            EntityAttributeType(const xg::Guid&, const std::string&, const ENTSYS_DATA_TYPE&);


			/// @brief Destructor.
			~EntityAttributeType();


			/// Implement a data validation method as
			/// required by class inheritance of DataValidation!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

	};


};
};
