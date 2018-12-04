// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../templates/TypeManager.hpp"
#include "../entity-relation-attribute-manager/entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {

	
	/// A manager class for types of entity relation attributes.
	class EntityRelationAttributeTypeManager : public TypeManager<EntityRelationAttributeType>
	{
		protected:

			/// Constructor.
			EntityRelationAttributeTypeManager();

			/// Destructor.
			~EntityRelationAttributeTypeManager();

		public:

			/// Creates an entity relation attribute type.
			/// @param ent_rel_attr_type_name The name of the new entity relation attribute type.
			/// @param ent_rel_attr_data_type The data type of the new entity relation attribute type.
			ENT_REL_ATTR_TYPE create_entity_relation_attribute_type(const std::string&, const ENTSYS_DATA_TYPE&);

			/// Returns the number of existing types of entity relation attributes.
			/// @return The number of existing types of entity relation attributes.
			std::size_t get_entity_relation_attribute_type_count() const;

			/// Deletes all types of entity relation attributes.
			void delete_all_entity_relation_attribute_types();

	};


};
};
