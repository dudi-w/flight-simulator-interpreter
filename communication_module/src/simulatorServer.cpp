#include "includes/simulatorServer.hpp"
#include "communicationExceptions.hpp"

fp::env::SimulatorServer::SimulatorServer()
: m_server(nullptr)
, m_fileDescription(nullptr)
{}

void fp::env::SimulatorServer::initialize(uint16_t port)
{
    m_server = std::make_unique<net::TCPserver>(port);
    m_server->createSocket();
    m_server->bindSocket();
    m_server->listenForClient();
}

std::string fp::env::SimulatorServer::receive()
{
    if(m_fileDescription == nullptr){
        m_fileDescription = m_server->acceptToRecieve();
        if(m_fileDescription == nullptr){
            throw net::FileDiscreptorError("invalid fileDiscreptor number");
        }
    }
    return m_fileDescription->read();
}

void fp::env::SimulatorServer::send(std::string const& message) const
{
    if(m_fileDescription == nullptr){
        throw net::FileDiscreptorError("invalid filediscreptor number");
    }

    if(int fileDescriptorNum = m_fileDescription->fileDescriptorNum(); fileDescriptorNum < 3){
        throw net::FileDiscreptorError("invalid file discreptor number " + std::to_string(fileDescriptorNum));
    }

    m_fileDescription->write(message);
}
