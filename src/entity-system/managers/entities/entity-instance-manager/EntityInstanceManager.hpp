// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <boost/signals2.hpp>
#include <crossguid/guid.hpp>
#include <optional>

#include "entity-system/listeners/entities/EntityInstanceCreatedListener.hpp"
#include "entity-system/listeners/entities/EntityInstanceDeletedListener.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"
#include "entity-system/util/return-codes/ReturnCodes.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity type instances.
    class EntityInstanceManager : public InstanceManagerTemplate<EntityInstance>
	{
        public:

			/// Constructor
			EntityInstanceManager(
				std::shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager
			);

			/// Destructor
			~EntityInstanceManager();
			
			/// Create an entity type instance.
			/// @param ent_type A const reference of a shared pointer
			/// to an entity type of which an instance will be created.
			/// @return A shared pointer to the entity type instance which was created.
			O_ENT_INST create_entity_instance(const ENT_TYPE&);



			/// @brief Checks if an entity instance does already exist.
            /// @return True if the entity instance already exists, false otherwise.
			bool does_entity_instance_exist(const xg::Guid);


            /// 
            /// 
			O_ENT_INST get_entity_instance(const xg::Guid&);


            /// 
            /// 
			O_ENT_INST get_entity_instance(const std::string&);


            // TODO: get_all_entity_instances_of_type() const;


            /// Returns all entity type instances.
			/// @return All entity type instances which exist in the entity system.
			std::vector<ENT_INST> get_all_entity_instances() const;


            // TODO: get_entity_instance_count_of_type() const;

			/// Returns the number of existing entity type instances.
			/// @return The number of existing entity type instances.
			std::size_t get_entity_instance_count() const;


            // TODO: delete_entity_instance(const xg::Guid&);
            // TODO: delete_all_entity_instances();


			/// Delete all entity type instances
			void delete_all_entity_instances();


			/// @brief Registers a new listener
			void register_on_created(const xg::Guid&, std::shared_ptr<EntityInstanceCreatedListener> listener);


			/// @brief Registers a new listener
			void register_on_deleted(const xg::Guid&, std::shared_ptr<EntityInstanceDeletedListener> listener);


        private:

			/// The entity attribute instance manager
    		std::shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager;


			/// Notifies all listeners that a new entity instance has been created.
			void notify_entity_instance_created(ENT_INST new_entity_instance);


			/// Notifies all listeners that an entity instance has been deleted.
			void notify_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);


			/// The signals that an entity instance has been created.
			/// Key is the GUID of the entity type.
			/// Value is a signal with one parameter: the created entity instance
			std::unordered_map<xg::Guid, std::shared_ptr<boost::signals2::signal<void(ENT_INST new_entity_instance)> > > signals_entity_instance_created;


			/// The signals that an entity instance has been deleted.
			/// Key is the GUID of the entity type.
			/// Value is a signal with two parameters: the GUID of the entity type, the GUID of the entity instance
			std::unordered_map<xg::Guid, std::shared_ptr<boost::signals2::signal<void(const xg::Guid& type_GUID, const xg::Guid& instance_GUID)> > > signals_entity_instance_deleted;


	};


};
};
