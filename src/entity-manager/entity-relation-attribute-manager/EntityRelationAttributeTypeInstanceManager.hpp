// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-attribute-manager/entity-relation-attribute-type-instance/EntityRelationAttributeTypeInstance.hpp"
#include "../entity-relation-attribute-manager/entity-relation-attribute-type/EntityRelationAttributeType.hpp"
#include "../../templates/TypeInstanceManagerTemplate.hpp"
#include "../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity relation attribute type instances.
	class EntityRelationAttributeTypeInstanceManager : public TypeInstanceManagerTemplate<EntityRelationAttributeTypeInstance>
	{
		private:

			/// We need this entity relation attribute type error
			/// to create the entity relation attribute type instance error.
			const ENT_REL_ATTR_TYPE entity_relation_attribute_type_error
				= std::make_shared<EntityRelationAttributeType>("ERROR", ENTSYS_DATA_TYPE_UNDEFINED);

			/// This entity relation attribute type instance error will be returned when a method fails.
			const ENT_REL_ATTR_TYPE_INST entity_relation_attribute_type_instance_error
				= std::make_shared<EntityRelationAttributeTypeInstance>(entity_relation_attribute_type_error);

		protected:

			/// Constructor.
			EntityRelationAttributeTypeInstanceManager();

			/// Destructor.
			~EntityRelationAttributeTypeInstanceManager();

		public:
			
			/// Creates an entity relation attribute type instance.
			/// @param ent_rel_attr_type A const reference to a shared pointer of
			/// an entity relation attribute type of which an instance will be created.
		    /// @return A shared pointer to the entity relation attribute type instance which was created.
            /// <br>If the creation fails, entity_relation_attribute_type_instance_error will be returned
			/// as error object.
			ENT_REL_ATTR_TYPE_INST create_entity_relation_attribute_type_instance(const ENT_REL_ATTR_TYPE&);

			/// Returns the number of existing entity relation attribute type instances.
			/// @return The number of existing entity relation attribute type instances.
			const std::size_t get_entity_relation_attribute_type_instance_count() const;

			/// Deletes all instances of entity relation attribute types.
			void delete_all_entity_relation_type_attribute_instances();

	};


};
};
