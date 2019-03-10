#include "EntityTypeBuilderFactory.hpp"

namespace inexor {
namespace entity_system {

	EntityTypeBuilderFactory::EntityTypeBuilderFactory(
		EntityTypeManagerPtr entity_type_manager,
		EntityAttributeTypeManagerPtr entity_attribute_type_manager,
		EntityAttributeInstanceManagerPtr entity_attribute_instance_manager
	)
	{
		this->entity_type_manager = entity_type_manager;
		this->entity_attribute_type_manager = entity_attribute_type_manager;
		this->entity_attribute_instance_manager = entity_attribute_instance_manager;
	}

	EntityTypeBuilderFactory::~EntityTypeBuilderFactory()
	{
	}

	void EntityTypeBuilderFactory::init()
	{
	}

	EntityTypeBuilderPtr EntityTypeBuilderFactory::get_builder() {
		return std::make_shared<EntityTypeBuilder>(entity_type_manager, entity_attribute_type_manager, entity_attribute_instance_manager);
	}

}
}
