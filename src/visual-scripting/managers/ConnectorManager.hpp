#pragma once

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/model/relation-attributes/relation-attribute-instances/RelationAttributeInstance.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "visual-scripting/model/Connector.hpp"
#include "logging/managers/LogManager.hpp"

#include <crossguid/guid.hpp>
#include <optional>

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Event.h"

namespace inexor {
namespace visual_scripting {

	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
	using RelationInstanceManagerPtr = std::shared_ptr<entity_system::RelationInstanceManager>;
	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
	using RelationAttributeInstancePtr = std::shared_ptr<entity_system::RelationAttributeInstance>;
	using ConnectorPtr = std::shared_ptr<Connector>;
	using ConnectorPtrOpt = std::optional<ConnectorPtr>;

	/// @class ConnectorManager
    /// @brief Management of the connectors.
	class ConnectorManager
	{
		public:

			/// Constructor.
			ConnectorManager(
				EntityInstanceManagerPtr entity_instance_manager,
				RelationInstanceManagerPtr relation_instance_manager,
				LogManagerPtr log_manager
			);

			/// Destructor.
			~ConnectorManager();

			/// Initialization of the ConnectionManager.
			void init();

			/// @brief Creates a connector from an entity attribute instance to another.
			/// @param output_attr A const reference to the shared pointer of the entity
			///                    attribute instance which is the output attribute.
			/// @param input_attr  A const reference to the shared pointer of the entity
			///                    attribute instance which is the input attribute.
			ConnectorPtrOpt create_connector(const EntityAttributeInstancePtr& output_attr, const EntityAttributeInstancePtr& input_attr);

			/// @brief Creates a connector from an entity attribute instance to another.
			/// @param connector_GUID The GUID of the newly created connector.
			/// @param output_attr A const reference to the shared pointer of the entity
			///                    attribute instance which is the output attribute.
			/// @param input_attr  A const reference to the shared pointer of the entity
			///                    attribute instance which is the input attribute.
			ConnectorPtrOpt create_connector(const xg::Guid& connector_GUID, const EntityAttributeInstancePtr& output_attr, const EntityAttributeInstancePtr& input_attr);

//			/// @brief Creates a connector from an entity attribute instance to a relation attribute instance.
//			/// @param output_attr A const reference to the shared pointer of the entity
//			///                    attribute instance which is the output attribute.
//			/// @param input_attr  A const reference to the shared pointer of the relation
//			///                    attribute instance which is the input attribute.
//			ConnectorPtrOpt create_connector(const EntityAttributeInstancePtr& output_attr, const RelationAttributeInstancePtr& input_attr);
//
//			/// @brief Creates a connector from an entity attribute instance to a relation attribute instance.
//			/// @param connector_GUID The GUID of the newly created connector.
//			/// @param output_attr A const reference to the shared pointer of the entity
//			///                    attribute instance which is the output attribute.
//			/// @param input_attr  A const reference to the shared pointer of the relation
//			///                    attribute instance which is the input attribute.
//			ConnectorPtrOpt create_connector(const xg::Guid& connector_GUID, const EntityAttributeInstancePtr& output_attr, const RelationAttributeInstancePtr& input_attr);
//
//			/// @brief Creates a connector from a relation attribute instance to a entity attribute instance.
//			/// @param output_attr A const reference to the shared pointer of the relation
//			///                    attribute instance which is the output attribute.
//			/// @param input_attr  A const reference to the shared pointer of the entity
//			///                    attribute instance which is the input attribute.
//			ConnectorPtrOpt create_connector(const RelationAttributeInstancePtr& output_attr, const EntityAttributeInstancePtr& input_attr);
//
//			/// @brief Creates a connector from a relation attribute instance to a entity attribute instance.
//			/// @param connector_GUID The GUID of the newly created connector.
//			/// @param output_attr A const reference to the shared pointer of the relation
//			///                    attribute instance which is the output attribute.
//			/// @param input_attr  A const reference to the shared pointer of the entity
//			///                    attribute instance which is the input attribute.
//			ConnectorPtrOpt create_connector(const xg::Guid& connector_GUID, const RelationAttributeInstancePtr& output_attr, const EntityAttributeInstancePtr& input_attr);
//
//			/// @brief Creates a connector from a relation attribute instance to another.
//			/// @param output_attr A const reference to the shared pointer of the relation
//			///                    attribute instance which is the output attribute.
//			/// @param input_attr  A const reference to the shared pointer of the relation
//			///                    attribute instance which is the input attribute.
//			ConnectorPtrOpt create_connector(const RelationAttributeInstancePtr& output_attr, const RelationAttributeInstancePtr& input_attr);
//
//			/// @brief Creates a connector from a relation attribute instance to another.
//			/// @param connector_GUID The GUID of the newly created connector.
//			/// @param output_attr A const reference to the shared pointer of the relation
//			///                    attribute instance which is the output attribute.
//			/// @param input_attr  A const reference to the shared pointer of the relation
//			///                    attribute instance which is the input attribute.
//			ConnectorPtrOpt create_connector(const xg::Guid& connector_GUID, const RelationAttributeInstancePtr& output_attr, const RelationAttributeInstancePtr& input_attr);

