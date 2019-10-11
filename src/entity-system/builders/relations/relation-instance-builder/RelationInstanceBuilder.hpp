#pragma once

#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace entity_system {

	/// These using instructions help to shorten the following code.
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

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically with the help of Boost DI.<br>
			/// For more information see https://boost-experimental.github.io/di/user_guide/index.html
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// @param relation_instance_manager A shared pointer to the relation instance manager.
			/// @param relation_type_manager A shared pointer to the relation type manager.
			RelationInstanceBuilder(
				RelationInstanceManagerPtr relation_instance_manager,
				RelationTypeManagerPtr relation_type_manager
			);

			/// @brief Destructor.
			~RelationInstanceBuilder();

			/// @brief Sets the name of the relation type to use.
			/// @param relation_type_name The name of the relation type.
			/// @return A std::optional shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr type(const std::string& relation_type_name);

			/// @brief Sets the relation type to use.
			/// @param relation_type The relation type of which an instance will be created.
			/// @return A std::optional shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr type(const RelationTypePtr& relation_type);

			/// @brief Sets the uuid of the relation instance.
			/// @param relation_type_uuid The GUID of the relation type of which an instance will be created.
			/// @return A std::optional shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr uuid(const std::string& relation_type_uuid);

			/// @brief Sets the source entity instance.
			/// @param ent_instance_source The source entity type of which an instance will be created.
			/// @return A std::optional shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr source(EntityInstancePtr ent_instance_source);

			/// @brief Sets the target entity instance.
			/// @param ent_instance_target The target entity type of which an instance will be created.
			/// @return A std::optional shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr target(EntityInstancePtr ent_instance_target);

			/// @brief Sets the value of the attribute.
			/// @param attribute_name The name of the attribute type.
			/// @param value The initialisation data type and data value of the attribute.
			/// @return A std::optional shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const DataContainerInitializer& value);

			/// @brief Sets the value of the attribute.
			/// @param attribute_name The name of the relation instance attribute.
			/// @param value The initialisation data type and data value of the attribute.
			/// @return A std::optional shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const bool& value);

			/// @brief Sets the value of the attribute.
			/// @param attribute_name The name of the relation instance attribute.
			/// @param value The initialisation data type and data value of the attribute.
			/// @return A std::optional shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const int& value);

			/// @brief Sets the value of the attribute.
			/// @param attribute_name The name of the relation instance attribute.
			/// @param value The initialisation data type and data value of the attribute.
			/// @return A std::optional shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const int64_t& value);

			/// @brief Sets the value of the attribute.
			/// @param attribute_name The name of the relation instance attribute.
			/// @param value The initialisation data type and data value of the attribute.
			/// @return A std::optional shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const float& value);

			/// @brief Sets the value of the attribute.
			/// @param attribute_name The name of the relation instance attribute.
			/// @param value The initialisation data type and data value of the attribute.
			/// @return A std::optional shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const double& value);

			/// @brief Sets the value of the attribute.
			/// @param attribute_name The name of the relation instance attribute.
			/// @param value The initialisation data type and data value of the attribute.
			/// @return A std::optional shared pointer to the relation instance builder.
			RelationInstanceBuilderPtr attribute(const std::string& attribute_name, const std::string& value);

			/// @brief Builds and returns the created relation instance.
			/// @return A std::optional shared pointer to the relation instance which has been created.
			RelationInstancePtrOpt build();

		private:

			/// The relation instance manager.
			RelationInstanceManagerPtr relation_instance_manager;

			/// The relation type manager.
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

			/// The mutex of this class.
			std::mutex relation_instance_builder_mutex;
			
	};

}
}
