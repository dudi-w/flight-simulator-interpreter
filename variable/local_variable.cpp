#include "local_variable.hpp"

namespace fp { // namespace flight plan
namespace var { // namespace var

LocalVariable::LocalVariable(std::string const& variable_name, float variable_value)
: m_variable_name(variable_name)
, m_variable_value(variable_value)
{}

float LocalVariable::get_value() const
{
    return m_variable_value;
}

void LocalVariable::set_value(float new_value)
{
    m_variable_value = new_value;
}

} //namespace var
} //namespace fp
