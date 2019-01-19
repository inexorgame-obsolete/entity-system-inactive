// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <iostream>
#include <thread>
#include <memory>
#include <chrono>
#include <cstdlib>

#include <restbed>

#include "spdlog/spdlog.h"

#include "entity-system/EntitySystem.hpp"
#include "logging/LogManager.hpp"

#include "api/EntitySystemApi.h"
#include "api/EntityTypeApi.h"
#include "api/RelationshipTypeApi.h"
#include "api/EntityInstanceApi.h"
#include "api/RelationshipInstanceApi.h"
#include "api/AttributeApi.h"

#define LOGGER_ENTITY_REST "inexor.entity.rest"

using namespace inexor::entity_system::rest::api;
using namespace restbed;

namespace inexor {
namespace entity_system {

	/// @class RestServer
    /// @brief The Inexor Entity System REST server.
	class RestServer : public restbed::Service,
	                   public EntityTypeApi
//					   public EntitySystemApi,
//					   public RelationshipTypeApi,
//					   public EntityInstanceApi,
//					   public RelationshipInstanceApi,
//					   public AttributeApi
	{
		public:

			/// Constructor.
			RestServer(
				std::shared_ptr<inexor::logging::LogManager> log_manager,

				std::shared_ptr<EntityTypeApiEntitiesTypesResource> spEntityTypeApiEntitiesTypesResource,
				std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidResource> spEntityTypeApiEntitiesTypesEntity_type_uuidResource,
				std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidAttributesNameResource> spEntityTypeApiEntitiesTypesEntity_type_uuidAttributesNameResource,
				std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidInstancesResource> spEntityTypeApiEntitiesTypesEntity_type_uuidInstancesResource,
				std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsIncomingResource> spEntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsIncomingResource,
				std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsOutgoingResource> spEntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsOutgoingResource,
				std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsResource> spEntityTypeApiEntitiesTypesEntity_type_uuidRelationshipsResource,
				std::shared_ptr<EntityTypeApiEntitiesTypesEntity_type_uuidAttributesResource> spEntityTypeApiEntitiesTypesEntity_type_uuidAttributesResource

			);

			/// Destructor.
			~RestServer();

			void init();

			void startService(int const& port);
			void stopService();

			/// Getter for the service
			std::shared_ptr<Service> get_service();

			/// Setter for the service
			void set_service(std::shared_ptr<restbed::Service> service);

			/// Getter for the REST server settings
			std::shared_ptr<Settings> get_settings();

		private:

            /// Management of the loggers
			std::shared_ptr<inexor::logging::LogManager> log_manager;

			/// The REST service
			std::shared_ptr<restbed::Service> service;

			/// The settings of the REST server
			std::shared_ptr<Settings> settings;
	};


};
};
