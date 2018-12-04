// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "entity-type-instance/EntityTypeInstance.hpp"
#include "../../templates/TypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for instances of types of entities.
    class EntityTypeInstanceManager : public TypeInstanceManager<EntityTypeInstance>
	{            
		private:

			/// We need this entity type error
			/// to create the entity type instance error.
			const ENT_TYPE entity_type_error
				= std::make_shared<EntityType>("ERROR");

			/// This entity type instance error
			/// will be returned when a method fails.
			const ENT_TYPE_INST entity_type_instance_error
				= std::make_shared<EntityTypeInstance>(entity_type_error);

        protected:

			/// Constructor
			EntityTypeInstanceManager();

			/// Destructor
			~EntityTypeInstanceManager();
			
		public:

			/// Create an entity type instance.
			/// @param ent_type A reference of a shared pointer
			/// to an entity type of which an instance will be created.
			/// @return A shared pointer to the entity type instance which was created.
			/// TODO: error_entity_type_instance!
			ENT_TYPE_INST create_entity_type_instance(const ENT_TYPE&);

			/// Returns the number of existing entity type instances.
			/// @return The number of existing entity type instances.
			const std::size_t get_entity_type_instance_count() const;

			/// Delete all entity type instances
			void delete_all_entity_type_instances();

			// TODO: Delete by UUID!

	};


};
};
