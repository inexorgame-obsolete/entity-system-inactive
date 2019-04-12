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
	/// @brief A builder pattern class for entity instances.
	/// @note This template base class is part of a software design pattern called the <b>builder pattern</b>.<br>
	/// https://en.wikipedia.org/wiki/Builder_pattern
	/// @todo Add mutex to ensure thread safety!
	/// @todo Add example in the comments here so users understand the builder pattern!
	/// 
	/// code example here!
	/// 
	/// 
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

			/// @brief Sets the name of the entity type so that the entity
			/// instance builder knows which entity instance has to be built.
			/// @param entity_type_name The name of the entity type of which the
			/// entity instance builder has to build an entity instance.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_type_name".
			EntityInstanceBuilderPtr type(const std::string& entity_type_name);

			/// @brief Sets the pointer of the entity type so that the entity
			/// instance builder knows which entity instance has to be built.
			/// @param entity_type_name The pointer of the entity type of which the
			/// entity instance builder has to build an entity instance.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_type".
			EntityInstanceBuilderPtr type(const EntityTypePtr& entity_type);

			/// @brief Sets the UUID of the entity type so that the entity
			/// instance builder knows which entity instance has to be built.
			/// @param entity_type_name The UUID of the entity type of which the
			/// entity instance builder has to build an entity instance.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_uuid".
			EntityInstanceBuilderPtr uuid(const std::string& entity_type_uuid);

			/// @brief Sets the value of the entity instances's attribute
			/// which will be built by the entity instance builder.
			/// @param attribute_name The name of the entity instance's attribute.
			/// @param value The data of the entity instance's attribute.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const DataContainerInitializer& value);

			/// @brief Sets the bool value of the entity instance's attribute
			/// which will be built by the entity instance builder.
			/// @param attribute_name The name of the entity instance's attribute.
			/// @param value The data of the entity instance's attribute.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const bool& value);

			/// @brief Sets the int value of the entity instance's attribute
			/// which will be built by the entity instance builder.
			/// @param attribute_name The name of the entity instance's attribute.
			/// @param value The data of the entity instance's attribute.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const int& value);

			/// @brief Sets the int64 value of the entity instance's attribute
			/// which will be built by the entity instance builder.
			/// @param attribute_name The name of the entity instance's attribute.
			/// @param value The data of the entity instance's attribute.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const int64_t& value);

			/// @brief Sets the float value of the entity instance's attribute
			/// which will be built by the entity instance builder.
			/// @param attribute_name The name of the entity instance's attribute.
			/// @param value The data of the entity instance's attribute.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const float& value);

			/// @brief Sets the double value of the entity instance's attribute
			/// which will be built by the entity instance builder.
			/// @param attribute_name The name of the entity instance's attribute.
			/// @param value The data of the entity instance's attribute.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const double& value);

			/// @brief Sets the std::string value of the entity instance's attribute
			/// which will be built by the entity instance builder.
			/// @param attribute_name The name of the entity instance's attribute.
			/// @param value The data of the entity instance's attribute.
			/// @note Because this method will be used in a builder pattern
			/// it does not make sense to rename it so "set_attribute".
			EntityInstanceBuilderPtr attribute(const std::string& attribute_name, const std::string& value);

			/// Builds and returns the entity instance.
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
