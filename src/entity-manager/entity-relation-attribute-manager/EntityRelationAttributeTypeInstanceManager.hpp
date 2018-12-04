// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-attribute-manager/entity-relation-attribute-type-instance/EntityRelationAttributeTypeInstance.hpp"
#include "../entity-relation-attribute-manager/entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../templates/TypeInstanceManager.hpp"
#include "../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for instances of types of entity relation attributes.
	class EntityRelationAttributeTypeInstanceManager : public TypeInstanceManager<EntityRelationAttributeTypeInstance>
	{
		protected:

			/// Constructor.
			EntityRelationAttributeTypeInstanceManager();

			/// Destructor.
			~EntityRelationAttributeTypeInstanceManager();

	public:
			
			/// Creates an entity relation attribute type instance.
			/// @param ent_rel_attr_type A reference to a shared pointer of
			/// an entity relation attribute type of which an instance will be created.
		    /// @return A shared pointer to the entity relation attribute type instance which was created.
            /// TODO: entity_relation_attribute_type_instance_ERROR! 
			ENT_REL_ATTR_TYPE_INST create_entity_relation_attribute_type_instance(const ENT_REL_ATTR_TYPE&);

			/// Returns the number of existing entity relation attribute type instances.
			/// @return The number of existing entity relation attribute type instancen.
			const std::size_t get_entity_relation_attribute_type_instance_count() const;

			/// Deletes all instances of entity relation attribute types.
			void delete_all_entity_relation_type_attribute_instances();

	};


};
};
