// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Event.h"

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "visual-scripting/model/Connector.hpp"

using namespace inexor::entity_system;
using namespace std;
using namespace xg;

namespace inexor {
namespace visual_scripting {

	/// @class ConnectorManager
    /// @brief Management of the connectors.
	class ConnectorManager
	{
		public:

			/// Constructor.
			ConnectorManager(
				shared_ptr<EntityInstanceManager> entity_instance_manager,
				shared_ptr<RelationInstanceManager> relation_instance_manager
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
			optional<shared_ptr<Connector>> create_connector(const ENT_ATTR_INST& output_attr, const ENT_ATTR_INST& input_attr);

			/// @brief Creates a connector from an entity attribute instance to another.
			/// @param connector_GUID The GUID of the newly created connector.
			/// @param output_attr A const reference to the shared pointer of the entity
			///                    attribute instance which is the output attribute.
			/// @param input_attr  A const reference to the shared pointer of the entity
			///                    attribute instance which is the input attribute.
			optional<shared_ptr<Connector>> create_connector(const Guid& connector_GUID, const ENT_ATTR_INST& output_attr, const ENT_ATTR_INST& input_attr);

//			/// @brief Creates a connector from an entity attribute instance to a relation attribute instance.
//			/// @param output_attr A const reference to the shared pointer of the entity
//			///                    attribute instance which is the output attribute.
//			/// @param input_attr  A const reference to the shared pointer of the relation
//			///                    attribute instance which is the input attribute.
//			optional<shared_ptr<Connector>> create_connector(const ENT_ATTR_INST& output_attr, const REL_ATTR_INST& input_attr);
//
//			/// @brief Creates a connector from an entity attribute instance to a relation attribute instance.
//			/// @param connector_GUID The GUID of the newly created connector.
//			/// @param output_attr A const reference to the shared pointer of the entity
//			///                    attribute instance which is the output attribute.
//			/// @param input_attr  A const reference to the shared pointer of the relation
//			///                    attribute instance which is the input attribute.
//			optional<shared_ptr<Connector>> create_connector(const Guid& connector_GUID, const ENT_ATTR_INST& output_attr, const REL_ATTR_INST& input_attr);
//
//			/// @brief Creates a connector from a relation attribute instance to a entity attribute instance.
//			/// @param output_attr A const reference to the shared pointer of the relation
//			///                    attribute instance which is the output attribute.
//			/// @param input_attr  A const reference to the shared pointer of the entity
//			///                    attribute instance which is the input attribute.
//			optional<shared_ptr<Connector>> create_connector(const REL_ATTR_INST& output_attr, const ENT_ATTR_INST& input_attr);
//
//			/// @brief Creates a connector from a relation attribute instance to a entity attribute instance.
//			/// @param connector_GUID The GUID of the newly created connector.
//			/// @param output_attr A const reference to the shared pointer of the relation
//			///                    attribute instance which is the output attribute.
//			/// @param input_attr  A const reference to the shared pointer of the entity
//			///                    attribute instance which is the input attribute.
//			optional<shared_ptr<Connector>> create_connector(const Guid& connector_GUID, const REL_ATTR_INST& output_attr, const ENT_ATTR_INST& input_attr);
//
//			/// @brief Creates a connector from a relation attribute instance to another.
//			/// @param output_attr A const reference to the shared pointer of the relation
//			///                    attribute instance which is the output attribute.
//			/// @param input_attr  A const reference to the shared pointer of the relation
//			///                    attribute instance which is the input attribute.
//			optional<shared_ptr<Connector>> create_connector(const REL_ATTR_INST& output_attr, const REL_ATTR_INST& input_attr);
//
//			/// @brief Creates a connector from a relation attribute instance to another.
//			/// @param connector_GUID The GUID of the newly created connector.
//			/// @param output_attr A const reference to the shared pointer of the relation
//			///                    attribute instance which is the output attribute.
//			/// @param input_attr  A const reference to the shared pointer of the relation
//			///                    attribute instance which is the input attribute.
//			optional<shared_ptr<Connector>> create_connector(const Guid& connector_GUID, const REL_ATTR_INST& output_attr, const REL_ATTR_INST& input_attr);

			/// @brief Deletes the connector which is connected to the given input attribute.
			/// @param input_attr A const reference to the shared pointer of the entity
			///                    attribute instance which is the input attribute.
			void delete_connector_by_input(const ENT_ATTR_INST& input_attr);

			/// @brief Deletes the connector which is connected to the given input attribute.
			/// @param input_attr A const reference to the shared pointer of the relation
			///                    attribute instance which is the input attribute.
			void delete_connector_by_input(const REL_ATTR_INST& input_attr);

			/// @brief Deletes all connectors which are connected to the given output attribute.
			/// @param input_attr A const reference to the shared pointer of the entity
			///                    attribute instance which is the output attribute.
			void delete_connectors_by_output(const ENT_ATTR_INST& output_attr);

			/// @brief Deletes all connectors which are connected to the given output attribute.
			/// @param input_attr A const reference to the shared pointer of the relation
			///                    attribute instance which is the output attribute.
			void delete_connectors_by_output(const REL_ATTR_INST& output_attr);

			/// @brief Deletes the connector with the given GUID.
			/// @param connector_GUID The GUID of the connector.
			void delete_connector(const Guid& connector_GUID);

			/// @brief Deletes the given connector.
			/// @param connector A const reference to the shared pointer of the connector.
			void delete_connector(const shared_ptr<Connector>& connector);

			/// @brief Returns true, if a connector exists with the given GUID.
			/// @param connector_GUID The GUID to search for.
			bool connector_exists(const Guid& connector_GUID);

			/// @brief Returns true, if a connector already exists which occupies the given input attribute.
			/// @param connector_GUID The GUID of the input attribute.
			bool input_occupied(const Guid& input_attr_GUID);

		private:

			/// The entity instance manager
			shared_ptr<EntityInstanceManager> entity_instance_manager;

			/// The relation instance manager
			shared_ptr<RelationInstanceManager> relation_instance_manager;


			/// Stores the connectors to search by GUID of the connector.
			unordered_map<Guid, shared_ptr<Connector>> connectors;

			/// Stores the list of outgoing connectors to search by GUID of the output attribute instance.
			unordered_map<Guid, vector<shared_ptr<Connector>>> output_to_connectors;

			/// Stores the incoming connectors to search by GUID of the input attribute instance.
			/// Each input can only have one connection! This can be used to check if an input is already occupied.
			unordered_map<Guid, shared_ptr<Connector>> input_to_connector;

	};


};
};
