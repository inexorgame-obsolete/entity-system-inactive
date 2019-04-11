#pragma once

#include "entity-system/model/entity-attributes/entity-attribute-types/EntityAttributeType.hpp"
#include "entity-system/model/base/instance/InstanceBase.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"

namespace inexor {
namespace entity_system {

	using EntityAttributeTypePtr = std::shared_ptr<EntityAttributeType>;

	/// @class EntityAttributeInstance
	/// @brief A base class for entity attribute type instances.
	class EntityAttributeInstance : public InstanceBase<EntityAttributeType>, public DataContainer, public GUIDBase
	{
		public:

			/// @brief Constructor.
			/// @note the GUID of the new entity attribute instance will be created automatically by the inheritance of GUIDBase!
			/// @param ent_attr_type A reference to a shared pointer of an entity attribute type of which an instance will be created.
			EntityAttributeInstance(const EntityAttributeTypePtr&);

			/// Destructor.
			~EntityAttributeInstance();

			/// @brief Get the entity attribute type.
			/// @return The type of the attribute.
			EntityAttributeTypePtr get_entity_attribute_type() const;

	};

}
}
