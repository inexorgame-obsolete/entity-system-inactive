// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <optional>

#include "entity-system/model/relation-attributes/relation-attribute-types/RelationAttributeType.hpp"
#include "entity-system/managers/manager-templates/TypeManagerTemplate.hpp"
#include "entity-system/model/relation-attributes/relation-attribute-instances/RelationAttributeInstance.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {

	
	/// A manager class for relation attribute types.
	class RelationAttributeTypeManager : public TypeManagerTemplate<RelationAttributeType>
	{
		public:

			/// Constructor.
			RelationAttributeTypeManager();

			/// Destructor.
			~RelationAttributeTypeManager();

			/// Creates an relation attribute type.
			/// @param rel_attr_type_name The name of the new relation attribute type.
			/// @param rel_attr_type_data_type The data type of the new relation attribute type.
			/// @param rel_attr_type_features The features of the new relation attribute type.
			/// @return A shared pointer to the relation attribute type which was created.
			O_REL_ATTR_TYPE create_relation_attribute_type(const std::string&, const DataType&, const EnumSet<Feature>&);

			/// Returns the number of existing types of relation attributes.
			/// @return The number of existing types of relation attributes.
			std::size_t get_relation_attribute_type_count() const;

			/// Deletes all types of relation attributes.
			void delete_all_relation_attribute_types();

	};


};
};
