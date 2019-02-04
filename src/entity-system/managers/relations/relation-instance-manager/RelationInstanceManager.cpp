// Inexor entity system
// (c)2018-2019 Inexor

#include "RelationInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    RelationInstanceManager::RelationInstanceManager(
    	std::shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager
    ) : InstanceManagerTemplate()
    {
    	// Store pointer to the entity relation attribute instance manager.
        this->relation_attribute_instance_manager = relation_attribute_instance_manager;
    }


    RelationInstanceManager::~RelationInstanceManager()
    {
		// TODO: Implement!
    }


    O_REL_INST RelationInstanceManager::create_relation_instance(const REL_TYPE& rel_type, const ENT_INST& ent_type_inst_source, const ENT_INST& ent_type_inst_target)
	{
		// Create a new entity relation type instance.
		REL_INST new_relation_instance = std::make_shared<RelationInstance>(rel_type, ent_type_inst_source, ent_type_inst_target);

		// Create all entity relation attribute type instances.
		std::vector<REL_ATTR_TYPE> rel_attributes = rel_type->get_linked_attribute_types();

		// Get the attribute instance map
		std::unordered_map<REL_ATTR_TYPE, REL_ATTR_INST> relation_attribute_instances = new_relation_instance->get_relation_attribute_instances();

		// Create the attribute instances
		for(std::size_t i = 0; i < rel_attributes.size(); i++)
		{
			//relation_attribute_instances[ent_rel_attributes[i]] = this->entity_relation_attribute_instance_manager->create_entity_relation_attribute_instance(ent_rel_attributes[i]);
		}

		// Add the relation type instance to the buffer.
		add_instance(new_relation_instance->get_GUID(), new_relation_instance);

		// Signal that the relation type has been created.
		notify_relation_instance_created(new_relation_instance);

        // Read only, no mutex required.
        return O_REL_INST { new_relation_instance };
	}


    bool RelationInstanceManager::does_relation_instance_exist(const xg::Guid instance_GUID)
	{
		return does_instance_exist(instance_GUID);
	}


	O_REL_INST RelationInstanceManager::get_relation_instance(const xg::Guid& instance_GUID)
	{
		return get_instance(instance_GUID);
	}


	std::size_t RelationInstanceManager::get_relation_instances_count() const
	{
        // Read only, no mutex required.
		return get_instance_count();
	}


	std::size_t RelationInstanceManager::delete_relation_instance(const xg::Guid& instance_GUID)
	{
		O_REL_INST o_rel_inst = get_relation_instance(instance_GUID);
		if (o_rel_inst.has_value())
		{
			REL_INST rel_inst = o_rel_inst.value();
			xg::Guid type_GUID = rel_inst->get_relation_type()->get_GUID();
			std::size_t deleted_instances_count = delete_instance(instance_GUID);
			notify_relation_instance_deleted(type_GUID, instance_GUID);
			return deleted_instances_count;
		} else {
			return 0;
		}
	}


	std::size_t RelationInstanceManager::delete_relation_instance(const REL_INST& relation_instance)
	{
		xg::Guid instance_GUID = relation_instance->get_GUID();
		xg::Guid type_GUID = relation_instance->get_relation_type()->get_GUID();
		std::size_t deleted_instances_count = delete_instance(instance_GUID);
		notify_relation_instance_deleted(type_GUID, instance_GUID);
		return deleted_instances_count;
	}


	void RelationInstanceManager::delete_all_relation_instances()
	{
		// Call template base class method.
		delete_all_instances();
	}


	void RelationInstanceManager::register_on_created(const xg::Guid& type_GUID, std::shared_ptr<RelationInstanceCreatedListener> listener)
	{
		if (signals_relation_instance_created.end() == signals_relation_instance_created.find(type_GUID))
		{
			auto signal = std::make_shared<boost::signals2::signal<void(REL_INST)>>();
			signals_relation_instance_created.insert(std::make_pair(type_GUID, signal));
		}
		signals_relation_instance_created[type_GUID]->connect(std::bind(&RelationInstanceCreatedListener::on_relation_instance_created, listener.get(), std::placeholders::_1));
	}


	void RelationInstanceManager::register_on_deleted(const xg::Guid& type_GUID, std::shared_ptr<RelationInstanceDeletedListener> listener)
	{
		if (signals_relation_instance_deleted.end() == signals_relation_instance_deleted.find(type_GUID))
		{
			auto signal = std::make_shared<boost::signals2::signal<void(const xg::Guid&, const xg::Guid&)>>();
			signals_relation_instance_deleted.insert(std::make_pair(type_GUID, signal));
		}
		signals_relation_instance_deleted[type_GUID]->connect(std::bind(&RelationInstanceDeletedListener::on_relation_instance_deleted, listener.get(), std::placeholders::_1, std::placeholders::_2));
	}


	void RelationInstanceManager::notify_relation_instance_created(REL_INST new_relation_instance)
	{
		xg::Guid type_GUID = new_relation_instance->get_relation_type()->get_GUID();
		if (!(signals_relation_instance_created.end() == signals_relation_instance_created.find(type_GUID)))
		{
			signals_relation_instance_created[type_GUID]->operator ()(new_relation_instance);
		}
	}


	void RelationInstanceManager::notify_relation_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		if (!(signals_relation_instance_deleted.end() == signals_relation_instance_deleted.find(type_GUID)))
		{
			signals_relation_instance_deleted[type_GUID]->operator ()(type_GUID, inst_GUID);
		}
	}


};
};
