// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <optional>

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

        private:

			/// The entity attribute instance manager
    		std::shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager;


	};


};
};
