// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <iostream>
#include <thread>
#include <memory>
#include <chrono>
#include <cstdlib>

#include <restbed>
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

namespace inexor {
namespace entity_system {

	/// @class RestServer
    /// @brief The Inexor Entity System REST server.
	class RestServer
	{
		public:

			/// Constructor.
			RestServer();

			/// Destructor.
			~RestServer();

			void start_services();

			void stop_services();

		private:
			std::shared_ptr<EntitySystemApi> entity_system_api;
			std::shared_ptr<EntityTypeApi> entity_type_api;
			std::shared_ptr<RelationshipTypeApi> relationship_type_api;
			std::shared_ptr<EntityInstanceApi> entity_instance_api;
			std::shared_ptr<RelationshipInstanceApi> relationship_instance_api;
			std::shared_ptr<AttributeApi> attribute_api;

	};


};
};
