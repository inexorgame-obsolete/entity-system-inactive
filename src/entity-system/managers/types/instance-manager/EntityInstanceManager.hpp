// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <optional>

#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"
#include "entity-system/managers/attributes/attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "entity-system/model/types/instances/EntityInstance.hpp"
#include "entity-system/util/error-handling/ReturnCodes.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity type instances.
    class EntityInstanceManager : public InstanceManagerTemplate<EntityInstance>
	{
        protected:

			/// Constructor
			EntityInstanceManager();

			/// Destructor
			~EntityInstanceManager();
			
    		/// The entity attribute instance manager
    		std::shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager;

		public:

			/// Create an entity type instance.
			/// @param ent_type A const reference of a shared pointer
			/// to an entity type of which an instance will be created.
			/// @return A shared pointer to the entity type instance which was created.
			std::optional<ENT_INST> create_entity_instance(const ENT_TYPE&);



            /// 
            /// 
            std::optional<ENT_INST> get_entity_instance(const xg::Guid&);


            /// 
            /// 
            std::optional<ENT_INST> get_entity_instance(const std::string&);


            // TODO: get_all_entity_instances_of_type() const;


            /// Returns all entity type instances.
			/// @return All entity type instances which exist in the entity system.
            std::optional<ENT_INST> get_all_entity_instances() const;


            // TODO: get_entity_instance_count_of_type() const;

			/// Returns the number of existing entity type instances.
			/// @return The number of existing entity type instances.
			const std::size_t get_entity_instance_count() const;


            // TODO: delete_entity_instance(const xg::Guid&);
            // TODO: delete_all_entity_instances();


			/// Delete all entity type instances
			void delete_all_entity_instances();


	};


};
};
