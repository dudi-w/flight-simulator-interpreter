#include "bind_variable.hpp"

namespace fp { // namespace flight plan
namespace var { // namespace var

RemoteVariable::RemoteVariable(std::string const& variable_name, std::string variable_path, float variable_value)
: m_variable_name(variable_name)
, m_variable_path(variable_path)
, m_variable_value(variable_value)
{}
    
float RemoteVariable::get_value() const
{
    return m_variable_value;
}

void RemoteVariable::set_value(float new_value)
{
    m_variable_value = new_value;
}

} //namespace var
} //namespace fp
