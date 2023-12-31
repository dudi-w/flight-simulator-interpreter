#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <iostream>
#include <memory>

#include "../communication_mudule/includes/netClient.hpp"
#include "../communication_mudule/includes/simulatorServer.hpp"
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

    // static void initialization_server(int port, int ups);   
    // static void initialization_simulator_cliant(std::string const& host, int port);

    static void insert_to_map(std::string const& variable_name, std::unique_ptr<fp::var::IVariable> variable);
    static void set_variable_value(std::string const& variable_name, float new_value);
    static float get_variable_value(std::string const& variable_name);

    static void set_output_stream(std::ostream& output_stream);
    static void print_str(std::string const& message);
    static void print_float(float number);


    static env::DataMap m_dataMap;
    static fp::env::SimulatorControl m_simulator;
private:
    Environment();
    Environment(Environment const& other) = delete;
    Environment& operator=(Environment const& other) = delete;

    static Environment& get_instance();


private:
    fp::var::VariableMap m_variable_map;
    std::ostream m_output_stream;
};

} //namespace env
} //namespace fp

#endif
