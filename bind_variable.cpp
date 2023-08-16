#include "bind_variable.hpp"

namespace fg { // namespace flight gear

BindVariable::BindVariable(std::string const& variable_name, std::string variable_path, float variable_value)
: m_variable_name(variable_name)
, m_variable_path(variable_path)
, m_variable_value(variable_value)
{}
    
float BindVariable::get_value() const
{
    return m_variable_value;
}

void BindVariable::set(float new_value)
{
    m_variable_value = new_value;
}

} //namespace
