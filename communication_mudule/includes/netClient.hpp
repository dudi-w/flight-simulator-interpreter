#ifndef NET_CLIENT
#define NET_CLIENT

#include <string>
#include <memory>

#include "TCPclient.hpp"
#include "TCPsocketFile.hpp"

namespace net{//Network

class TelnetetClient
{
public:
    TelnetetClient();
    TelnetetClient(TelnetetClient const& other) = default;
    TelnetetClient& operator=(TelnetetClient const& other) = default;
    ~TelnetetClient() = default;

    void initialize(std::string const& serverAddress, uint16_t port);
    std::string receive() const;
    void send(std::string const& message);
    
public:
    std::unique_ptr<net::TCPclient> m_client;
    std::unique_ptr<net::TCPsocketFile> m_fileDescription;
};

}//namespace net

#endif
