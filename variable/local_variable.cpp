#include "local_variable.hpp"

namespace fg { // namespace flight gear

LocalVariable::LocalVariable(std::string const& variable_name, float variable_value)
: m_variable_name(variable_name)
, m_variable_value(variable_value)
{}

float LocalVariable::get_value() const
{
    return m_variable_value;
}

void LocalVariable::set(float new_value)
{
    m_variable_value = new_value;
}

} //namespace
