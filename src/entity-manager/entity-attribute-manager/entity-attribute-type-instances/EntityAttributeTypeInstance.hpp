// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-attribute-type/EntityAttributeType.hpp"
#include "../../../data-container/DataContainer.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for entity attribute type instances.
	class EntityAttributeTypeInstance : public TypeInstanceBase<EntityAttributeType,EntityAttributeTypeInstance>,
                                        public DataContainer
	{
		public:

			/// Constructor.
			/// @param ent_attr_type A reference to a shared pointer of
			/// an entity attribute type of which an instance will be created.
			EntityAttributeTypeInstance(const ENT_ATTR_TYPE&);

			/// Destructor.
			~EntityAttributeTypeInstance();

			// Note: Set and get methods are already implemented by inheriting from DataContainer.

	};


};
};
