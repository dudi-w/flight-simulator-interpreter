#include <nlohmann/json.hpp>

#include "../includes/simulatorServer.hpp"
#include "../myExceptions.hpp"

fp::env::SimulatorServer::SimulatorServer()
: m_server(nullptr)
, m_fileDescription(nullptr)
{}

fp::env::SimulatorServer::~SimulatorServer()
{
    m_updater.join();
}

void fp::env::SimulatorServer::initialize(uint16_t port)
{
    m_server = std::make_unique<net::TCPserver>(port);
    m_server->createSocket();
    m_server->bindSocket();
    m_server->listenForClient();

    m_updater = std::thread([this](){updateMap();});
}

void fp::env::SimulatorServer::updateMap()
{
    while(true){
        std::string message = receive();
        std::stringstream strs(message);
        nlohmann::json j;
        strs >> j;

        auto it = j.begin();
        while(it != j.end()){
            if(it->is_number_float()){
                fp::env::Environment::set_variable_value(fp::env::Environment::mapVar_at(it.key()), it.value());
            }
            ++it;
        }
    }
    
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
        throw net::FileDiscreptorError("invalid file discreptor number " + fileDescriptorNum);
    }

    m_fileDescription->write(message);
}
