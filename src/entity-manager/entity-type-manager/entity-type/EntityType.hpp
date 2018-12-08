// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <unordered_map>

#include "../../entity-attribute-manager/entity-attribute-type/EntityAttributeType.hpp"
#include "../../../templates/TypeContainerTemplate.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"
#include "base-classes/GUID/GUIDBase.hpp"


namespace inexor {
namespace entity_system {

	
	/// A base class for entity types.
	class EntityType : public TypeBase,
		               public TypeContainerTemplate<EntityAttributeType>,
		               public GUIDBase
    {
        public:

			/// Constructor.
			/// @param ent_type_name The unique name
			/// of the entity type which will be created.
			/// @note The GUID of the new entity type will be created
			/// automatically by the inheritance of GUIDBase!
			EntityType(const std::string&);

			/// Destructor.
			~EntityType();

			/// Check if an entity attribute type is already linked to this entity type.
			/// @param ent_attr_type_name The name of the entity attribute type of which
			/// will be checked if it is associated with this entity type.
			/// @return True if this entity attribute type is already linked,
			/// false otherwise.
			bool has_attribute_type(const std::string&);

			/// Check if an entity attribute type is already linked to this entity type.
			/// @param ent_attr_type A const reference of a shared pointer to the
			/// entity attribute type of which will be checked if it is linked
			/// with this entity type.
			/// @return True if this entity attribute type is already associated,
			/// false otherwise.
			bool has_attribute_type(const ENT_ATTR_TYPE&);
        
			/// Links an entity attribute type to this entity type.
			/// @param ent_attr_type A const reference of a shared pointer to
			/// an entity attribute type which will be linked to this entity type.
			/// @return ENTSYS_SUCCESS if linking succeeded, ENTSYS_ERROR otherwise.
			ENTSYS_RESULT link_attribute_type(const ENT_ATTR_TYPE&);
	
			/// Returns the number of entity attribute types which are linked to this entity type.
			/// @return The number of entity attribute types which are linked to this entity type.
			std::size_t get_linked_attributes_count() const;

			/// Returns a vector of entity attribute types which are linked to this entity type.
			/// @return a vector of entity attribute types which are linked to this entity type.
			const std::vector<ENT_ATTR_TYPE> get_linked_attribute_types() const;

			/// Deletes all entity attribute types which are linked to this entity type.
			void reset_linked_attribute_types();

			/// Implement a data validation method as
			/// required by class inheritance of DataValidation
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

    };


};
};
