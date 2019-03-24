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
#include "logging/managers/LogManager.hpp"


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

            /// @brief Constructor.
            /// @note The dependencies of this class will be injected automatically.
            /// @param log_manager Management of the loggers.
            /// @param entity_type_api The REST API for entity types.
            /// @param relation_type_api The REST API for relation types.
            /// @param entity_instance_api The REST API for entity instances.
            /// @param relation_instance_api The REST API for relation instance.
            /// @param attribute_api The REST API for attributes.
			RestServer(
				std::shared_ptr<inexor::logging::LogManager> log_manager,
				std::shared_ptr<EntityTypeApi> entity_type_api,
				std::shared_ptr<RelationTypeApi> relation_type_api,
				std::shared_ptr<EntityInstanceApi> entity_instance_api,
				std::shared_ptr<RelationInstanceApi> relation_instance_api,
				std::shared_ptr<AttributeApi> attribute_api
			);

            /// Destructor.
			~RestServer();

            /// ?
			void init();

			/// Start the server on a specific port (in a dedicated thread).
            /// @note The standard port is 8080.
            /// @param port The port of the REST API server.
			void startService(uint16_t port = 8080);
			
            /// ?
            void stopService();

			/// Get method for the service.
			std::shared_ptr<Service> get_service();

			/// Set method for the service.
			void set_service(std::shared_ptr<restbed::Service> service);

			/// Get method for the REST server settings.
			std::shared_ptr<Settings> get_settings();

		private:

            /// Management of the loggers.
			std::shared_ptr<inexor::logging::LogManager> log_manager;

			/// The REST API for entity types.
			std::shared_ptr<EntityTypeApi> entity_type_api;

			/// The REST API for relation types.
			std::shared_ptr<RelationTypeApi> relation_type_api;

			/// The REST API for entity instances.
			std::shared_ptr<EntityInstanceApi> entity_instance_api;

			/// The REST API for relation instance.
			std::shared_ptr<RelationInstanceApi> relation_instance_api;

			/// The REST API for attributes.
			std::shared_ptr<AttributeApi> attribute_api;

			// TODO: Get rid of this tight coupling.
            /// ?
			std::shared_ptr<restbed::Service> service;

			/// The settings of the REST server.
			std::shared_ptr<Settings> settings;

			/// The dedicated thread running the service (because the restbed service is blocking).
			std::thread service_thread;
	};


};
};
