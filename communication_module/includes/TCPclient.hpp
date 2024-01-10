#ifndef TCP_CLIENT_HPP
#define TCP_CLIENT_HPP

#include <sys/socket.h>
#include <arpa/inet.h>
#include <memory>

#include "TCPsocketFile.hpp"

namespace net{//Search Engine

class TCPclient
{
public:
    explicit TCPclient(std::string const& serverAddress, uint16_t port);
    TCPclient(TCPclient const& other) = default;
    TCPclient& operator=(TCPclient const& other) = default;
    ~TCPclient();

    std::unique_ptr<net::TCPsocketFile> connectToServer();

private:
    void createSocket();
    void closeSocket() const;

private:
    int m_client_fd;
    int m_serverPort;
    const std::string m_serverAddress;
};

}//namespace se

#endif
