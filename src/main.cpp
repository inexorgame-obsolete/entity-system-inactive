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
	application.init();
	std::thread start_thread(&inexor::InexorApplication::start, &application);
	std::thread run_thread(&inexor::InexorApplication::run, &application);
	start_thread.join();
	run_thread.join();
    return EXIT_SUCCESS;
}
