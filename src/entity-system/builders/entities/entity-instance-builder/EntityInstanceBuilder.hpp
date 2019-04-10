#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"

namespace inexor {
namespace entity_system {

	class EntityInstanceBuilder;
	using EntityInstanceBuilderPtr = std::shared_ptr<EntityInstanceBuilder>;
	using EntityInstanceManagerPtr = std::shared_ptr<EntityInstanceManager>;
	using EntityTypeManagerPtr = std::shared_ptr<EntityTypeManager>;
	using EntityTypePtr = std::shared_ptr<EntityType>;
	using EntityTypePtrOpt = std::optional<EntityTypePtr>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	/// @class EntityInstanceBuilder
	/// @brief Management of the loggers.
	class EntityInstanceBuilder
	: public std::enable_shared_from_this<EntityInstanceBuilder>
	{
		public:

			/// Constructor.
			EntityInstanceBuilder(
			EntityInstanceManagerPtr entity_instance_manager,
			EntityTypeManagerPtr entity_type_manager
			);

			/// Destructor.
			~EntityInstanceBuilder();

			/// Sets the name of the entity type to use.
			EntityInstanceBuilderPtr type(const std::string& entity_type_name);

			/// Sets the entity type to use.
			EntityInstanceBuilderPtr type(const EntityTypePtr& entity_type);

			/// Sets the uuid of the entity instance.
			EntityInstanceBuilderPtr uuid(const std::string& entity_type_uuid);

			/// Sets the value of the attribute.
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const DataContainerInitializer& value);

			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const bool& value);

			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const int& value);

			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const int64_t& value);

			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const float& value);

			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const double& value);

			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const std::string& value);

			/// Builds and returns the created entity instance.
			EntityInstancePtrOpt build();

		private:

			/// The entity instance manager
			EntityInstanceManagerPtr entity_instance_manager;

			/// The entity type manager
			EntityTypeManagerPtr entity_type_manager;

			/// The name of the entity type to use.
			std::string entity_type_name;

			/// The entity type to use.
			EntityTypePtrOpt o_entity_type;

			/// The UUID of the new entity instance.
			std::string entity_instance_uuid;

			/// The attribute definitions.
			std::unordered_map<std::string, DataContainerInitializer> entity_instance_attributes;

	};

}
}
