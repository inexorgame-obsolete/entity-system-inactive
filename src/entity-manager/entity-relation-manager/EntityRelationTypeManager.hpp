// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-manager/entity-relation-type/EntityRelationType.hpp"
#include "../../templates/TypeManagerTemplate.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for types of entity relations.
    class EntityRelationTypeManager : public TypeManagerTemplate<EntityRelationType>
    {
		private:

			/// We need this entity type error
			/// to create the entity relation type error.
			const ENT_TYPE entity_type_error
				= std::make_shared<EntityType>("ERROR");

			/// This entity relation type error
			/// will be returned when a method fails.
			const ENT_REL_TYPE entity_relation_type_error
				= std::make_shared<EntityRelationType>("ERROR", entity_type_error, entity_type_error);
			

        protected:

			/// Constructor.
			EntityRelationTypeManager();

			/// Destructor.
			~EntityRelationTypeManager();

		public:

			/// Checks if an entity relation type does already exist.
			/// @param ent_rel_type_name The name of the entity relation type.
			/// @return true if this entity relation type does already exist,
			/// false otherwise.
			bool does_entity_relation_type_exist(const std::string&);

			/// Checks if an entity relation type does already exist.
			/// @param ent_rel_type A const reference of a shared pointer
			/// to an entity relation type.
			/// @return true if this entity relation type does already exist,
			/// false otherwise.
			bool does_entity_relation_type_exist(const ENT_REL_TYPE&);

			// TODO: check by UUID!

			/// Creates a new entity relation type and store it in the entity system.
			/// @param ent_rel_type_name The name of the new entity relation type name.
			/// @param ent_type_source A const reference of a shared pointer to
			/// an entity type which will act as <b>source</b> entity type.
			/// @param ent_type_target A const reference of a shared pointer to
			/// an entity type which will act as <b>target</b> entity type.
			/// <br>If this method fails, entity_relation_type_error will be returned
			/// as error object.
			ENT_REL_TYPE create_entity_relation_type(const std::string&, const ENT_TYPE&, const ENT_TYPE&);

			/// Returns the number of available entity relation types.
			/// @return The number of available entity relation types.
			const std::size_t get_entity_relation_types_count() const;

			/// Deletes an entity relation type.
			/// @param ent_rel_type_name The name of the entity relation type name.
			void delete_entity_relation_type(const std::string&);
			
			/// Deletes an entity relation type.
			/// @param ent_rel_type A const reference of a shared pointer
			/// to the entity relation type which will be deleted.
			void delete_entity_relation_type(const ENT_REL_TYPE&);

			// TODO: Delete by UUID.

			/// Deletes all entity relation types.
			void delete_all_entity_relation_types();

	};

};
};
