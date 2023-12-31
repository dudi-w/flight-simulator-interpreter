#ifndef SIMULATOR_CONTROL_HPP
#define SIMULATOR_CONTROL_HPP

#include <thread>
#include <string>

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

private:
    void updateMap();

private:
    uint16_t m_serverPort;
    uint16_t m_updatePerSecond;
    std::string m_simulator_host;
    uint16_t m_simulator_port;

    std::thread m_updater;

    // bool m_runCluent;
    // bool m_runServer;
    // bool m_runSimulator;

    // std::thread m_sys;
    net::TelnetetClient m_client;
    fp::env::SimulatorServer m_server;
};

}//namespace env
}// namespace fp

#endif

#include <stdlib.h>
#include <nlohmann/json.hpp>

fp::env::SimulatorControl::SimulatorControl()
: m_serverPort{0}
, m_updatePerSecond{0}
, m_simulator_host{""}
, m_simulator_port{0}
// , m_runServer{false}
// , m_runSimulator{false}
// , m_runCluent{false}
{}

fp::env::SimulatorControl::~SimulatorControl()
{
    m_updater.join();
}

void fp::env::SimulatorControl::set_server_port(uint16_t serverPort)
{
    m_serverPort = serverPort;
    tryRun();
}

void fp::env::SimulatorControl::set_server_update_per_second(uint16_t updatePerSecond)
{
    m_updatePerSecond = updatePerSecond;
    tryRun();
}

void fp::env::SimulatorControl::set_simulator_host(std::string const& host)
{
    m_simulator_host = host;
    tryRun();
}

void fp::env::SimulatorControl::set_simulator_port(uint16_t port)
{
    m_simulator_port = port;
    tryRun();
}

void fp::env::SimulatorControl::tryRun()
{
    if(m_serverPort && m_updatePerSecond && m_simulator_host != "" && m_simulator_port /*&& serverRun*/){
        run();
    }
}

void fp::env::SimulatorControl::run()
{
    m_server.initialize(m_serverPort);
    // std::unique_lock<std::mutex> lock(mtx);
    // cv.wait(lock, [] { return step1_done; });
    // fp::env::Environment::initialization_server(stoi(m_port), stoi(m_ups));
    std::string systemCommand("fgfs --generic=socket,out," + std::to_string(m_updatePerSecond) + ",127.0.0.1," + std::to_string(m_serverPort) + ",tcp,generic_json_format --telnet=socket,in,10," + m_simulator_host + ',' + std::to_string(m_simulator_port) + ",tcp --httpd=8080");
    if(FILE* pipe = popen(systemCommand.c_str(), "r"); !pipe){
        throw; //TODO my exption;
    }
    m_client.initialize(m_simulator_host, m_simulator_port);
}

void fp::env::SimulatorControl::setValue(std::string variablePath, float value)
{
    m_client.send("set " + variablePath + " " + std::to_string(value));
}

void fp::env::SimulatorControl::updateMap()
{
    while(true){
        std::string message = m_server.receive();
        std::stringstream strs(message);
        nlohmann::json j;
        strs >> j;

        auto it = j.begin();
        while(it != j.end()){
            if(it->is_number_float()){
                fp::env::Environment::m_dataMap.set(it.key(), it.value());
                // fp::env::Environment::set_variable_value(fp::env::Environment::mapVar_at(it.key()), it.value());
            }
            ++it;
        }
    }
}
