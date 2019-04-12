#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"

namespace inexor {
namespace entity_system {

	class EntityInstanceBuilder;

	/// These using instructions help to shorten the following code.
	using EntityInstanceBuilderPtr = std::shared_ptr<EntityInstanceBuilder>;
	using EntityInstanceManagerPtr = std::shared_ptr<EntityInstanceManager>;
	using EntityTypeManagerPtr = std::shared_ptr<EntityTypeManager>;
	using EntityTypePtr = std::shared_ptr<EntityType>;
	using EntityTypePtrOpt = std::optional<EntityTypePtr>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	/// @class EntityInstanceBuilder
	/// @brief A class for entity instances.
	/// @note This template base class is part of a software design pattern called the <b>builder pattern</b>.<br>
	/// https://en.wikipedia.org/wiki/Builder_pattern
	/// @todo Add mutex to ensure thread-safety during write operations!
	class EntityInstanceBuilder
		: public std::enable_shared_from_this<EntityInstanceBuilder>
	{
		public:

			/// @brief Constructs the entity instance builder.
			/// @note The dependencies of this class will be injected automatically.<br>
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// https://boost-experimental.github.io/di/user_guide/index.html
			/// @param entity_instance_manager The entity instance manager.
			/// @param entity_type_manager The entity type manager.
			EntityInstanceBuilder(
				EntityInstanceManagerPtr entity_instance_manager,
				EntityTypeManagerPtr entity_type_manager
			);

			/// Destructs the entity instance builder.
			~EntityInstanceBuilder();

			/// @brief Sets the name of the entity type to use.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_type_name".
			EntityInstanceBuilderPtr type(const std::string& entity_type_name);

			/// @brief Sets the entity type to use.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_type".
			EntityInstanceBuilderPtr type(const EntityTypePtr& entity_type);

			/// @brief Sets the uuid of the entity instance.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_uuid".
			EntityInstanceBuilderPtr uuid(const std::string& entity_type_uuid);

			/// @brief Sets the value of the attribute.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			/// @param attribute_name The name of the attribute.
			/// @param value The data of the attribute.
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const DataContainerInitializer& value);

			/// @brief Sets the value of the attribute.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			/// @param attribute_name The name of the attribute.
			/// @param value The bool data of the attribute.
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const bool& value);

			/// @brief Sets the value of the attribute.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			/// @param attribute_name The name of the attribute.
			/// @param value The int data of the attribute.
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const int& value);

			/// @brief 
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			/// @param attribute_name The name of the attribute.
			/// @param value The int64_t data of the attribute.
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const int64_t& value);

			/// @brief 
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			/// @param attribute_name The name of the attribute.
			/// @param value The float data of the attribute.
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const float& value);

			/// @brief 
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			/// @param attribute_name The name of the attribute.
			/// @param value The double data of the attribute.
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const double& value);

			/// @brief 
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			/// @param attribute_name The name of the attribute.
			/// @param value The std::string data of the attribute.
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const std::string& value);

			/// Builds and returns the created entity instance.
			EntityInstancePtrOpt build();

		private:

			/// The entity instance manager.
			EntityInstanceManagerPtr entity_instance_manager;

			/// The entity type manager.
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
