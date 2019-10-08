#pragma once

#include "entity-system/model/entity-attributes/entity-attribute-types/EntityAttributeType.hpp"
#include "entity-system/model/base/instance/InstanceBase.hpp"

namespace inexor {
namespace entity_system {

	using EntityAttributeTypePtr = std::shared_ptr<EntityAttributeType>;

	/// @class EntityAttributeInstance
	/// @brief A base class for entity attribute type instances.
	class EntityAttributeInstance : public InstanceBase<EntityAttributeType>, public DataContainer, public GUIDBase
	{
		private:
			
			/// The mutex of this class.
			std::mutex entity_attribute_instance_mutex;

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

			/// @brief Returns the value of the attribute instance.
			/// @tparam I The data type.
			/// @return The value of the attribute instance.
			template <std::size_t I>
			auto get()
			{
			    return std::get<I>(value.Value());
			}

			/// @brief Sets the own value of the attribute instance.
			/// @note The given value must be of the correct data type. No checks are done.
			/// @param value The data value.
			void set_own_value(DataValue value);

			/// @brief Toggles the own value of the attribute instance.
			/// @note The attribute have to be of data type BOOL. No checks are done.
			void toggle();

	};

}
}
