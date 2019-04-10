#include "EntityInstanceManager.hpp"

namespace inexor {
namespace entity_system {

	using EntityAttributeTypePtr = std::shared_ptr<EntityAttributeType>;
	using EntityAttributeInstancePtr = std::shared_ptr<EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

	EntityInstanceManager::EntityInstanceManager(
		std::shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager
	) : InstanceManagerTemplate()
	{
		this->entity_attribute_instance_manager = entity_attribute_instance_manager;
	}


	EntityInstanceManager::~EntityInstanceManager()
	{
	}


	EntityInstancePtrOpt EntityInstanceManager::create_entity_instance(const EntityTypePtr& ent_type)
	{
		// Create a new entity type instance without GUID.
		EntityInstancePtr new_ent_instance = std::make_shared<EntityInstance>(ent_type);

		// Create all entity attribute type instances for this entity type instance.
		std::optional<std::vector<EntityAttributeTypePtr>> o_ent_type_attributes = ent_type->get_linked_attribute_types();
		if(o_ent_type_attributes.has_value())
		{
			std::vector<EntityAttributeTypePtr> ent_type_attributes = o_ent_type_attributes.value();
			for(std::size_t i=0; i<ent_type_attributes.size(); i++)
			{
				// Create an entity attribute type instance and store it in the map.
				EntityAttributeInstancePtrOpt o_new_ent_attr_inst = entity_attribute_instance_manager->create_entity_attribute_instance(ent_type_attributes[i]);
				if(o_new_ent_attr_inst.has_value())
				{
					EntityAttributeInstancePtr new_ent_attr_inst = o_new_ent_attr_inst.value();
					new_ent_instance->add_entity_attribute_instance(ent_type_attributes[i], new_ent_attr_inst);
				}
				// Use the entity system's EntityAttributeInstanceManager method!
				// TODO: FIX: Create instances!
				//ENT_ATTR_INST new_ent_attr_instance = ?->create_entity_attribute_instance(ent_type_attributes[i]);
				// create_entity_attribute_instance

				// Call template base class method.
				// FIX!
				//new_ent_instance->add_entity_attribute_instance(ent_type_attributes[i], new_ent_attr_instance);
			}
		}

		// Call template base class method.
		add_instance(new_ent_instance->get_GUID(), new_ent_instance);

		// Signal that the entity type has been created.
		notify_entity_instance_created(new_ent_instance);

		return EntityInstancePtrOpt { new_ent_instance };
	}

	EntityInstancePtrOpt EntityInstanceManager::create_entity_instance(const xg::Guid& ent_inst_GUID, const EntityTypePtr& ent_type)
	{
		// Check if an entity instance with this GUID does already exist.
		if(does_entity_instance_exist(ent_inst_GUID))
		{
			return std::nullopt;
		}

		// Create a new entity type instance with GUID.
		EntityInstancePtr new_ent_instance = std::make_shared<EntityInstance>(ent_inst_GUID, ent_type);

		// Create all entity attribute type instances for this entity type instance.
		std::optional<std::vector<EntityAttributeTypePtr>> o_ent_type_attributes = ent_type->get_linked_attribute_types();
		if(o_ent_type_attributes.has_value())
		{
			std::vector<EntityAttributeTypePtr> ent_type_attributes = o_ent_type_attributes.value();
			for(std::size_t i=0; i<ent_type_attributes.size(); i++)
			{
			// Create an entity attribute type instance and store it in the map.
			EntityAttributeInstancePtrOpt o_new_ent_attr_inst = entity_attribute_instance_manager->create_entity_attribute_instance(ent_type_attributes[i]);
			if(o_new_ent_attr_inst.has_value())
			{
				EntityAttributeInstancePtr new_ent_attr_inst = o_new_ent_attr_inst.value();
				new_ent_instance->add_entity_attribute_instance(ent_type_attributes[i], new_ent_attr_inst);
			}
			// Use the entity system's EntityAttributeInstanceManager method!
			// TODO: FIX: Create instances!
			//ENT_ATTR_INST new_ent_attr_instance = ?->create_entity_attribute_instance(ent_type_attributes[i]);
			// create_entity_attribute_instance

			// Call template base class method.
			// FIX!
			//new_ent_instance->add_entity_attribute_instance(ent_type_attributes[i], new_ent_attr_instance);
			}
		}

		// Call template base class method.
		add_instance(new_ent_instance->get_GUID(), new_ent_instance);

		// Signal that the entity type has been created.
		notify_entity_instance_created(new_ent_instance);

		return EntityInstancePtrOpt { new_ent_instance };
	}


