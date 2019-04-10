#pragma once

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/model/entity-attributes/entity-attribute-types/EntityAttributeType.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/base/instance/Instance.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"

#include <mutex>
#include <optional>

namespace inexor {
namespace entity_system {

	using EntityTypePtr = std::shared_ptr<EntityType>;
	using EntityAttributeTypePtr = std::shared_ptr<EntityAttributeType>;
	using EntityAttributeInstancePtr = std::shared_ptr<EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

	/// @class EntityInstance
	/// @brief A base class for entity instances.
	class EntityInstance : public InstanceBase<EntityType>, public GUIDBase
	{
		private:

			/// A map for storing the instances by type.
			/// Every EntityInstance can have only one instance of a unique EntityAttributeType.
			std::unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr> instances;

			/// Mutex for this entity instance.
			std::mutex entity_type_mutex;

		public:

			/// @brief Constructor.
			/// @note The GUID of the new entity type instance will be created automatically by the inheritance of GUIDBase!
			/// @param ent_type A const reference of a shared pointer to the entity type of which an instance will be created.
			EntityInstance(const EntityTypePtr& ent_type);

			/// @brief Constructor.
			/// @param ent_type A const reference of a shared pointer to the entity type of which an instance will be created.
			/// @param ent_inst_GUID The GUID of the entity instance which will be created.
			/// @param ent_type The entity type which will be created.
			EntityInstance(const xg::Guid& ent_inst_GUID, const EntityTypePtr& ent_type);

			/// Destructor.
			~EntityInstance();

			/// @brief Get the entity type.
			/// @return The entity type of the entity instance.
			EntityTypePtr get_entity_type() const;

			/// @brief Adds an entity attribute instance to the entity instance.
			/// @param ent_attr_type The entity attribute type.
			/// @param ent_attr_inst The entity attribute instance.
			void add_entity_attribute_instance(const EntityAttributeTypePtr& ent_attr_type, const EntityAttributeInstancePtr& ent_attr_inst);

			/// @brief Get all the attribute instances.
			/// @return All existing attribute instances.
			std::optional<std::unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr>> get_instances() const;

			// TODO: Implement methods for setting and getting entity attribute instance data...

			/// @brief Get the attribute instance by name.
			/// @return The attribute instance with the given name.
			EntityAttributeInstancePtrOpt get_attribute_instance(const std::string& attr_name);
	};

}
}
