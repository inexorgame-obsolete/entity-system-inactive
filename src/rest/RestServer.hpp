// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#define PISTACHE_SERVER_THREADS 2

#include <iostream>
#include <memory>

#include <pistache/endpoint.h>

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

			void start();

			void stop();

		private:
			std::shared_ptr<Pistache::Http::Endpoint> httpEndpoint;

	};


};
};
