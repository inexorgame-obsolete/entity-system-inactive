#include <entity-system/builders/relations/relation-instance-builder/RelationInstanceBuilder.hpp>

#include <utility>

#if !defined(_MSC_VER)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow"
#endif

namespace inexor::entity_system {

	RelationInstanceBuilder::RelationInstanceBuilder(
		RelationInstanceManagerPtr relation_instance_manager,
		RelationTypeManagerPtr relation_type_manager
	)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);
		
		this->relation_instance_manager = std::move(relation_instance_manager);
		this->relation_type_manager = std::move(relation_type_manager);
		this->relation_type_name = "";
		this->o_relation_type = std::nullopt;
	}

	RelationInstanceBuilder::~RelationInstanceBuilder()
	= default;

	RelationInstanceBuilderPtr RelationInstanceBuilder::type(const std::string& relation_type_name)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		this->relation_type_name = relation_type_name;
		return shared_from_this();
	}

	RelationInstanceBuilderPtr RelationInstanceBuilder::type(const RelationTypePtr& relation_type)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		this->o_relation_type = { relation_type };
		return shared_from_this();
	}

	RelationInstanceBuilderPtr RelationInstanceBuilder::uuid(const std::string& relation_instance_uuid)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		this->relation_instance_uuid = relation_instance_uuid;
		return shared_from_this();
	}

	RelationInstanceBuilderPtr RelationInstanceBuilder::source(EntityInstancePtr ent_instance_source)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		this->ent_instance_source = std::move(ent_instance_source);
		return shared_from_this();
	}

	RelationInstanceBuilderPtr RelationInstanceBuilder::target(EntityInstancePtr ent_instance_target)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		this->ent_instance_target = std::move(ent_instance_target);
		return shared_from_this();
	}

	RelationInstanceBuilderPtr RelationInstanceBuilder::attribute(const std::string& attribute_name, const DataContainerInitializer& initializer)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		relation_instance_attributes[attribute_name] = {initializer.type, initializer.value };
		return shared_from_this();
	}

	RelationInstanceBuilderPtr RelationInstanceBuilder::attribute(const std::string& attribute_name, const bool& value)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		relation_instance_attributes[attribute_name] = {DataType::BOOL, value};
		return shared_from_this();
	}

	RelationInstanceBuilderPtr RelationInstanceBuilder::attribute(const std::string& attribute_name, const int& value)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		relation_instance_attributes[attribute_name] = {DataType::INT, value};
		return shared_from_this();
	}

	RelationInstanceBuilderPtr RelationInstanceBuilder::attribute(const std::string& attribute_name, const int64_t& value)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		relation_instance_attributes[attribute_name] = {DataType::BIG_INT, value};
		return shared_from_this();
	}

	RelationInstanceBuilderPtr RelationInstanceBuilder::attribute(const std::string& attribute_name, const float& value)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		relation_instance_attributes[attribute_name] = {DataType::FLOAT, value};
		return shared_from_this();
	}

	RelationInstanceBuilderPtr RelationInstanceBuilder::attribute(const std::string& attribute_name, const double& value)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		relation_instance_attributes[attribute_name] = {DataType::DOUBLE, value};
		return shared_from_this();
	}

	RelationInstanceBuilderPtr RelationInstanceBuilder::attribute(const std::string& attribute_name, const std::string& value)
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		relation_instance_attributes[attribute_name] = {DataType::STRING, value};
		return shared_from_this();
	}

	RelationInstancePtrOpt RelationInstanceBuilder::build()
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(relation_instance_builder_mutex);

		RelationInstancePtrOpt o_relation_instance = std::nullopt;
		if(!o_relation_type.has_value() && !relation_type_name.empty())
		{
			o_relation_type = relation_type_manager->get_relation_type(relation_type_name);
		}
		if(o_relation_type.has_value())
		{
			if(!relation_instance_uuid.empty())
			{
				o_relation_instance = relation_instance_manager->create_relation_instance(xg::Guid(relation_instance_uuid), o_relation_type.value(), ent_instance_source, ent_instance_target);
			}
			else
			{
				o_relation_instance = relation_instance_manager->create_relation_instance(o_relation_type.value(), ent_instance_source, ent_instance_target);
			}
		}
		if (o_relation_instance.has_value())
		{
			RelationInstancePtr relation_instance = o_relation_instance.value();
			// TODO: set attribute values
			for(auto& attr_entry : relation_instance_attributes)
			{
				std::string attr_name = attr_entry.first;
				DataContainerInitializer attr_value = attr_entry.second;
			//				O_REL_ATTR_INST o_attr_inst = relation_instance->get_attribute_instance(attr_entry.first);
			//				if (o_attr_inst.has_value()) {
			//					REL_ATTR_INST attr_inst = o_attr_inst.value();
			//					if (attr_inst->type == attr_value.type) {
			//						attr_inst->value.Set(attr_value.value.Value());
			//						switch (attr_inst->type)
			//						{
			//							case DataType::INT:
			//								spdlog::debug("Set attribute {} = {}", attr_name, std::get<DataType::INT>(attr_inst->value.Value()));
			//								break;
			//							case DataType::STRING:
			//								spdlog::debug("Set attribute {} = {}", attr_name, std::get<DataType::STRING>(attr_inst->value.Value()));
			//								break;
			//							default:
			//								break;
			//						}
			//					} else {
			//						// Error: Wrong datatype
			//						spdlog::error("Wrong datatype for attribute {}: {} != {}", attr_name, attr_inst->type, attr_value.type);
			//						return std::nullopt;
			//					}
			//				} else {
			//					// Error: Attribute not found by name
			//					spdlog::error("Relation instance attribute {} not found", attr_name);
			//					return std::nullopt;
			//				}
			}
			return o_relation_instance;
		}
		else
		{
			spdlog::error("Failed to create relation instance");
			return std::nullopt;
		}
	}

}

#if !defined(_MSC_VER)
#pragma clang diagnostic pop
#endif
