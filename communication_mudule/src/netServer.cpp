#include "netServer.hpp"
#include "../myExceptions.hpp"

net::NetServer::NetServer()
: m_server(nullptr)
, m_fileDescription(nullptr)
{}

void net::NetServer::initialize(uint16_t port)
{
    m_server = std::make_unique<net::TCPserver>(port);
    m_server->createSocket();
    m_server->bindSocket();
    m_server->listenForClient();
}

std::string net::NetServer::receive()
{
    if(m_fileDescription == nullptr){
        m_fileDescription = m_server->acceptToRecieve();
        if(m_fileDescription == nullptr){
            throw net::FileDiscreptorError("invalid fileDiscreptor number");
        }
    }

    return m_fileDescription->read();
}

void net::NetServer::send(std::string const& message) const
{
    if(m_fileDescription == nullptr){
        throw net::FileDiscreptorError("invalid filediscreptor number");
    }

    if(int fileDescriptorNum = m_fileDescription->fileDescriptorNum(); fileDescriptorNum < 3){
        throw net::FileDiscreptorError("invalid file discreptor number " + fileDescriptorNum);
    }

    m_fileDescription->write(message);
}
