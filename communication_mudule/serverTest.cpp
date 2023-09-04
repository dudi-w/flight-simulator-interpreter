#include <iostream>

#include "includes/netServer.hpp"

int main(){

    net::SimulatoServer server;
    server.initialize(5400);
    while (true)
    {
        std::cout<<"\033[1;33m"<<server.receive()<<std::endl;
    }

    return EXIT_SUCCESS;
}
