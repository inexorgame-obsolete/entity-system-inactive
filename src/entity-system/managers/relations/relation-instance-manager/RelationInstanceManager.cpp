#include "RelationInstanceManager.hpp"

namespace inexor {
namespace entity_system {

	RelationInstanceManager::RelationInstanceManager(
		std::shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager
	) : InstanceManagerTemplate()
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_manager);

		// Store pointer to the entity relation attribute instance manager.
		this->relation_attribute_instance_manager = relation_attribute_instance_manager;
	}

	RelationInstanceManager::~RelationInstanceManager()
	{
	}

	RelationInstancePtrOpt RelationInstanceManager::create_relation_instance(const RelationTypePtr& rel_type, const EntityInstancePtr& ent_type_inst_source, const EntityInstancePtr& ent_type_inst_target)
	{
		// Create a new entity relation instance.
		RelationInstancePtr new_relation_instance = std::make_shared<RelationInstance>(rel_type, ent_type_inst_source, ent_type_inst_target);

		// No wit is time to create all corresponding entity relation attribute instances.
		// Query all relation attribute types.
		std::vector<RelationAttributeTypePtr> rel_attributes = rel_type->get_linked_attribute_types();
		
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_manager);

		// Create relation attribute instances.
		for(std::size_t i = 0; i < rel_attributes.size(); i++)
		{
			// Create relation attribute instance.
			RelationAttributeInstancePtr linked_rel_attr_type_inst = relation_attribute_instance_manager->create_relation_attribute_instance(rel_attributes[i]);

			// Link relation attribute instance to this relation instance.
			new_relation_instance->register_relation_attribute_instance(rel_attributes[i], linked_rel_attr_type_inst);
		}

		// Add the relation type instance to the buffer.
		add_instance(new_relation_instance->get_GUID(), new_relation_instance);

		// Signal that the relation type has been created.
		notify_relation_instance_created(new_relation_instance);

		return RelationInstancePtrOpt { new_relation_instance };
	}

	RelationInstancePtrOpt RelationInstanceManager::create_relation_instance(const xg::Guid& rel_inst_GUID, const RelationTypePtr& rel_type, const EntityInstancePtr& ent_type_inst_source, const EntityInstancePtr& ent_type_inst_target)
	{
		// Check if a relation instance with this GUID does already exist.
		if(does_relation_instance_exist(rel_inst_GUID))
		{
			return std::nullopt;
		}

		// Create a new entity relation instance.
		RelationInstancePtr new_relation_instance = std::make_shared<RelationInstance>(rel_type, ent_type_inst_source, ent_type_inst_target);

		// No wit is time to create all corresponding entity relation attribute instances.
		// Query all relation attribute types.
		std::vector<RelationAttributeTypePtr> rel_attributes = rel_type->get_linked_attribute_types();
		
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_manager);

		// Create relation attribute instances.
		for(std::size_t i = 0; i < rel_attributes.size(); i++)
		{
			// Create relation attribute instance.
			RelationAttributeInstancePtr linked_rel_attr_type_inst = relation_attribute_instance_manager->create_relation_attribute_instance(rel_attributes[i]);

			// Link relation attribute instance to this relation instance.
			new_relation_instance->register_relation_attribute_instance(rel_attributes[i], linked_rel_attr_type_inst);
		}

		// Add the relation type instance to the buffer.
		add_instance(new_relation_instance->get_GUID(), new_relation_instance);

		// Signal that the relation type has been created.
		notify_relation_instance_created(new_relation_instance);

		return RelationInstancePtrOpt { new_relation_instance };
	}

	bool RelationInstanceManager::does_relation_instance_exist(const xg::Guid instance_GUID)
	{
		// No mutex required as this is a read-only operation.
		return does_instance_exist(instance_GUID);
	}

	RelationInstancePtrOpt RelationInstanceManager::get_relation_instance(const xg::Guid& instance_GUID)
	{
		// No mutex required as this is a read-only operation.
		return get_instance(instance_GUID);
	}

	std::size_t RelationInstanceManager::get_relation_instances_count() const
	{
		// Read only, no mutex required.
		return get_instance_count();
	}

	std::size_t RelationInstanceManager::delete_relation_instance(const xg::Guid& instance_GUID)
	{
		RelationInstancePtrOpt o_rel_inst = get_relation_instance(instance_GUID);
		if(o_rel_inst.has_value())
		{
			RelationInstancePtr rel_inst = o_rel_inst.value();
			xg::Guid type_GUID = rel_inst->get_relation_type()->get_GUID();
			std::size_t deleted_instances_count = delete_instance(instance_GUID);
			notify_relation_instance_deleted(type_GUID, instance_GUID);
			return deleted_instances_count;
		}
		else
		{
			return 0;
		}
	}

	std::size_t RelationInstanceManager::delete_relation_instance(const RelationInstancePtr& relation_instance)
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
		if(signals_relation_instance_created.end() == signals_relation_instance_created.find(type_GUID))
		{
			auto signal = std::make_shared<boost::signals2::signal<void(RelationInstancePtr)>>();
			signals_relation_instance_created.insert(std::make_pair(type_GUID, signal));
		}
		signals_relation_instance_created[type_GUID]->connect(std::bind(&RelationInstanceCreatedListener::on_relation_instance_created, listener.get(), std::placeholders::_1));
	}

	void RelationInstanceManager::register_on_deleted(const xg::Guid& type_GUID, std::shared_ptr<RelationInstanceDeletedListener> listener)
	{
		if(signals_relation_instance_deleted.end() == signals_relation_instance_deleted.find(type_GUID))
		{
			auto signal = std::make_shared<boost::signals2::signal<void(const xg::Guid&, const xg::Guid&)>>();
			signals_relation_instance_deleted.insert(std::make_pair(type_GUID, signal));
		}
		signals_relation_instance_deleted[type_GUID]->connect(std::bind(&RelationInstanceDeletedListener::on_relation_instance_deleted, listener.get(), std::placeholders::_1, std::placeholders::_2));
	}

	void RelationInstanceManager::notify_relation_instance_created(RelationInstancePtr new_relation_instance)
	{
		xg::Guid type_GUID = new_relation_instance->get_relation_type()->get_GUID();
		if (!(signals_relation_instance_created.end() == signals_relation_instance_created.find(type_GUID)))
		{
			signals_relation_instance_created[type_GUID]->operator ()(new_relation_instance);
		}
	}

	void RelationInstanceManager::notify_relation_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		if(!(signals_relation_instance_deleted.end() == signals_relation_instance_deleted.find(type_GUID)))
		{
			signals_relation_instance_deleted[type_GUID]->operator ()(type_GUID, inst_GUID);
		}
	}

}
}
