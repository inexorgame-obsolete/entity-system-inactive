// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-attribute-type/EntityAttributeType.hpp"
#include "../../../data-container/DataContainer.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"
#include "base-classes/GUID/GUIDBase.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for entity attribute type instances.
	class EntityAttributeTypeInstance : public TypeInstanceBase<EntityAttributeType,EntityAttributeTypeInstance>,
                                        public DataContainer,
		                                public GUIDBase
	{
		public:

			/// Constructor.
			/// @param ent_attr_type A reference to a shared pointer of
			/// an entity attribute type of which an instance will be created.
			/// @note the GUID of the new entity attribute type instance will
			/// be created automatically by the inheritance of GUIDBase!
			EntityAttributeTypeInstance(const ENT_ATTR_TYPE&);

			/// Destructor.
			~EntityAttributeTypeInstance();

			/// Returns the GUID of the entity attribute type instance.
			/// @return The GUID of the entity attribute type instance.
			xg::Guid get_entity_attribute_type_instance_GUID() const;

			// Note: Set and get methods are already implemented by inheriting from DataContainer.

	};


};
};
