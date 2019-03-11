#include "RelationAttributeInstanceManager.hpp"

namespace inexor {
namespace entity_system {

	RelationAttributeInstanceManager::RelationAttributeInstanceManager() : InstanceManagerTemplate()
	{
	}

	RelationAttributeInstanceManager::~RelationAttributeInstanceManager()
	{
	}

	RelationAttributeInstancePtrOpt RelationAttributeInstanceManager::create_relation_attribute_instance(const RelationAttributeTypePtr& rel_attr_type)
	{
		// Creates a new relation attribute type instance.
		RelationAttributeInstancePtr new_rel_attr_inst = std::make_shared<RelationAttributeInstance>(rel_attr_type);
		
		// Call base template class method.
		add_instance(new_rel_attr_inst->get_GUID(), new_rel_attr_inst);

        // Read only, no mutex required.
        return RelationAttributeInstancePtrOpt { new_rel_attr_inst };
	}

	std::size_t RelationAttributeInstanceManager::get_relation_attribute_instance_count() const
	{
		return get_instance_count();
	}

	void RelationAttributeInstanceManager::delete_all_relation_attribute_instances()
	{
		return delete_all_instances();
	}

}
}
