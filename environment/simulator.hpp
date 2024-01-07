#ifndef SIMULATOR_CONTROL_HPP
#define SIMULATOR_CONTROL_HPP

#include <thread>
#include <string>

#include "../communication_mudule/includes/simulatorServer.hpp"
#include "../communication_mudule/includes/netClient.hpp"

namespace fp {
namespace env {

class SimulatorControl
{
public:
    SimulatorControl();
    SimulatorControl(SimulatorControl const& other) = default;
    SimulatorControl& operator=(SimulatorControl const& other) = default;
    ~SimulatorControl();

    void set_server_port(uint16_t serverPort);
    void set_server_update_per_second(uint16_t updatePerSecond);
    void set_simulator_host(std::string const& host);
    void set_simulator_port(uint16_t port);

    void setValue(std::string variablePath ,float value);

private:
    void tryRun();
    void run();
    void updateMap();

private:
    uint16_t m_serverPort;
    uint16_t m_updatePerSecond;
    std::string m_simulator_host;
    uint16_t m_simulator_port;

    std::thread m_updater;
    net::TelnetetClient m_client;
    fp::env::SimulatorServer m_server;
};

}//namespace env
}// namespace fp

#endif
