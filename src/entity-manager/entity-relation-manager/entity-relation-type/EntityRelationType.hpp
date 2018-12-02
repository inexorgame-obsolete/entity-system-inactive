// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../entity-type-manager/entity-type/EntityType.hpp"
#include "../../entity-relation-attribute-manager/entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../../base-classes/TypeBase.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {

	
	/// A base class for types of entity relations.
	class EntityRelationType : public TypeBase
	{
		private:

			/// The entity type of the source entity.
			ENT_TYPE source_entity_type;

			/// The entity type of the target entity.
			ENT_TYPE target_entity_type;

			/// Types of entity relation attributes which are linked to this entity relation type.
			std::vector<ENT_REL_ATTR_TYPE> linked_rel_attr_types;

		public:

			/// Constructor.
			/// @param ?
			/// @param ?
			/// @param ?
			EntityRelationType(const std::string&, const ENT_TYPE&, const ENT_TYPE&);
			
			/// Destructor.
			~EntityRelationType();

			/// Links an entity relation attribute type to this entity relation type.
			/// @param ? TODO
			void link_entity_relation_attribute_type(const ENT_REL_ATTR_TYPE&);
			
			/// Returns linked entity relation attribute types.
			std::vector<ENT_REL_ATTR_TYPE> get_linked_attribute_types() const;
						
			/// Implementation of data validation method as required by inheritance of base class DataValidation!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;


	};


};
};
