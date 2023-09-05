#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <iostream>
#include <memory>

#include "../communication_mudule/includes/netClient.hpp"
#include "../communication_mudule/includes/simulatorServer.hpp"
#include "dataMap.hpp"
// #include "../variable/variable_map.hpp"
// #include "../variable/variable.hpp"

namespace fp { // namespace flight plan
namespace env { // namespace env

class Environment
{
public:
    ~Environment() = default;

    static void initialization_client(std::string const& host, int port);
    static void initialization_server(int port, int ups);   

    static void insert_to_map(std::string const& variable_name, std::shared_ptr<IVariable> variable);
    static float get_variable_value(std::string const& variable_name);
    static void set_variable_value(std::string const& variable_name, float new_value);

    static void set_output_stream(std::ostream& output_stream);
    static void print_str(std::string const& message);
    static void print_float(float number);

private:
    Environment() = default;
    Environment(Environment const& other) = delete;
    Environment& operator=(Environment const& other) = delete;

    static Environment& get_instance();

private:
    net::TelnetetClient m_client;
    fp::env::SimulatorServer m_server;
    env::DataMap dataMap;
    VariableMap m_variable_map;
    std::ostream& m_output_stream;
};

} //namespace env
} //namespace fp

#endif
