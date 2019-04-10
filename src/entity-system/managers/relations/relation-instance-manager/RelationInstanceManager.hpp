#pragma once

#include "entity-system/listeners/relations/RelationInstanceCreatedListener.hpp"
#include "entity-system/listeners/relations/RelationInstanceDeletedListener.hpp"
#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "entity-system/model/relations/relation-instances/RelationInstance.hpp"
#include "entity-system/model/relations/relation-types/RelationType.hpp"

#include <boost/signals2.hpp>
#include <crossguid/guid.hpp>
#include <optional>

namespace inexor {
namespace entity_system {

	using RelationTypePtr = std::shared_ptr<RelationType>;
	using RelationInstancePtr = std::shared_ptr<RelationInstance>;
	using RelationInstancePtrOpt = std::optional<RelationInstancePtr>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;

	/// A manager class for relation instances.
	class RelationInstanceManager : public InstanceManagerTemplate<RelationInstance>
	{
		public:

			/// Constructor.
			RelationInstanceManager(
				std::shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager
			);

			/// Destructor.
			~RelationInstanceManager();

			/// Creates a new entity relation instance.
			/// @param rel_type A const reference to a shared pointer of
			/// an relation type of which an instance will be created.
			/// @param ent_inst_source A const reference to a shared pointer of
			/// the entity instance which will be used as <b>source</b> entity instance.
			/// @param ent_inst_target A const reference to a shared pointer of
			/// the entity instance which will be used as <b>target</b> entity instance.
			/// @return A shared pointer to the new relation instance which was created.
			RelationInstancePtrOpt create_relation_instance(const RelationTypePtr&, const EntityInstancePtr&, const EntityInstancePtr&);

			/// Creates a new entity relation instance.
			/// @param rel_inst_GUID The GUID of the new relation instance.
			/// @param rel_type A const reference to a shared pointer of
			/// a relation type of which an instance will be created.
			/// @param ent_inst_source A const reference to a shared pointer of
			/// the entity instance which will be used as <b>source</b> entity instance.
			/// @param ent_inst_target A const reference to a shared pointer of
			/// the entity instance which will be used as <b>target</b> entity instance.
			/// @return A shared pointer to the new relation instance which was created.
			RelationInstancePtrOpt create_relation_instance(const xg::Guid&, const RelationTypePtr&, const EntityInstancePtr&, const EntityInstancePtr&);

			/// @brief Checks if an relation instance does already exist.
			/// @return True if the relation instance already exists, false otherwise.
			bool does_relation_instance_exist(const xg::Guid);

			///
			///
			RelationInstancePtrOpt get_relation_instance(const xg::Guid&);

			/// TODO: what's the parameter meaning?
			/// TODO: implement
			RelationInstancePtrOpt get_relation_instance(const std::string&);

			// TODO: get_all_relation_instances_of_type() const;

			/// Returns all relation instances.
			/// @return All relation instances which exist in the entity system.
			/// TODO: implement
			std::vector<RelationInstancePtr> get_all_relation_instances() const;

			// TODO: get_relation_instance_count_of_type() const;

			/// Returns the number of relation instances.
			/// @return The number of existing relation instances.
			std::size_t get_relation_instances_count() const;

			// TODO: Get instances count.
			// TODO: Delete instance.
			// TODO: Get instance(s).
			// TODO: Delete all instances.

			/// Delete relation instance by GUID
			std::size_t delete_relation_instance(const xg::Guid& instance_GUID);

			/// Delete relation instance
			std::size_t delete_relation_instance(const RelationInstancePtr& relation_instance);

			// TODO: Delete relation instances by source entity instance

			// TODO: Delete relation instances by target entity instance

			// TODO: Delete relation instances by entity instance (both: source and target)
			// Called by delete_entity_instance() -> also delete all relation instances of the to-be-deleted entity instance!

			// TODO: Delete relation instances by relation type

			/// Delete all relation instances
			void delete_all_relation_instances();

			/// @brief Registers a new listener
			void register_on_created(const xg::Guid&, std::shared_ptr<RelationInstanceCreatedListener> listener);

			/// @brief Registers a new listener
			void register_on_deleted(const xg::Guid&, std::shared_ptr<RelationInstanceDeletedListener> listener);

		private:

			/// The entity relation attribute instance manager
			std::shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager;

			/// Notifies all listeners that a new relation instance has been created.
			void notify_relation_instance_created(RelationInstancePtr new_entity_instance);

			/// Notifies all listeners that a relation instance has been deleted.
			void notify_relation_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			/// The signals that an relation instance has been created.
			/// Key is the GUID of the relation type.
			/// Value is a signal with one parameter: the created relation instance
			std::unordered_map<xg::Guid, std::shared_ptr<boost::signals2::signal<void(RelationInstancePtr new_relation_instance)> > > signals_relation_instance_created;

			/// The signals that an relation instance has been deleted.
			/// Key is the GUID of the relation type.
			/// Value is a signal with two parameters: the GUID of the relation type, the GUID of the relation instance
			std::unordered_map<xg::Guid, std::shared_ptr<boost::signals2::signal<void(const xg::Guid& type_GUID, const xg::Guid& instance_GUID)> > > signals_relation_instance_deleted;

	};

}
}
