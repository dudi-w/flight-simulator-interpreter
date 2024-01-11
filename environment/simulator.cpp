#include <stdlib.h>
#include "nlohmann/json.hpp"

#include "simulator.hpp"
#include "environment.hpp"

fp::env::SimulatorControl::SimulatorControl()
: m_serverPort{0}
, m_updatePerSecond{0}
, m_simulator_host{""}
, m_simulator_port{0}
, m_toUpdataMap{false}
{}

fp::env::SimulatorControl::~SimulatorControl()
{
    stopUpdateMap();
    if(m_updater.joinable()){
        m_updater.join();
    }
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
    std::string systemCommand = "fgfs --generic=socket,out," + std::to_string(m_updatePerSecond) + ",127.0.0.1," + std::to_string(m_serverPort) + ",tcp,generic_json_format --telnet=socket,in,10," + m_simulator_host + ',' + std::to_string(m_simulator_port) + ",tcp --httpd=8080";
    if(FILE* pipe = popen(systemCommand.c_str(), "r"); !pipe){
        throw; //TODO my exception;
    }
    std::this_thread::sleep_for(std::chrono::seconds(30));
    m_client.initialize(m_simulator_host, m_simulator_port);
    m_toUpdataMap = true;
    m_updater = std::thread([this](){updateMap();});
}

void fp::env::SimulatorControl::setValue(std::string variablePath, float value)
{
    m_client.send("set " + variablePath + " " + std::to_string(value));
}

void fp::env::SimulatorControl::stopUpdateMap()
{
    m_toUpdataMap = false;
}

void fp::env::SimulatorControl::updateMap()
{
    while(m_toUpdataMap){//TODO stop conditions
        std::string message = m_server.receive();
        std::stringstream strs(message);
        nlohmann::json j;
        strs >> j;

        auto it = j.begin();
        while(it != j.end()){
            if(it->is_number_float()){
                try
                {
                    fp::env::Environment::getDataMap().set(it.key(), static_cast<float>(it.value()));
                    // std::cout<<it.key()+'\t'+std::to_string(static_cast<float>(it.value()))<<std::endl;
                }
                catch(const std::exception& e)
                {
                    // std::cerr << e.what() << '\n';
                }
            }
            ++it;
        }
    }
}
