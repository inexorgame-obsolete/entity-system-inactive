#pragma once

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/model/entity-attributes/entity-attribute-types/EntityAttributeType.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/base/instance/InstanceBase.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"

#include <mutex>
#include <optional>

namespace inexor {
namespace entity_system {

	/// These using instructions help to shorten the following code.
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
			/// Every EntityInstance can have only one instance of a certain unique EntityAttributeType.
			std::unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr> instances;

			/// The mutex for this class.
			std::mutex entity_instance_mutex;

		public:

			/// @brief Constructor.
			/// @note The GUID of the new entity type instance will be created automatically by the inheritance of GUIDBase!
			/// @param ent_type The entity type of which an instance will be created.
			EntityInstance(const EntityTypePtr& ent_type);

			/// @brief Constructor.
			/// @param ent_type A const reference of a shared pointer to the entity type of which an instance will be created.
			/// @param ent_inst_GUID The GUID of the entity instance which will be created.
			/// @param ent_type The entity type of which an enity instance will be created.
			EntityInstance(const xg::Guid& ent_inst_GUID, const EntityTypePtr& ent_type);

			/// @brief Destructor.
			~EntityInstance();

			/// @brief Returns the entity type.
			/// @return The entity type of the entity instance.
			EntityTypePtr get_entity_type() const;

			/// @brief Adds an entity attribute instance to the entity instance.
			/// @param ent_attr_type The entity attribute type.
			/// @param ent_attr_inst The entity attribute instance.
			void add_entity_attribute_instance(const EntityAttributeTypePtr& ent_attr_type, const EntityAttributeInstancePtr& ent_attr_inst);

			/// @brief Returns all the attribute instances.
			/// @return All existing attribute instances.
			std::optional<std::unordered_map<EntityAttributeTypePtr, EntityAttributeInstancePtr>> get_instances() const;

			/// @brief Gets the attribute instance by name.
			/// @return The attribute instance with the given name.
			EntityAttributeInstancePtrOpt get_attribute_instance(const std::string& attr_name);

			/// @brief Gets the attribute instance by name.
			/// @note The attribute must exist! No checks are done.
			/// @TODO Add checks if the attribute exists!
			/// @param The name of the attribute.
			/// @return The attribute instance with the given name.
			EntityAttributeInstancePtrOpt operator[](const std::string& attr_name);

			/// @brief Returns the value of the attribute instance by name.
			/// @tparam I The data type.
			/// @param The name of the attribute.
			/// @return The value of the attribute instance.
			template <std::size_t I>
			auto get(const std::string& attr_name)
			{
				// No mutex required as this is a read-only operation.
			    return std::get<I>(get_attribute_instance(attr_name).value()->value.Value());
			}

			/// @brief Sets the value of an attribute.
			/// @param attr_name The name of the EntityAttributeType.
			/// @param value The value of the EntityAttributeInstance.
			void set_own_value(const std::string& attr_name, DataValue value);

			/// @TODO Set value by GUID!

			/// @brief Toggles the own value of the attribute instance by name.
			/// @warning The attribute must exist! No checks are done.
			/// @warning The attribute has to be of data type BOOL. No checks are done.
			/// @param The name of the attribute.
			/// @todo: Add type check here! Toggle should only be available for bool.
			void toggle(const std::string& attr_name);

	};

}
}
