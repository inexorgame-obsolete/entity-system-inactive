// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include "../../../model/types/instances/EntityInstance.hpp"
#include "../../manager-templates/InstanceManagerTemplate.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity type instances.
    class EntityInstanceManager : public InstanceManagerTemplate<EntityInstance>
	{            
		private:

			/// We need this entity type error
			/// to create the entity type instance error.
			const ENT_TYPE entity_type_error = std::make_shared<EntityType>("ERROR");

			/// This entity type instance error
			/// will be returned when a method fails.
			const ENT_INST entity_instance_error = std::make_shared<EntityInstance>(entity_type_error);

        protected:

			/// Constructor
			EntityInstanceManager();

			/// Destructor
			~EntityInstanceManager();
			
		public:

			/// Create an entity type instance.
			/// @param ent_type A const reference of a shared pointer
			/// to an entity type of which an instance will be created.
			/// @return A shared pointer to the entity type instance which was created.
			/// <br>If this method fails, entity_instance_error will be returned
			/// as error object.
			ENT_INST create_entity_instance(const ENT_TYPE&);

			/// Returns the number of existing entity type instances.
			/// @return The number of existing entity type instances.
			const std::size_t get_entity_instance_count() const;

			/// Returns the number of existing entity type instances of given type.
			/// @param ? TODO
			//const std::size_t get_entity_instances_count_of_type(const ENT_TYPE&);

			/// Returns all entity type instances.
			/// @return All entity type instances which exist in the entity system.
			//const std::vector<ENT_INST> get_all_entity_instances() const;

			/// Returns all entity type instances of given type.
			/// @param ? TODO
			//const std::vector<ENT_INST> get_all_entity_instances_of_type(const ENT_TYPE&);

			/// Delete all entity type instances
			void delete_all_entity_instances();

            // TODO: Implement
			//void delete_instance(const xg::Guid&);

	};


};
};
