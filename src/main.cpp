#include <boost/di.hpp>
#include "spdlog/spdlog.h"
#include "InexorApplication.hpp"

int main(int argc, char* argv[])
{
	auto injector = boost::di::make_injector();
	auto application = injector.create<inexor::InexorApplication>();
	application.init(argc, argv);
	application.run();
    return EXIT_SUCCESS;
}
