#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <sstream>

#include "TCPsocketFile.hpp"
#include "../myExceptions.hpp"

net::TCPsocketFile::TCPsocketFile(int fileDescriptor)
: m_fileDescriptor(fileDescriptor)
, m_buffSize(4096)
{}

net::TCPsocketFile::~TCPsocketFile()
{
    colseSocket();
}

std::string net::TCPsocketFile::read()
{
    std::string message;
    while(true){
        std::string buffer(m_buffSize, 0);
        ssize_t bytesReceived = recv(m_fileDescriptor, buffer.data(), m_buffSize ,0);
        if(bytesReceived < 0){
            throw net::ReadError("Cannot read from file descriptor number " + m_fileDescriptor);
        }
        message.append(buffer ,0 ,bytesReceived);
        if(bytesReceived < m_buffSize && bytesReceived){
            break;
        }
    }
    return message;
}

void net::TCPsocketFile::write(std::string const& text) const
{
    if(ssize_t bytesSent = send(m_fileDescriptor, text.c_str(), text.size(), 0); bytesSent < 0){
        throw net::WriteError("Cannot write to file descriptor number " + m_fileDescriptor);
    }
}

void net::TCPsocketFile::colseSocket() const
{
    close(m_fileDescriptor);
}

int net::TCPsocketFile::fileDescriptorNum() const noexcept
{
    return m_fileDescriptor;
}

