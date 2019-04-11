#pragma once

#include "entity-system/model/relation-attributes/relation-attribute-types/RelationAttributeType.hpp"
#include "entity-system/model/base/instance/InstanceBase.hpp"

namespace inexor {
namespace entity_system {

	using RelationAttributeTypePtr = std::shared_ptr<RelationAttributeType>;

	/// @class RelationAttributeInstance
	/// @brief A base class for relation attribute type instances
	class RelationAttributeInstance : public InstanceBase<RelationAttributeType>, public DataContainer, public GUIDBase
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @note the GUID of the new relation attribute instance will be created automatically by the inheritance of GUIDBase!
			/// @param rel_attr_type A const reference to a shared pointer of an relation attribute type of which an instance will be created.
			RelationAttributeInstance(const RelationAttributeTypePtr& rel_attr_type);

			/// Destructor.
			~RelationAttributeInstance();

			/// @brief Get the relation attribute type.
			/// @return The type of the attribute.
			RelationAttributeTypePtr get_relation_attribute_type() const;

	};

}
}
