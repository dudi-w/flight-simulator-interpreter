#ifndef TCP_QUERY_HPP
#define TCP_QUERY_HPP

#include <thread>

#include "TCPserver.hpp"
#include "TCPsocketFile.hpp"

namespace fp { // namespace flight plan
namespace env { // namespace env

class SimulatorServer
{
public:
    SimulatorServer();
    SimulatorServer(SimulatorServer const& other) = delete;
    SimulatorServer& operator=(SimulatorServer const& other) = delete;
    ~SimulatorServer() = default;

    void initialize(uint16_t port);
    std::string receive();
    void send(std::string const& message) const;

private:
    std::unique_ptr<net::TCPserver> m_server;
    std::unique_ptr<net::TCPsocketFile> m_fileDescription;
};

}//namespace env
}// namespace fp

#endif