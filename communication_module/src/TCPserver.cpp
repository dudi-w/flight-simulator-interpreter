#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <memory>

#include "TCPserver.hpp"
#include "../communicationExceptions.hpp"

net::TCPserver::TCPserver(uint16_t port)
: m_port(port)
{}

net::TCPserver::~TCPserver()
{
    closeSocket();
}

void net::TCPserver::createSocket()
{
    if((m_server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        throw net::CreateSocketError("failed to create socket");
    }
}

void net::TCPserver::bindSocket()
{
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = INADDR_ANY;
    m_address.sin_port = htons(m_port);
    if(bind(m_server_fd, (struct sockaddr*)&m_address, sizeof(m_address))< 0){
        throw net::BindingSocketError("Bind failure");
    }
}

void net::TCPserver::listenForClient() const
{
    if(listen(m_server_fd, SOMAXCONN) < 0){
        throw net::ListenError("Listen failure");
    }
}

std::unique_ptr<net::TCPsocketFile> net::TCPserver::acceptToRecieve() const
{
    int clientFileDesciptor;
    struct sockaddr_in clientAddress;
    int addrlen = sizeof(m_address);
    if((clientFileDesciptor = accept(m_server_fd, (struct sockaddr*)&clientAddress, (socklen_t*)&addrlen)) < 0){
        throw net::AcceptError("Accept failure");
    }
    logConnect(clientAddress);
    return std::make_unique<net::TCPsocketFile>(clientFileDesciptor);
}

void net::TCPserver::closeSocket() const
{
    close(m_server_fd);
}

void net::TCPserver::logConnect(struct sockaddr_in& clientAddress) const
{
    std::string ipAddress;
    ipAddress.resize(INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(clientAddress.sin_addr), ipAddress.data(), INET_ADDRSTRLEN);
    std::clog << "connect to client\n\tClient IP address is: " << ipAddress << "\n\tClient port num is:"<<clientAddress.sin_port<<std::endl;
}
