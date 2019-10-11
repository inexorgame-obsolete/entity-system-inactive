#pragma once

#include "entity-system/model/base/attribute/AttributeBase.hpp"
#include "entity-system/model/base/type/TypeBase.hpp"

#include <vector>
#include <unordered_map>

namespace inexor {
namespace entity_system {

	/// @class RelationAttributeType
	/// @brief A base class for entity relation attribute types.
	class RelationAttributeType : public TypeBase, public AttributeBase, public GUIDBase
	{
		public:

			/// @brief Constructs the relation attribute type.
			/// @note The GUID of this relation attribute type will be created automatically by inheriting from GUIDBase!
			/// @param rel_attr_type_name The name of this relation attribute type.
			/// @param rel_attr_type_data_type The data type of this relation attribute type.
			/// @param rel_attr_type_features The features of this relation attribute type.
			RelationAttributeType(const std::string& rel_attr_type_name, const DataType& rel_attr_type_data_type, const EnumSet<Feature>& rel_attr_type_features);

			/// @brief Destructs the relation attribute type.
			~RelationAttributeType();

	};

}
}
