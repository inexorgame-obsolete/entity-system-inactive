// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-manager/entity-relation-type-instance/EntityRelationTypeInstance.hpp"
#include "../../templates/TypeInstanceManagerTemplate.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity relation type instances.
    class EntityRelationTypeInstanceManager : public TypeInstanceManagerTemplate<EntityRelationTypeInstance>
    {
		private:

			/// We need this entity type error
			/// to create the entity type instance error
			const ENT_TYPE entity_type_error
				= std::make_shared<EntityType>("ERROR");

			/// We need this entity type instance error
			/// to create the entity relation type error
			const ENT_TYPE_INST entity_type_instance_error
				= std::make_shared<EntityTypeInstance>(entity_type_error);

			/// We need this entity relation type error
			/// to create the entity relation type error instance.
			const ENT_REL_TYPE entity_relation_type_error
				= std::make_shared<EntityRelationType>("ERROR", entity_type_error, entity_type_error);

			/// This entity relation type instance error will be returned when a method fails.
			const ENT_REL_TYPE_INST entity_relation_type_instance_error
				= std::make_shared<EntityRelationTypeInstance>(entity_relation_type_error,
					                                           entity_type_instance_error,
					                                           entity_type_instance_error);

        protected:
            
			/// Constructor.
            EntityRelationTypeInstanceManager();

			/// Destructor.
			~EntityRelationTypeInstanceManager();

		public:
		
			/// Creates a new entity relation type instance.
			/// @param ent_rel_type A const reference to a shared pointer of
			/// an entity relation type of which an instance will be created.
			/// @param ent_type_inst_source A const reference to a shared pointer of
			/// the entity type instance which will be used as <b>source</b> entity type instance.
			/// @param ent_type_inst_target A const reference to a shared pointer of
			/// the entity type instance which will be used as <b>target</b> entity type instance.
			/// @return A shared pointer to the new entity relation type instance which was created.
			/// <br>If This method fails, entity_relation_type_instance_error will be returned
			/// as error object.
			ENT_REL_TYPE_INST create_entity_relation_type_instance(const ENT_REL_TYPE&,
				                                                   const ENT_TYPE_INST&,
				                                                   const ENT_TYPE_INST&);

			/// Returns the number of relation type instances.
			/// @return The number of existing entity relation type instances.
			const std::size_t get_relation_type_instances_count() const;

			// TODO: Get instances count.
			// TODO: Delete instance.
			// TODO: Get instance(s).
			// TODO: Delete all instances.

    };


};
};
