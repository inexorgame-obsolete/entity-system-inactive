// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-attribute-type/EntityAttributeType.hpp"
#include "../../../data-container/DataContainer.hpp"


namespace inexor {
namespace entity_system {


	// A base class for instances of attributes of entities.
	class EntityAttributeTypeInstance : public EntityAttributeType,
		                                public DataContainer
	{
		public:

			// TODO: Remove default constructor!
			EntityAttributeTypeInstance(); // = delete;

			// TODO: Make this the default constructor.
			EntityAttributeTypeInstance(const std::shared_ptr<EntityAttributeType>&);

			// 
			~EntityAttributeTypeInstance();

			// Implement data validation method as required by base class inheritance!
			// This overrides EntityAttributeType::validate().
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

	};


};
};
