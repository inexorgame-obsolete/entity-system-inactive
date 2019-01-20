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

#include "api/AttributeApi.hpp"
#include "api/EntityInstanceApi.hpp"
#include "api/EntitySystemApi.hpp"
#include "api/EntityTypeApi.hpp"
#include "api/RelationInstanceApi.hpp"
#include "api/RelationTypeApi.hpp"
#include "entity-system/EntitySystem.hpp"
#include "logging/LogManager.hpp"


#define LOGGER_ENTITY_REST "inexor.entity.rest"

using namespace inexor::entity_system::rest::api;
using namespace restbed;

namespace inexor {
namespace entity_system {

	/// @class RestServer
    /// @brief The Inexor Entity System REST server.
	class RestServer : public restbed::Service
	{
		public:

			/// Constructor.
			RestServer(
				std::shared_ptr<inexor::logging::LogManager> log_manager,

				// The REST APIs
				std::shared_ptr<EntityTypeApi> entity_type_api,
				std::shared_ptr<RelationTypeApi> relation_type_api,
				std::shared_ptr<EntityInstanceApi> entity_instance_api,
				std::shared_ptr<RelationInstanceApi> relation_instance_api,
				std::shared_ptr<AttributeApi> attribute_api

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

			/// The REST API for entity types
			std::shared_ptr<EntityTypeApi> entity_type_api;

			/// The REST API for relation types
			std::shared_ptr<RelationTypeApi> relation_type_api;

			/// The REST API for entity instances
			std::shared_ptr<EntityInstanceApi> entity_instance_api;

			/// The REST API for relation instance
			std::shared_ptr<RelationInstanceApi> relation_instance_api;

			/// The REST API for attributes
			std::shared_ptr<AttributeApi> attribute_api;

			/// The REST service
			std::shared_ptr<restbed::Service> service;

			/// The settings of the REST server
			std::shared_ptr<Settings> settings;
	};


};
};
