// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-attribute-type/EntityAttributeType.hpp"
#include "../../../data-container/DataContainer.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	// A base class for instances of attributes of entities.
	class EntityAttributeTypeInstance : public TypeInstanceBase<EntityAttributeType,EntityAttributeTypeInstance>,
                                        public DataContainer
	{
		public:

			// 
			EntityAttributeTypeInstance(const ENT_ATTR_TYPE&);

			// 
			~EntityAttributeTypeInstance();

			// Note: Set and get methods are already implemented by inheriting from DataContainer.

	};


};
};
