#pragma once

#include "entity-system/managers/manager-templates/TypeManagerTemplate.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/listeners/entities/EntityTypeCreatedListener.hpp"
#include "entity-system/listeners/entities/EntityTypeDeletedListener.hpp"

#include <string>
#include <optional>
#include <boost/signals2.hpp>
#include <crossguid/guid.hpp>

namespace inexor {
namespace entity_system {

	/// These using instructions help to shorten the following code.
	using EntityTypePtr = std::shared_ptr<EntityType>;
	using EntityTypePtrOpt = std::optional<EntityTypePtr>;

	/// @class EntityTypeManager
	/// @brief A manager class for entity types.
	class EntityTypeManager : public TypeManagerTemplate<EntityType>
	{
		public:

			/// @brief Constructor.
			EntityTypeManager();

			/// @brief Destructor.
			~EntityTypeManager();

			/// @brief Creates a new entity type.
			/// @param type_name The name of the new entity type.
			/// @return A std::optional shared pointer to the entity type which was created.
			EntityTypePtrOpt create_entity_type(const std::string& type_name);


			/// @brief Creates a new entity type.
			/// @param type_GUID The GUID of the new entity type.
			/// @param type_name The name of the new entity type.
			/// @return A std::optional shared pointer to the entity type which was created.
			EntityTypePtrOpt create_entity_type(const xg::Guid& type_GUID, const std::string& type_name);


			/// @brief Checks if an entity type does already exist.
			/// @param type_GUID The GUID of the type.
			/// @return True if the entity type already exists, false otherwise.
			bool does_entity_type_exist(const xg::Guid& type_GUID);


			/// @brief Checks if an entity type does already exist.
			/// @param type_name The name of the entity type.
			/// @return True if the entity type already exists, false otherwise.
			bool does_entity_type_exist(const std::string& type_name);


			/// @brief Checks if an entity type does already exist.
			/// @param type_shared_ptr A const reference of a shared pointer to the entity type.
			/// @return True if the entity type already exists, false otherwise.
			bool does_entity_type_exist(const EntityTypePtr& type_shared_ptr);


			/// @brief Returns the number of existing entity types.
			/// @return The number of existing entity types.
			std::size_t get_entity_type_count() const;


			/// @brief Returns an entity type.
			/// @param type_GUID The GUID of the entity type.
			/// @return A std::optional<EntityTypePtr> of the entity type.
			EntityTypePtrOpt get_entity_type(const xg::Guid& type_GUID);


			/// @brief Returns an entity type.
			/// @param type_name The name of the entity type.
			/// @return A std::optional<EntityTypePtr> of the entity type.
			EntityTypePtrOpt get_entity_type(const std::string& type_name);


			/// @brief Deletes an entity type by GUID.
			/// @param type_GUID The GUID of the entity type which will be deleted.
			/// @return The number of deleted entity types.
			std::size_t delete_entity_type(const xg::Guid& type_GUID);


			/// @brief Deletes an entity type by name.
			/// @param ent_type_name The name of the entity type which will be deleted.
			/// @return The number of deleted entity types.
			std::size_t delete_entity_type(const std::string& type_name);


			/// @brief Deletes an entity type by entity type.
			/// @param type A const reference of a shared pointer to the entity type which will be deleted.
			/// @return The number of deleted entity types.
			std::size_t delete_entity_type(const EntityTypePtr& type);


			/// @brief Removes all types of entities.
			void delete_all_entity_types();


			/// @brief Registers a new listener
			/// @param listener The listener.
			void register_on_created(std::shared_ptr<EntityTypeCreatedListener> listener);


			/// @brief Registers a new listener
			/// @param listener The listener.
			void register_on_deleted(std::shared_ptr<EntityTypeDeletedListener> listener);

		private:

			/// @brief Notifies all listeners that a new entity type has been created.
			/// @param new_entity_type The entity type which was created.
			void notify_entity_type_created(EntityTypePtr new_entity_type);

			/// @brief Notifies all listeners that an entity type has been deleted.
			/// @param type_GUID The GUID of the type which was created.
			void notify_entity_type_deleted(const xg::Guid& type_GUID);

			/// Signal, that an entity type has been created.
			boost::signals2::signal<void(EntityTypePtr new_entity_type)> signal_entity_type_created;

			/// Signal, that an entity type has been deleted.
			boost::signals2::signal<void(const xg::Guid& type_GUID)> signal_entity_type_deleted;

	};

}
}
