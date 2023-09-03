#include "environment.hpp"

namespace fp { // namespace flight plan
namespace env { // namespace env

Environment::Environment(std::ostream& output_stream)
: m_output_stream(output_stream)
{}

Environment& Environment::get_instance(std::ostream& output_stream)
{
    static Environment instance(output_stream);
    return instance;
}

void Environment::initialization_client(int host, int port)
{
    
}

void Environment::initialization_server(int port, int ups)
{
    
}
    
void Environment::insert_to_map(std::string const& variable_name, std::shared_ptr<IVariable> variable)
{
    m_variable_map.insert(variable_name, variable);
}

float Environment::get_variable_value(std::string const& variable_name) const
{
    m_variable_map.get_variable_value(variable_name);
}

void Environment::set_variable_value(std::string const& variable_name, float new_value)
{
    m_variable_map.set_variable_value(variable_name, new_value);
}

void Environment::set_output_stream(std::ostream& output_stream)
{
    m_output_stream.rdbuf(output_stream.rdbuf());
}

void Environment::print_str(std::string const& message)
{
    m_output_stream << message << std::endl;
}

void Environment::print_float(float number)
{
    m_output_stream << number << std::endl;
}

} //namespace env
} //namespace fp