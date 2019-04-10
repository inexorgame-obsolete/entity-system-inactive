#pragma once

#include "entity-system/model/base/attribute/AttributeBase.hpp"
#include "entity-system/model/base/type/TypeBase.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/return-codes/ReturnCodes.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"

#include <string>

namespace inexor {
namespace entity_system {

	/// @class EntityAttributeType
	/// @brief A base class for entity attribute types.
	class EntityAttributeType : public TypeBase, public AttributeBase, public GUIDBase
	{
		public:

			/// @brief Constructor.
			/// @note the GUID of the new entity attribute type will be created automatically by the inheritance of GUIDBase!
			/// @param ent_attr_type_name The name of the new entity attribute type.
			/// @param ent_attr_type_datatype The data type of the new entity attribute type.
			/// @param ent_attr_type_features The features of the new entity attribute type.
			EntityAttributeType(const std::string& ent_attr_type_name, const DataType& ent_attr_type_datatype, const EnumSet<Feature>& ent_attr_type_features);

			/// @brief Constructor
			/// @note the GUID of the new entity attribute type will be created automatically by the inheritance of GUIDBase!
			/// @param ent_attr_type_GUID The GUID of the new entity attribute type.
			/// @param ent_attr_type_name The name of the new entity attribute type.
			/// @param ent_attr_type_datatype The data type of the new entity attribute type.
			/// @param ent_attr_type_features The features of the new entity attribute type.
			EntityAttributeType(const xg::Guid& ent_attr_type_GUID, const std::string& ent_attr_type_name, const DataType& ent_attr_type_datatype, const EnumSet<Feature>& ent_attr_type_features);

			/// Destructor.
			~EntityAttributeType();

	};

}
}
