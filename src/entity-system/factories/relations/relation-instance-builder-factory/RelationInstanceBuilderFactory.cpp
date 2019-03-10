#include "RelationInstanceBuilderFactory.hpp"

namespace inexor {
namespace entity_system {

	RelationInstanceBuilderFactory::RelationInstanceBuilderFactory(
		RelationInstanceManagerPtr relation_instance_manager,
		RelationTypeManagerPtr relation_type_manager
	)
	{
		this->relation_instance_manager = relation_instance_manager;
		this->relation_type_manager = relation_type_manager;
	}

	RelationInstanceBuilderFactory::~RelationInstanceBuilderFactory()
	{
	}

	void RelationInstanceBuilderFactory::init()
	{
	}

	RelationInstanceBuilderPtr RelationInstanceBuilderFactory::get_builder() {
		return std::make_shared<RelationInstanceBuilder>(relation_instance_manager, relation_type_manager);
	}

}
}
