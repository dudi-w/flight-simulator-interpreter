#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <iostream>
#include <memory>

#include "communication_mudule/netClient.hpp"
#include "communication_mudule/netServer.hpp"
#include "variable/variable_map.hpp"
#include "variable/variable.hpp"

namespace fp { // namespace flight plan
namespace env { // namespace env

class Environment
{
public:
    Environment(Environment const& other) = delete;
    Environment& operator=(Environment const& other) = delete;
    ~Environment() = default;

    Environment& get_instance(std::ostream& output_stream)//???

    void initialization_client(int host, int port);
    void initialization_server(int port, int ups);   
    
    void insert_to_map(std::string const& variable_name, std::shared_ptr<IVariable> variable);
    float get_variable_value(std::string const& variable_name) const;
    void set_variable_value(std::string const& variable_name, float new_value);
    
    void set_output_stream(std::ostream& output_stream);
    void print_str(std::string const& message);
    void print_float(float number);

private:
    Environment(std::ostream& output_stream);

private:
    net::TelnetetClient m_client;
    net::NetServer m_server;
    VariableMap m_variable_map;
    std::ostream& m_output_stream;
};

} //namespace env
} //namespace fp

#endif
