// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include "entity-system/model/entity-attributes/entity-attribute-types/EntityAttributeType.hpp"
#include "entity-system/model/base/instance/Instance.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for entity attribute type instances.
	class EntityAttributeInstance : public InstanceBase<EntityAttributeType>, public DataContainer, public GUIDBase
	{
		public:

			/// Constructor.
			/// @param ent_attr_type A reference to a shared pointer of
			/// an entity attribute type of which an instance will be created.
			/// @note the GUID of the new entity attribute instance will
			/// be created automatically by the inheritance of GUIDBase!
			EntityAttributeInstance(const ENT_ATTR_TYPE&);

			/// Destructor.
			~EntityAttributeInstance();

            /// @brief Get the entity attribute type.
            /// @return The type of the attribute.
			ENT_ATTR_TYPE get_entity_attribute_type() const;

			// Note: Set and get methods are already implemented by inheriting from DataContainer.

	};


};
};
