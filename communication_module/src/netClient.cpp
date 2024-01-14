#include "netClient.hpp"
#include "../myExceptions.hpp"

net::TelnetetClient::TelnetetClient()
: m_client(nullptr)
, m_fileDescription(nullptr)
{}

void net::TelnetetClient::initialize(std::string const& serverAddress, uint16_t port)
{
    m_client = std::make_unique<net::TCPclient>(serverAddress, port);
}

std::string net::TelnetetClient::receive() const
{
    if(m_fileDescription == nullptr){
        throw net::FileDiscreptorError("returnResult invalid filediscreptor number");
    }
    
    if(int fileDescriptorNum = m_fileDescription->fileDescriptorNum(); fileDescriptorNum < 3){
        throw net::FileDiscreptorError("invalid file discreptor number " + std::to_string(fileDescriptorNum));
    }
    return m_fileDescription->read();
}

void net::TelnetetClient::send(std::string const& message)
{
    if(m_fileDescription == nullptr && (m_fileDescription = m_client->connectToServer()) == nullptr){
        throw net::FileDiscreptorError("returnResult invalid filediscreptor number");
    }
    
    if(int fileDescriptorNum = m_fileDescription->fileDescriptorNum(); fileDescriptorNum < 3){
        throw net::FileDiscreptorError("invalid file discreptor number " + std::to_string(fileDescriptorNum));
    }
    m_fileDescription->write(message + "\r\n");//telnet protocol
}