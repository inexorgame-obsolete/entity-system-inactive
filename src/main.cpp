// Inexor entity system prototype
// (c)2018 Inexor

#ifdef __linux__
#include <vector>
#include <signal.h>
#include <unistd.h>
#endif

#include "EntitySystem.hpp"
#include "rest/RestServer.hpp"

using namespace inexor::entity_system;

std::shared_ptr<RestServer> rest_server;

#ifdef __linux__
static void sigHandler(int sig){
    switch(sig){
        case SIGINT:
        case SIGQUIT:
        case SIGTERM:
        case SIGHUP:
        default:
        	rest_server->stop();
            break;
    }
    exit(0);
}

static void setUpUnixSignals(std::vector<int> quitSignals) {
    sigset_t blocking_mask;
    sigemptyset(&blocking_mask);
    for (auto sig : quitSignals)
        sigaddset(&blocking_mask, sig);

    struct sigaction sa;
    sa.sa_handler = sigHandler;
    sa.sa_mask    = blocking_mask;
    sa.sa_flags   = 0;

    for (auto sig : quitSignals)
        sigaction(sig, &sa, nullptr);
}
#endif

int main(int argc, char* argv[])
{

	// Setup signal handling
#ifdef __linux__
    std::vector<int> sigs{SIGQUIT, SIGINT, SIGTERM, SIGHUP};
    setUpUnixSignals(sigs);
#endif

    // Setup REST server
    rest_server = std::make_shared<RestServer>();
	rest_server->start();
    return 0;

}
