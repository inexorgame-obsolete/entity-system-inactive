#include "RelationInstanceBuilderFactory.hpp"

namespace inexor {
namespace entity_system {

	RelationInstanceBuilderFactory::RelationInstanceBuilderFactory(
		RelationInstanceManagerPtr relation_instance_manager,
		RelationTypeManagerPtr relation_type_manager
	)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_factory_mutex);

		this->relation_instance_manager = relation_instance_manager;
		this->relation_type_manager = relation_type_manager;
	}

	RelationInstanceBuilderFactory::~RelationInstanceBuilderFactory()
	{
	}

	void RelationInstanceBuilderFactory::init()
	{
	}

	RelationInstanceBuilderPtr RelationInstanceBuilderFactory::get_builder()
	{
		// No mutex required as this is a read-only operation.
		return std::make_shared<RelationInstanceBuilder>(relation_instance_manager, relation_type_manager);
	}

}
}
