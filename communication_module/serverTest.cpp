#include <iostream>

#include "includes/simulatorServer.hpp"

int main(){

    fp::env::SimulatorServer server;
    server.initialize(5400);
    std::string message;
    
    while(message[0] != '9')
    {
        message = server.receive();
        std::cout<<"\033[1;33mserver.receive() = "<<message<<std::endl;
        std::cout<<"\033[1;33mserver.send() = \033[0m"<<std::endl;
        server.send("{jhk : lmn}");
    }

    return EXIT_SUCCESS;
}
