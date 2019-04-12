#pragma once

#include "entity-system/model/relation-attributes/relation-attribute-types/RelationAttributeType.hpp"
#include "entity-system/model/base/instance/InstanceBase.hpp"

namespace inexor {
namespace entity_system {

	/// This using instruction helps to shorten the following code.
	using RelationAttributeTypePtr = std::shared_ptr<RelationAttributeType>;

	/// @class RelationAttributeInstance
	/// @brief A base class for relation attribute instances.
	class RelationAttributeInstance : public InstanceBase<RelationAttributeType>, public DataContainer, public GUIDBase
	{
		public:

			/// @brief Constructs the relation attribute instance.
			/// @note The GUID of this relation attribute instance will be created automatically by inheriting from GUIDBase!
			/// @param rel_attr_type A const reference to a shared pointer of a relation attribute type of which an instance will be created.
			/// @todo Add a mutex to ensure thread-safety!
			RelationAttributeInstance(const RelationAttributeTypePtr& rel_attr_type);

			/// Destructs the relation attribute instance.
			~RelationAttributeInstance();

			/// @brief Returns the relation attribute type.
			/// @return The attribte type.
			RelationAttributeTypePtr get_relation_attribute_type() const;

	};

}
}