	bool EntityInstanceManager::does_entity_instance_exist(const xg::Guid instance_GUID)
	{
		return does_instance_exist(instance_GUID);
	}

	EntityInstancePtrOpt EntityInstanceManager::get_entity_instance(const xg::Guid& instance_GUID)
	{
		return get_instance(instance_GUID);
	}

	std::size_t EntityInstanceManager::get_entity_instance_count() const
	{
		// Call template base class method.
		return get_instance_count();
	}

	std::size_t EntityInstanceManager::delete_entity_instance(const xg::Guid& instance_GUID)
	{
		EntityInstancePtrOpt o_ent_inst = get_entity_instance(instance_GUID);
		if (o_ent_inst.has_value())
		{
			EntityInstancePtr ent_inst = o_ent_inst.value();
			xg::Guid type_GUID = ent_inst->get_entity_type()->get_GUID();
			std::size_t deleted_instances_count = delete_instance(instance_GUID);
			notify_entity_instance_deleted(type_GUID, instance_GUID);
			return deleted_instances_count;
		}
		else
		{
			return 0;
		}
	}

	std::size_t EntityInstanceManager::delete_entity_instance(const EntityInstancePtr& entity_instance)
	{
		xg::Guid instance_GUID = entity_instance->get_GUID();
		xg::Guid type_GUID = entity_instance->get_entity_type()->get_GUID();
		std::size_t deleted_instances_count = delete_instance(instance_GUID);
		notify_entity_instance_deleted(type_GUID, instance_GUID);
		return deleted_instances_count;
	}

	void EntityInstanceManager::delete_all_entity_instances()
	{
		// Call template base class method.
		delete_all_instances();
	}

	// TODO: Implement!
	/*
	const std::size_t EntityInstanceManager::get_entity_instances_count_of_type(const EntityTypePtr&)
	{
	// Call template base class method.
	}

	const std::vector<ENT_INST> EntityInstanceManager::get_all_entity_instances() const
	{
	// Call template base class method.
	}

	const std::vector<ENT_INST> EntityInstanceManager::get_all_entity_instances_of_type(const EntityTypePtr&)
	{
	// Call template base class method.
	}
	*/

	void EntityInstanceManager::register_on_created(const xg::Guid& type_GUID, std::shared_ptr<EntityInstanceCreatedListener> listener)
	{
		if (signals_entity_instance_created.end() == signals_entity_instance_created.find(type_GUID))
		{
			auto signal = std::make_shared<boost::signals2::signal<void(EntityInstancePtr)>>();
			signals_entity_instance_created.insert(std::make_pair(type_GUID, signal));
		}
		signals_entity_instance_created[type_GUID]->connect(std::bind(&EntityInstanceCreatedListener::on_entity_instance_created, listener.get(), std::placeholders::_1));
	}

	void EntityInstanceManager::register_on_deleted(const xg::Guid& type_GUID, std::shared_ptr<EntityInstanceDeletedListener> listener)
	{
		if (signals_entity_instance_deleted.end() == signals_entity_instance_deleted.find(type_GUID))
		{
			auto signal = std::make_shared<boost::signals2::signal<void(const xg::Guid&, const xg::Guid&)>>();
			signals_entity_instance_deleted.insert(std::make_pair(type_GUID, signal));
		}
		signals_entity_instance_deleted[type_GUID]->connect(std::bind(&EntityInstanceDeletedListener::on_entity_instance_deleted, listener.get(), std::placeholders::_1, std::placeholders::_2));
	}

	void EntityInstanceManager::notify_entity_instance_created(EntityInstancePtr new_entity_instance)
	{
		xg::Guid type_GUID = new_entity_instance->get_entity_type()->get_GUID();
		if (!(signals_entity_instance_created.end() == signals_entity_instance_created.find(type_GUID)))
		{
			signals_entity_instance_created[type_GUID]->operator ()(new_entity_instance);
		}
	}

	void EntityInstanceManager::notify_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		if (!(signals_entity_instance_deleted.end() == signals_entity_instance_deleted.find(type_GUID)))
		{
			signals_entity_instance_deleted[type_GUID]->operator ()(type_GUID, inst_GUID);
		}
	}

}
}
