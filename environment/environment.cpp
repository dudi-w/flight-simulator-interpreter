#include "environment.hpp"

namespace fp { // namespace flight plan
namespace env { // namespace env

Environment& Environment::get_instance()
{
    static Environment instanc;
    return instance;
}

void Environment::initialization_client(std::string const& host, int port)
{
    get_instance().m_client.initialize(host, port);
}

void Environment::initialization_server(int port, int ups)
{
    get_instance().m_server.initialize(port);
}

void Environment::insert_to_map(std::string const& variable_name, std::shared_ptr<IVariable> variable)
{
    get_instance().m_variable_map.insert(variable_name, variable);
}

float Environment::get_variable_value(std::string const& variable_name) const
{
    get_instance().m_variable_map.get_variable_value(variable_name);
}

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

void Environment::print_float(float number)
{
    get_instance().m_output_stream << number << std::endl;
}

} //namespace env
} //namespace fp