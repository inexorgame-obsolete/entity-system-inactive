#pragma once

#include "entity-system/listeners/relations/RelationTypeCreatedListener.hpp"
#include "entity-system/listeners/relations/RelationTypeDeletedListener.hpp"
#include "entity-system/model/relations/relation-types/RelationType.hpp"
#include "entity-system/managers/manager-templates/TypeManagerTemplate.hpp"

#include <boost/signals2.hpp>
#include <crossguid/guid.hpp>
#include <optional>

namespace inexor {
namespace entity_system {

	/// These using instructions help to shorten the following code.
	using EntityTypePtr = std::shared_ptr<EntityType>;
	using RelationTypePtr = std::shared_ptr<RelationType>;
	using RelationTypePtrOpt = std::optional<RelationTypePtr>;

	/// @class RelationTypeManager
	/// @brief A manager class for entity relation types.
	class RelationTypeManager : public TypeManagerTemplate<RelationType>
	{
		public:

			/// @brief Constructor.
			RelationTypeManager();

			/// @brief Destructor.
			~RelationTypeManager();

			/// @brief Creates a new relation type and store it in the entity system.
			/// @param rel_type_name The name of the new relation type name.
			/// @param ent_type_source A const reference of a shared pointer to an entity type which will act as <b>source</b> entity type.
			/// @param ent_type_target A const reference of a shared pointer to an entity type which will act as <b>target</b> entity type.
			/// @return A std::optional shared pointer to the relation type which was created.
			RelationTypePtrOpt create_relation_type(const std::string& rel_type_name, const EntityTypePtr& ent_type_source, const EntityTypePtr& ent_type_target);

			/// @brief Creates a new relation type and store it in the entity system.
			/// @param rel_type_GUID The GUID of the new relation type.
			/// @param rel_type_name The name of the new relation type.
			/// @param ent_type_source A const reference of a shared pointer to an entity type which will act as <b>source</b> entity type.
			/// @param ent_type_target A const reference of a shared pointer to an entity type which will act as <b>target</b> entity type.
			/// @return A std::optional shared pointer to the relation type which was created.
			RelationTypePtrOpt create_relation_type(const xg::Guid&, const std::string&, const EntityTypePtr&, const EntityTypePtr&);

			/// @brief Checks if a relation type exists by GUID.
			/// @param rel_type_GUID The GUID of the type.
			/// @return true if the type exists, false otherwise.
			bool does_relation_type_exist(const xg::Guid& rel_type_GUID);

			/// @brief Checks if an relation type exists by name.
			/// @param rel_type_name The name of the relation type.
			/// @return true if this relation type does already exist, false otherwise.
			bool does_relation_type_exist(const std::string& rel_type_name);

			/// @brief Checks if an relation type does already exist.
			/// @param rel_type A const reference of a shared pointer to an relation type.
			/// @return true if this relation type exist, false otherwise.
			bool does_relation_type_exist(const RelationTypePtr& rel_type);

			/// @brief Returns the number of available relation types.
			/// @return The number of available relation types.
			std::size_t get_relation_types_count() const;

			/// @brief Returns an relation type.
			/// @param rel_type_GUID The GUID of the relation type.
			/// @return A std::optional<REL_TYPE> of the relation type.
			RelationTypePtrOpt get_relation_type(const xg::Guid& rel_type_GUID);

			/// @brief Returns an relation type.
			/// @param rel_type_name The name of the relation type.
			/// @return A std::optional<REL_TYPE> of the relation type.
			RelationTypePtrOpt get_relation_type(const std::string& rel_type_name);

			/// @brief Deletes an relation type by GUID.
			/// @param type_GUID The GUID of the relation type which will be deleted.
			/// @return The number of deleted types.
			std::size_t delete_relation_type(const xg::Guid& type_GUID);

			/// @brief Deletes an entity relation type.
			/// @param rel_type_name The name of the relation type name.
			/// @return The number of deleted types.
			std::size_t delete_relation_type(const std::string& rel_type_name);

			/// @brief Deletes an entity relation type.
			/// @param rel_type A const reference of a shared pointer to the relation type which will be deleted.
			/// @return The number of deleted types.
			std::size_t delete_relation_type(const RelationTypePtr& rel_type);

			/// @brief Deletes all entity relation types.
			void delete_all_relation_types();

			/// @brief Registers a new listener.
			/// @param listener The listener.
			void register_on_created(std::shared_ptr<RelationTypeCreatedListener> listener);

			/// @brief Registers a new listener.
			/// @param listener The listener.
			void register_on_deleted(std::shared_ptr<RelationTypeDeletedListener> listener);

		private:

			/// @brief Notifies all listeners that a new relation type has been created.
			/// @param new_relation_type The new relation type which was created.
			void notify_relation_type_created(RelationTypePtr new_relation_type);

			/// @brief Notifies all listeners that an relation type has been deleted.
			/// @param type_GUID The GUID of the new relation type which was created.
			void notify_relation_type_deleted(const xg::Guid& type_GUID);

			/// Signal, that an relation type has been created.
			boost::signals2::signal<void(RelationTypePtr new_relation_type)> signal_relation_type_created;

			/// Signal, that an relation type has been deleted.
			boost::signals2::signal<void(const xg::Guid& type_GUID)> signal_relation_type_deleted;

			/// The mutex of this class.
			std::mutex relation_type_manager_mutex;

	};

}
}
