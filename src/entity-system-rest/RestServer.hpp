// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <iostream>
#include <thread>
#include <memory>
#include <chrono>
#include <cstdlib>

#include <restbed>

#include "../entity-system/EntitySystem.hpp"
//#include <corvusoft/restbed/session.hpp>
//#include <corvusoft/restbed/resource.hpp>
//#include <corvusoft/restbed/service.hpp>

#include "api/EntitySystemApi.h"
#include "api/EntityTypeApi.h"
#include "api/RelationshipTypeApi.h"
#include "api/EntityInstanceApi.h"
#include "api/RelationshipInstanceApi.h"
#include "api/AttributeApi.h"

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
			RestServer(std::shared_ptr<inexor::entity_system::EntitySystem> entity_system);

			/// Destructor.
			~RestServer();

			std::shared_ptr<Service> get_service();
			void set_service(std::shared_ptr<restbed::Service> service);

			void create_resources();

			std::shared_ptr<inexor::entity_system::EntitySystem> get_entity_system();

			void startService(int const& port);
			void stopService();

		private:
			std::shared_ptr<inexor::entity_system::EntitySystem> entity_system;
			std::shared_ptr<restbed::Service> service;

	};


};
};
