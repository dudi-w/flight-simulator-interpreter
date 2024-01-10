#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <iostream>
#include <memory>

#include "../communication_module/includes/netClient.hpp"
#include "../communication_module/includes/simulatorServer.hpp"
#include "dataMap.hpp"
#include "simulator.hpp"
#include "../variable/variable_map.hpp"
#include "../variable/variable.hpp"

namespace fp { // namespace flight plan
namespace env { // namespace env

class Environment
{
public:
    ~Environment() = default;

/*simulator functions*/
    static env::SimulatorControl& simulatorControl();
    // static void setServerPort(uint16_t serverPort);
    // static void setServerUpdatePerSecond(uint16_t updatePerSecond);
    // static void setSimulatorHost(std::string const& host);
    // static void setSimulatorPort(uint16_t port);
    // static void setValueInSimulator(std::string variablePath ,float value);

/*dataMap functions*/
    static env::DataMap& getDataMap();
    static void set_output_stream(std::ostream& output_stream);

    static void insert_to_map(std::string const& variable_name, std::unique_ptr<fp::var::IVariable> variable);
    static void set_variable_value(std::string const& variable_name, float new_value);
    static float get_variable_value(std::string const& variable_name);

    static void print_str(std::string const& message);
    static void print_float(float number);

public:

private:
    Environment();
    Environment(Environment const& other) = delete;
    Environment& operator=(Environment const& other) = delete;

    static Environment& get_instance();

private:
    env::DataMap m_dataMap;
    fp::var::VariableMap m_variable_map;
    fp::env::SimulatorControl m_simulator;
    std::ostream m_output_stream;
};

} //namespace env
} //namespace fp

#endif
