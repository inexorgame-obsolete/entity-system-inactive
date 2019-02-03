// Inexor entity system
// (c)2018 Inexor

#include "RelationTypeBuilderManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {


	RelationTypeBuilderManager::RelationTypeBuilderManager(
		shared_ptr<RelationTypeManager> relation_type_manager,
		shared_ptr<RelationAttributeTypeManager> relation_attribute_type_manager,
		shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager
	)
	{
		this->relation_type_manager = relation_type_manager;
		this->relation_attribute_type_manager = relation_attribute_type_manager;
		this->relation_attribute_instance_manager = relation_attribute_instance_manager;
	}

	RelationTypeBuilderManager::~RelationTypeBuilderManager()
	{
	}

	void RelationTypeBuilderManager::init()
	{
	}

	shared_ptr<RelationTypeBuilder> RelationTypeBuilderManager::get_builder() {
		return make_shared<RelationTypeBuilder>(relation_type_manager, relation_attribute_type_manager, relation_attribute_instance_manager);
	}

}
}
