// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <boost/signals2.hpp>
#include <crossguid/guid.hpp>
#include <optional>

#include "entity-system/listeners/relations/RelationInstanceCreatedListener.hpp"
#include "entity-system/listeners/relations/RelationInstanceDeletedListener.hpp"
#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "entity-system/model/relations/relation-instances/RelationInstance.hpp"
#include "entity-system/model/relations/relation-types/RelationType.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity relation type instances.
    class RelationInstanceManager : public InstanceManagerTemplate<RelationInstance>
    {
        public:
            
			/// Constructor.
            RelationInstanceManager(
            	std::shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager
            );

			/// Destructor.
			~RelationInstanceManager();

			/// Creates a new entity relation type instance.
			/// @param ent_rel_type A const reference to a shared pointer of
			/// an entity relation type of which an instance will be created.
			/// @param ent_type_inst_source A const reference to a shared pointer of
			/// the entity type instance which will be used as <b>source</b> entity type instance.
			/// @param ent_type_inst_target A const reference to a shared pointer of
			/// the entity type instance which will be used as <b>target</b> entity type instance.
			/// @return A shared pointer to the new entity relation type instance which was created.
			O_REL_INST create_relation_instance(const REL_TYPE&, const ENT_INST&, const ENT_INST&);

			/// Returns the number of relation type instances.
			/// @return The number of existing entity relation type instances.
			std::size_t get_relation_instances_count() const;


			// TODO: Get instances count.
			// TODO: Delete instance.
			// TODO: Get instance(s).
			// TODO: Delete all instances.

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
			void notify_relation_instance_created(REL_INST new_entity_instance);


			/// Notifies all listeners that a relation instance has been deleted.
			void notify_relation_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);


			/// The signals that an relation instance has been created.
			/// Key is the GUID of the relation type.
			/// Value is a signal with one parameter: the created relation instance
			std::unordered_map<xg::Guid, std::shared_ptr<boost::signals2::signal<void(REL_INST new_relation_instance)> > > signals_relation_instance_created;


			/// The signals that an relation instance has been deleted.
			/// Key is the GUID of the relation type.
			/// Value is a signal with two parameters: the GUID of the relation type, the GUID of the relation instance
			std::unordered_map<xg::Guid, std::shared_ptr<boost::signals2::signal<void(const xg::Guid& type_GUID, const xg::Guid& instance_GUID)> > > signals_relation_instance_deleted;

    };


};
};
