// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <optional>

#include "entity-system/model/relations/relation-types/RelationType.hpp"
#include "entity-system/managers/manager-templates/TypeManagerTemplate.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity relation types.
    class RelationTypeManager : public TypeManagerTemplate<RelationType>
    {
        public:

			/// Constructor.
			RelationTypeManager();

			/// Destructor.
			~RelationTypeManager();

			/// Checks if an entity relation type does already exist.
			/// @param ent_rel_type_name The name of the entity relation type.
			/// @return true if this entity relation type does already exist,
			/// false otherwise.
			bool does_relation_type_exist(const std::string&);


			/// Checks if an entity relation type does already exist.
			/// @param ent_rel_type A const reference of a shared pointer
			/// to an entity relation type.
			/// @return true if this entity relation type does already exist,
			/// false otherwise.
			bool does_relation_type_exist(const REL_TYPE&);


            /// 
			bool does_relation_type_exist(const xg::Guid&);


			/// Creates a new entity relation type and store it in the entity system.
			/// @param ent_rel_type_name The name of the new entity relation type name.
			/// @param ent_type_source A const reference of a shared pointer to
			/// an entity type which will act as <b>source</b> entity type.
			/// @param ent_type_target A const reference of a shared pointer to
			/// an entity type which will act as <b>target</b> entity type.
			O_REL_TYPE create_relation_type(const std::string&, const ENT_TYPE&, const ENT_TYPE&);


			/// Returns the number of available entity relation types.
			/// @return The number of available entity relation types.
			std::size_t get_relation_types_count() const;


			/// Deletes an entity relation type.
			/// @param ent_rel_type_name The name of the entity relation type name.
			void delete_relation_type(const std::string&);
			

			/// Deletes an entity relation type.
			/// @param ent_rel_type A const reference of a shared pointer
			/// to the entity relation type which will be deleted.
			void delete_relation_type(const REL_TYPE&);


			void delete_relation_type(const xg::Guid&);


			/// Deletes all entity relation types.
			void delete_all_relation_types();

	};

};
};
