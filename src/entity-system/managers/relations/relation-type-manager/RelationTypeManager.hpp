// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <boost/signals2.hpp>
#include <crossguid/guid.hpp>
#include <optional>

#include "entity-system/listeners/relations/RelationTypeCreatedListener.hpp"
#include "entity-system/listeners/relations/RelationTypeDeletedListener.hpp"
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

			/// Checks if an relation type does already exist.
			/// @param ent_rel_type_name The name of the relation type.
			/// @return true if this relation type does already exist,
			/// false otherwise.
			bool does_relation_type_exist(const std::string&);


			/// Checks if an relation type does already exist.
			/// @param ent_rel_type A const reference of a shared pointer
			/// to an relation type.
			/// @return true if this relation type does already exist,
			/// false otherwise.
			bool does_relation_type_exist(const REL_TYPE&);


            /// 
			bool does_relation_type_exist(const xg::Guid&);


			/// Creates a new relation type and store it in the entity system.
			/// @param ent_rel_type_name The name of the new relation type name.
			/// @param ent_type_source A const reference of a shared pointer to
			/// an entity type which will act as <b>source</b> entity type.
			/// @param ent_type_target A const reference of a shared pointer to
			/// an entity type which will act as <b>target</b> entity type.
			O_REL_TYPE create_relation_type(const std::string&, const ENT_TYPE&, const ENT_TYPE&);


			/// Returns the number of available relation types.
			/// @return The number of available relation types.
			std::size_t get_relation_types_count() const;


			/// Deletes an entity relation type.
			/// @param rel_type_name The name of the relation type name.
			std::size_t delete_relation_type(const std::string&);


			/// @brief Deletes an relation type by GUID.
            /// @param rel_type_guid The GUID of the relation type which will be deleted.
			std::size_t delete_relation_type(const xg::Guid&);
			

			/// Deletes an entity relation type.
			/// @param rel_type A const reference of a shared pointer
			/// to the relation type which will be deleted.
			std::size_t delete_relation_type(const REL_TYPE&);


			/// Deletes all entity relation types.
			void delete_all_relation_types();


			/// @brief Registers a new listener
			void register_on_created(std::shared_ptr<RelationTypeCreatedListener> listener);


			/// @brief Registers a new listener
			void register_on_deleted(std::shared_ptr<RelationTypeDeletedListener> listener);


		private:


			/// Notifies all listeners that a new relation type has been created.
			void notify_relation_type_created(REL_TYPE new_relation_type);


			/// Notifies all listeners that an relation type has been deleted.
			void notify_relation_type_deleted(const xg::Guid& type_GUID);


			/// Signal, that an relation type has been created.
			boost::signals2::signal<void(REL_TYPE new_relation_type)> signal_relation_type_created;


			/// Signal, that an relation type has been deleted.
			boost::signals2::signal<void(const xg::Guid& type_GUID)> signal_relation_type_deleted;

	};

};
};
