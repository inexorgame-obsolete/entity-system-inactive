#include "RelationTypeBuilderFactory.hpp"

namespace inexor {
namespace entity_system {

	RelationTypeBuilderFactory::RelationTypeBuilderFactory(
		RelationTypeManagerPtr relation_type_manager,
		RelationAttributeTypeManagerPtr relation_attribute_type_manager,
		RelationAttributeInstanceManagerPtr relation_attribute_instance_manager
	)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_type_builder_factory);

		this->relation_type_manager = relation_type_manager;
		this->relation_attribute_type_manager = relation_attribute_type_manager;
		this->relation_attribute_instance_manager = relation_attribute_instance_manager;
	}

	RelationTypeBuilderFactory::~RelationTypeBuilderFactory()
	{
	}

	void RelationTypeBuilderFactory::init()
	{
	}

	RelationTypeBuilderPtr RelationTypeBuilderFactory::get_builder()
	{
		// No mutex required as this is a read-only operation.
		return std::make_shared<RelationTypeBuilder>(relation_type_manager, relation_attribute_type_manager, relation_attribute_instance_manager);
	}

}
}
