// Inexor entity system
// (c)2018 Inexor

#include "RelationInstanceBuilderManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {


	RelationInstanceBuilderManager::RelationInstanceBuilderManager(
		shared_ptr<RelationInstanceManager> relation_instance_manager,
		shared_ptr<RelationTypeManager> relation_type_manager
	)
	{
		this->relation_instance_manager = relation_instance_manager;
		this->relation_type_manager = relation_type_manager;
	}

	RelationInstanceBuilderManager::~RelationInstanceBuilderManager()
	{
	}

	void RelationInstanceBuilderManager::init()
	{
	}

	shared_ptr<RelationInstanceBuilder> RelationInstanceBuilderManager::get_builder() {
		return make_shared<RelationInstanceBuilder>(relation_instance_manager, relation_type_manager);
	}

}
}
