// Inexor entity system prototype
// (c)2018 Inexor

#include <iostream>
#include <memory>
#include <grpcpp/grpcpp.h>

#include "EntitySystem.hpp"
#include "generated/entity-system.grpc.pb.h"

using namespace inexor::entity_system;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

int main(int argc, char* argv[])
{
    std::cin.get();
    return 0;
}
