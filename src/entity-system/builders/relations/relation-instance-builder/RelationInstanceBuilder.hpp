#pragma once

#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace entity_system {

	class RelationInstanceBuilder;
	using RelationInstanceBuilderPtr = std::shared_ptr<RelationInstanceBuilder>;
	using RelationInstanceManagerPtr = std::shared_ptr<RelationInstanceManager>;
	using RelationTypeManagerPtr = std::shared_ptr<RelationTypeManager>;

	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using RelationTypePtr = std::shared_ptr<RelationType>;
	using RelationTypePtrOpt = std::optional<RelationTypePtr>;
	using RelationInstancePtr = std::shared_ptr<RelationInstance>;
	using RelationInstancePtrOpt = std::optional<RelationInstancePtr>;

	/// @class RelationInstanceBuilder
	/// @brief Builder for relation instances.
	class RelationInstanceBuilder : public std::enable_shared_from_this<RelationInstanceBuilder>
	{
		public:

			/// Constructor.
			RelationInstanceBuilder(
				RelationInstanceManagerPtr relation_instance_manager,
				RelationTypeManagerPtr relation_type_manager
			);

			/// Destructor.
			~RelationInstanceBuilder();

			/// Sets the name of the relation type to use.
			RelationInstanceBuilderPtr type(const std::string& relation_type_name);

			/// Sets the relation type to use.
			RelationInstanceBuilderPtr type(const RelationTypePtr& relation_type);

			/// Sets the uuid of the relation instance.
			RelationInstanceBuilderPtr uuid(const std::string& relation_type_uuid);

			/// Sets the source entity instance.
			RelationInstanceBuilderPtr source(EntityInstancePtr ent_instance_source);

			/// Sets the target entity instance.
			RelationInstanceBuilderPtr target(EntityInstancePtr ent_instance_target);

			/// Sets the value of the attribute.
			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const DataContainerInitializer& value);

			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const bool& value);

			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const int& value);

			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const int64_t& value);

			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const float& value);

			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const double& value);

			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const std::string& value);

			/// Builds and returns the created relation instance.
			RelationInstancePtrOpt build();

		private:

			/// The relation instance manager
			RelationInstanceManagerPtr relation_instance_manager;

			/// The relation type manager
			RelationTypeManagerPtr relation_type_manager;

			/// The name of the relation type to use.
			std::string relation_type_name;

			/// The relation type to use.
			RelationTypePtrOpt o_relation_type;

			/// The UUID of the new relation instance.
			std::string relation_instance_uuid;

			/// The source entity instance.
			EntityInstancePtr ent_instance_source;

			/// The target entity instance.
			EntityInstancePtr ent_instance_target;

			/// The attribute definitions.
			std::unordered_map<std::string, DataContainerInitializer> relation_instance_attributes;

	};


}
}
