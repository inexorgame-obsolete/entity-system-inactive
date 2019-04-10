#include "RelationManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	RelationManager::RelationManager(
		shared_ptr<RelationTypeManager> relation_type_manager,
		shared_ptr<RelationInstanceManager> relation_instance_manager,
		shared_ptr<RelationAttributeTypeManager> relation_attribute_type_manager,
		shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager
	)
	{
		this->relation_type_manager = relation_type_manager;
		this->relation_instance_manager = relation_instance_manager;
		this->relation_attribute_type_manager = relation_attribute_type_manager;
		this->relation_attribute_instance_manager = relation_attribute_instance_manager;
	}

	RelationManager::~RelationManager()
	{
	}

	// Order of destruction:
	// <ul>
	// <li> Attributes first, then the container which owns the attribute
	// <li> Instances first, then types
	// </ul>
	void RelationManager::reset_entity_system()
	{
		// Attribute instances
		relation_attribute_instance_manager->delete_all_relation_attribute_instances();

		// Attribute types
		relation_attribute_type_manager->delete_all_relation_attribute_types();

		// Instances
		relation_instance_manager->delete_all_relation_instances();

		// Types
		relation_type_manager->delete_all_relation_types();
	}


};
};
