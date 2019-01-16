// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <optional>

#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"
#include "entity-system/model/attributes/attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity attribute type instances.
    class EntityAttributeInstanceManager : public InstanceManagerTemplate<EntityAttributeInstance>
    {
		protected:
            
			/// Constructor.
			EntityAttributeInstanceManager();

			/// Destructor.
			~EntityAttributeInstanceManager();

		public:

			/// Creates an entity attribute type instance.
			/// @param ent_attr_type A const reference to a shared pointer of
			/// an entity attribute type of which an instance will be created.
			/// @return A shared pointer to the entity attribute type instance
			/// which was created.
			/// @note the GUID of the entity attribute type will be created
			/// automatically because EntityAttributeType inherits from GUIDBase!
			std::optional<ENT_ATTR_INST> create_entity_attribute_instance(const ENT_ATTR_TYPE&);


            std::optional<ENT_ATTR_INST> get_entity_attribute_instance(const xg::Guid&);


			/// Returns the number of existing entity attribute type instances.
			/// @return The number of existing entity attribute type instances.
			std::size_t get_entity_attribute_instance_count() const;


            std::size_t delete_entity_attribute_instance(const xg::Guid&);


			/// Deletes all entity attribute type instances.
			void delete_all_entity_attribute_instances();

	};


};
};
