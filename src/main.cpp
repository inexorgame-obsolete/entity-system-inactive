// Inexor entity system
// (c)2018-2019 Inexor

#include <boost/di.hpp>
#include "spdlog/spdlog.h"
#include "InexorApplication.hpp"

int main(int argc, char* argv[])
{
	spdlog::info("Inexor (c) 2009-2019");
	auto injector = boost::di::make_injector();
	auto application = injector.create<inexor::InexorApplication>();
	spdlog::info("application.start()");
	application.start();
	spdlog::info("application.run()");
	application.run();
	spdlog::info("application.shutdown()");
	application.shutdown();
    return EXIT_SUCCESS;
}