			/// @brief Deletes the connector which is connected to the given input attribute.
			/// @param input_attr A const reference to the shared pointer of the entity
			///                    attribute instance which is the input attribute.
			void delete_connector_by_input(const EntityAttributeInstancePtr& input_attr);

			/// @brief Deletes the connector which is connected to the given input attribute.
			/// @param input_attr A const reference to the shared pointer of the relation
			///                    attribute instance which is the input attribute.
			void delete_connector_by_input(const RelationAttributeInstancePtr& input_attr);

			/// @brief Deletes all connectors which are connected to the given output attribute.
			/// @param input_attr A const reference to the shared pointer of the entity
			///                    attribute instance which is the output attribute.
			void delete_connectors_by_output(const EntityAttributeInstancePtr& output_attr);

			/// @brief Deletes all connectors which are connected to the given output attribute.
			/// @param input_attr A const reference to the shared pointer of the relation
			///                    attribute instance which is the output attribute.
			void delete_connectors_by_output(const RelationAttributeInstancePtr& output_attr);

			/// @brief Deletes the connector with the given GUID.
			/// @param connector_GUID The GUID of the connector.
			void delete_connector(const xg::Guid& connector_GUID);

			/// @brief Deletes the given connector.
			/// @param connector A const reference to the shared pointer of the connector.
			void delete_connector(const ConnectorPtr& connector);

			/// @brief Deletes the given connector.
			/// @param o_connector A const reference to the optional to the shared pointer of the connector.
			void delete_connector(const ConnectorPtrOpt& o_connector);

			/// @brief Returns true, if a connector exists with the given GUID.
			/// @param connector_GUID The GUID to search for.
			bool connector_exists(const xg::Guid& connector_GUID);

			/// @brief Returns true, if a connector already exists which occupies the given input attribute.
			/// @param connector_GUID The GUID of the input attribute.
			bool input_occupied(const xg::Guid& input_attr_GUID);

			/// @brief Enables the debug of the given connector.
			/// @param o_connector A const reference to the optional to the shared pointer of the connector.
			void enable_debug(const ConnectorPtrOpt& o_connector);

			/// @brief Disables the debug of the given connector.
			/// @param o_connector A const reference to the optional to the shared pointer of the connector.
			void disable_debug(const ConnectorPtrOpt& o_connector);

		private:

			/// The entity instance manager.
			EntityInstanceManagerPtr entity_instance_manager;

			/// The relation instance manager.
			RelationInstanceManagerPtr relation_instance_manager;

			/// The log manager.
			LogManagerPtr log_manager;

			/// Stores the connectors to search by GUID of the connector.
			std::unordered_map<xg::Guid, ConnectorPtr> connectors;

			/// Stores the list of outgoing connectors to search by GUID of the output attribute instance.
			std::unordered_map<xg::Guid, std::vector<ConnectorPtr>> output_to_connectors;

			/// Stores the incoming connectors to search by GUID of the input attribute instance.
			/// Each input can only have one connection! This can be used to check if an input is already occupied.
			std::unordered_map<xg::Guid, ConnectorPtr> input_to_connector;

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.vs.connector.manager";

	};


}
}
