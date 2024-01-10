#include <iostream>

#include "includes/netClient.hpp"

int main(){

    net::TelnetetClient client;
    client.initialize("127.0.0.1", 5400);
    int i{0};
    while(i<9){
        client.send(std::to_string(++i) + "{abc : efg}");
        std::cout<<"client.receive() = "<<client.receive()<<std::endl;
    }
    
    return EXIT_SUCCESS;
}
