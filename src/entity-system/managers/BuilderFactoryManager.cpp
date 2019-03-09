#include "BuilderFactoryManager.hpp"

namespace inexor {
namespace entity_system {

	BuilderFactoryManager::BuilderFactoryManager(
		EntityTypeBuilderFactoryPtr entity_type_builder_factory,
		EntityInstanceBuilderFactoryPtr entity_instance_builder_factory,
		RelationTypeBuilderFactoryPtr relation_type_builder_factory,
		RelationInstanceBuilderFactoryPtr relation_instance_builder_factory
    )
    {
		this->entity_type_builder_factory = entity_type_builder_factory;
		this->entity_instance_builder_factory = entity_instance_builder_factory;
		this->relation_type_builder_factory = relation_type_builder_factory;
		this->relation_instance_builder_factory = relation_instance_builder_factory;
    }

    BuilderFactoryManager::~BuilderFactoryManager()
    {
    }

}
}
