#include <boost/di.hpp>
#include "InexorApplication.hpp"

int main(int argc, char* argv[])
{
	auto injector = boost::di::make_injector();
	auto application = injector.create<inexor::InexorApplication>();
	application.pre_init(argc, argv);
	application.init();
	application.run();
    return EXIT_SUCCESS;
}
