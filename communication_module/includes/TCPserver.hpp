#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP

#include <sys/socket.h>
#include <arpa/inet.h>
#include <memory>

#include "TCPsocketFile.hpp"

namespace net{//Network

class TCPserver
{
public:
    explicit TCPserver(uint16_t port);
    TCPserver(TCPserver const& other) = delete;
    TCPserver& operator=(TCPserver const& other) = delete;
    ~TCPserver();

public:
    void createSocket();
    void bindSocket();
    void listenForClient() const;
    std::unique_ptr<net::TCPsocketFile> acceptToRecieve() const;

private:
    void closeSocket() const;
    void logConnect(struct sockaddr_in& clientAddress) const;

private:
    struct sockaddr_in m_address;
    int m_server_fd;
    int m_port;
};

}//namespace net

#endif
