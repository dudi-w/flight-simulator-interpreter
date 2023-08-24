#ifndef TCP_QUERY_HPP
#define TCP_QUERY_HPP

#include "TCPserver.hpp"
#include "TCPsocketFile.hpp"

namespace net{//Network

class NetServer
{
public:
    NetServer();
    NetServer(NetServer const& other) = delete;
    NetServer& operator=(NetServer const& other) = delete;
    ~NetServer() = default;

    void initialize(uint16_t port);
    std::string receive();
    void send(std::string const& message) const;

private:
    std::unique_ptr<TCPserver> m_server;
    std::unique_ptr<net::TCPsocketFile> m_fileDescription;
};

}//namespace net

#endif