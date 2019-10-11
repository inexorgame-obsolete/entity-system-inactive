#pragma once

#include "entity-system/listeners/entities/EntityInstanceCreatedListener.hpp"
#include "entity-system/listeners/entities/EntityInstanceDeletedListener.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"

#include <boost/signals2.hpp>
#include <crossguid/guid.hpp>
#include <optional>

namespace inexor {
namespace entity_system {

	/// These using instructions help to shorten the following code.
	using EntityTypePtr = std::shared_ptr<EntityType>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	/// @class EntityInstanceManager
	/// @brief A manager class for entity instances.
	class EntityInstanceManager : public InstanceManagerTemplate<EntityInstance>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically with the help of Boost DI.<br>
			/// For more information see https://boost-experimental.github.io/di/user_guide/index.html
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// @param entity_attribute_instance_manager A shared pointer to the entity attribute instance manager.
			EntityInstanceManager(
				std::shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager
			);

			/// @brief Destructor.
			~EntityInstanceManager();


			/// @brief Creates an entity instance.
			/// @param ent_type A const reference of a shared pointer to an entity type of which an instance will be created.
			/// @return A shared pointer to the entity instance which was created.
			EntityInstancePtrOpt create_entity_instance(const EntityTypePtr& ent_type);


			/// @brief Creates an entity instance.
			/// @param ent_type A const reference of a shared pointer to an entity type of which an instance will be created.
			/// @param instance_initializer Function for initializing the attributes.
			/// @return A shared pointer to the entity instance which was created.
			EntityInstancePtrOpt create_entity_instance(const EntityTypePtr& type, std::function<bool (EntityInstancePtr)> instance_initializer);


			/// @brief Creates an entity instance.
			/// @param ent_inst_GUID The GUID of the new entity instance.
			/// @param ent_type A const reference of a shared pointer to an entity type of which an instance will be created.
			/// @return A shared pointer to the entity instance which was created.
			EntityInstancePtrOpt create_entity_instance(const xg::Guid& inst_GUID, const EntityTypePtr& type);


			/// @brief Creates an entity instance.
			/// @param ent_inst_GUID The GUID of the new entity instance.
			/// @param ent_type A const reference of a shared pointer to an entity type of which an instance will be created.
			/// @return A shared pointer to the entity instance which was created.
			EntityInstancePtrOpt create_entity_instance(const xg::Guid& inst_GUID, const EntityTypePtr& type, std::function<bool (EntityInstancePtr)> instance_initializer);


			/// @brief Checks if an entity instance does already exist.
			/// @param instance_GUID The GUID of the new entity instance.
			/// @return True if the entity instance already exists, false otherwise.
			bool does_entity_instance_exist(const xg::Guid instance_GUID);


			/// @brief Gets an entity instance by GUID.
			/// @param instance_GUID The GUID of the instance.
			/// @return A std::optional shared pointer to the enity instance.
			EntityInstancePtrOpt get_entity_instance(const xg::Guid& instance_GUID);

			// TODO: get_all_entity_instances_of_type() const;

			/// Returns all entity instances.
			/// @return A std::unordered_map of all entity instances (value) with their corresponding GUID (key).
			std::unordered_map<xg::Guid, EntityInstancePtr> get_all_entity_instances() const;

			// TODO: get_entity_instance_count_of_type(...) const;

			/// Returns the number of existing entity instances.
			/// @return The number of existing entity instances.
			std::size_t get_entity_instance_count() const;


			/// Delete entity instance by GUID
			std::size_t delete_entity_instance(const xg::Guid& instance_GUID);


			/// Delete entity instance
			std::size_t delete_entity_instance(const EntityInstancePtr& entity_instance);


			/// Delete all entity type instances
			void delete_all_entity_instances();


			/// @brief Registers a new listener
			/// @param type_GUID The GUID of the type which was created.
			/// @param listener The listener.
			void register_on_created(const xg::Guid& type_GUID, std::shared_ptr<EntityInstanceCreatedListener> listener);


			/// @brief Registers a new listener.
			/// @param type_GUID The GUID of the type which was deleted.
			/// @param listener The listener.
			void register_on_deleted(const xg::Guid& type_GUID, std::shared_ptr<EntityInstanceDeletedListener> listener);


		private:

			/// The entity attribute instance manager.
			std::shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager;

			/// @brief Notifies all listeners that a new entity instance has been created.
			/// @param new_entity_instance
			void notify_entity_instance_created(EntityInstancePtr new_entity_instance);


			/// @brief Notifies all listeners that an entity instance has been deleted.
			/// @param type_GUID The GUID of the entity type which was deleted.
			/// @param inst_GUID The GUID of the entity instance which was deleted.
			void notify_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);


			/// @brief The signals that an entity instance has been created.
			/// Key is the GUID of the entity type.
			/// Value is a signal with one parameter: the created entity instance.
			std::unordered_map<xg::Guid, std::shared_ptr<boost::signals2::signal<void(EntityInstancePtr new_entity_instance)> > > signals_entity_instance_created;


			/// The signals that an entity instance has been deleted.
			/// Key is the GUID of the entity type.
			/// Value is a signal with two parameters: the GUID of the entity type, the GUID of the entity instance
			std::unordered_map<xg::Guid, std::shared_ptr<boost::signals2::signal<void(const xg::Guid& type_GUID, const xg::Guid& instance_GUID)> > > signals_entity_instance_deleted;

	};

}
}
