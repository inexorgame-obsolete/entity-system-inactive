#pragma once

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"

#include <optional>

namespace inexor {
namespace entity_system {

	using EntityAttributeTypePtr = std::shared_ptr<EntityAttributeType>;
	using EntityAttributeInstancePtr = std::shared_ptr<EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

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
			EntityAttributeInstancePtrOpt create_entity_attribute_instance(const EntityAttributeTypePtr&);

			/// @brief Returns an entity attribute instance.
			/// @param ent_attr_inst_GUID The GUID of the entity attribute instance.
			/// @return The entity attribute instance if creating it succeeded, std::nullopt otherwise.
			EntityAttributeInstancePtrOpt get_entity_attribute_instance(const xg::Guid&) const;

			/// @brief Returns the number of existing entity attribute instances.
			/// @return The number of existing entity attribute instances.
			std::size_t get_entity_attribute_instance_count() const;

			/// @brief Deletes a specific entity attribute instances.
			/// @param ent_attr_inst_GUID The GUID of the entity attribute instance which will be deleted.
			std::size_t delete_entity_attribute_instance(const xg::Guid&);

			/// @brief Deletes a specific entity attribute instances.
			/// @param The entity attribute instance which will be deleted.
			std::size_t delete_entity_attribute_instance(const EntityAttributeInstancePtr&);

			/// @brief Deletes all entity attribute instances.
			void delete_all_entity_attribute_instances();

	};

}
}
