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
				std::shared_ptr<inexor::entity_system::EntitySystem> entity_system,
				std::shared_ptr<inexor::logging::LogManager> log_manager
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

			/// Getter for the entity system
			std::shared_ptr<inexor::entity_system::EntitySystem> get_entity_system();

			/// Getter for the REST server settings
			std::shared_ptr<Settings> get_settings();

		private:

			/// The inexor entity system
			std::shared_ptr<inexor::entity_system::EntitySystem> entity_system;

            /// Management of the loggers
			std::shared_ptr<inexor::logging::LogManager> log_manager;

			/// The REST service
			std::shared_ptr<restbed::Service> service;

			/// The settings of the REST server
			std::shared_ptr<Settings> settings;
	};


};
};
