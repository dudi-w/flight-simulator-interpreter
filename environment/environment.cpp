#include "environment.hpp"

namespace fp { // namespace flight plan
namespace env { // namespace env

Environment::Environment()
: m_output_stream(std::cout.rdbuf())
{}

Environment& Environment::get_instance()
{
    static Environment instance{};
    return instance;
}

// void Environment::setServerPort(uint16_t serverPort)
// {
//     get_instance().m_simulator.set_server_port(serverPort);
// }

// void Environment::setServerUpdatePerSecond(uint16_t updatePerSecond)
// {
//     get_instance().m_simulator.set_server_update_per_second(updatePerSecond);
// }

// void Environment::setSimulatorHost(std::string const& host)
// {
//     get_instance().m_simulator.set_simulator_host(host);
// }

// void Environment::setSimulatorPort(uint16_t port)
// {
//     get_instance().m_simulator.set_simulator_port(port);
// }

// void Environment::setValueInSimulator(std::string variablePath ,float value)
// {
//     get_instance().m_simulator.setValue(variablePath ,value);
// }

env::SimulatorControl& Environment::simulatorControl()
{
    return get_instance().m_simulator;
}

env::DataMap& Environment::getDataMap()
{
    return get_instance().m_dataMap;
}

void Environment::insert_to_map(std::string const& variable_name, std::unique_ptr<fp::var::IVariable> variable)
{
    get_instance().m_variable_map.insert(variable_name, std::move(variable));
}

float Environment::get_variable_value(std::string const& variable_name)
{
    return get_instance().m_variable_map.get_variable_value(variable_name);
}

//Remember: this function is only used by the user
void Environment::set_variable_value(std::string const& variable_name, float new_value)
{
    get_instance().m_variable_map.set_variable_value(variable_name, new_value);
}

void Environment::set_output_stream(std::ostream& output_stream)
{
    get_instance().m_output_stream.rdbuf(output_stream.rdbuf());
}

void Environment::print_str(std::string const& message)
{
    get_instance().m_output_stream << message << std::endl;
}

void Environment::print_float(float number)//?
{
    get_instance().m_output_stream << number << std::endl;
}

} //namespace env
} //namespace fp
