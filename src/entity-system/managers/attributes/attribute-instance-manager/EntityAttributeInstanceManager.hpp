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
		public:
            
			/// Constructor.
			EntityAttributeInstanceManager();

			/// Destructor.
			~EntityAttributeInstanceManager();

			/// @brief Creates an entity attribute instance.
			/// @param ent_attr_type The entity attribute type of which an instance will be created.
			/// @return The entity attribute instance if creating it succeeded, std::nullopt otherwise.
			std::optional<ENT_ATTR_INST> create_entity_attribute_instance(const ENT_ATTR_TYPE&);


            /// @brief Returns an entity attribute instance.
            /// @param ent_attr_inst_GUID The GUID of the entity attribute instance.
			/// @return The entity attribute instance if creating it succeeded, std::nullopt otherwise.
            std::optional<ENT_ATTR_INST> get_entity_attribute_instance(const xg::Guid&) const;


			/// @brief Returns the number of existing entity attribute instances.
			/// @return The number of existing entity attribute instances.
			std::size_t get_entity_attribute_instance_count() const;


            /// @brief Deletes a specific entity attribute instances.
            /// @param ent_attr_inst_GUID The GUID of the entity attribute instance which will be deleted.
            std::size_t delete_entity_attribute_instance(const xg::Guid&);


            /// @brief Deletes a specific entity attribute instances.
            /// @param The entity attribute instance which will be deleted.
            std::size_t delete_entity_attribute_instance(const ENT_ATTR_INST&);


			/// @brief Deletes all entity attribute instances.
			void delete_all_entity_attribute_instances();

	};


};
};
